#include "LuaWorker.h"
#include "Exceptions.h"

#include <QThread>
#include <QVector>
#include <QString>
#include <QDebug>

//--- LUA includes --------------------------------------------------------------------------------
#include "lua.h"
#include "lstate.h"

#include "IFile.h"
#include "ILuaValue.h"
#include "Exceptions.h"
#include "Locker.h"

//-------------------------------------------------------------------------------------------------
LuaWorker::LuaWorker(IConsole *pConsole)
    :QObject(NULL)
    ,m_pConsole(pConsole)
    ,m_mtxTasks()
    ,m_luaState(NULL)
    ,m_pSysVar(NULL)
{
    // Hier keine dynamische allokation, da diese im Hauptthread geschehen würde!
    if (m_pConsole==NULL)
        throw InternalError(tr("Can't create Lua worker with null console pointer"));

    init();
}

//-------------------------------------------------------------------------------------------------
LuaWorker::~LuaWorker()
{
    if (m_luaState)
    {
      lua_close(m_luaState);
      m_luaState = NULL;
    }
}

//-------------------------------------------------------------------------------------------------
void LuaWorker::doSyntaxCheck(const IFile *pFile)
{
    if (pFile!=NULL)
        emit checkSyntax(pFile);
}

//-------------------------------------------------------------------------------------------------
void LuaWorker::stop()
{
    m_luaState->stop_now = 1;
}

//-------------------------------------------------------------------------------------------------
/** \brief Ausführen von Lua code aus einen String.

    Diese Funktion wird für die Konsolenanwendung benötigt.
*/
void LuaWorker::on_doString(const QString &sCmd)
{
    if (m_pConsole==NULL)
        return;

    qDebug("on_doString(\"%s\"); thread id: %d",
           sCmd.toStdString().c_str(),
           reinterpret_cast<int>(QThread::currentThreadId()));

    try
    {
        doString(sCmd, "command_line_chunk");
    }
    catch(Exception &exc)
    {
        emit error(exc.getMessage());
    }
    catch(std::exception &exc)
    {
        emit error(exc.what());
    }
    catch(...)
    {
        emit error("Internal error: FrmConsole::executeCommand");
    }

    //emit finished();
}


//-------------------------------------------------------------------------------------------------
void LuaWorker::on_doFile(IFile *pFile)
{
    if (m_pConsole==NULL || pFile==NULL)
        return;

    qDebug("on_doFile(%s); thread id: %d",
           pFile->getName().toStdString().c_str(),
           reinterpret_cast<int>(QThread::currentThreadId()));

    try
    {
        QVector<QString> vLines = pFile->getLines();
        QString sScript;
        for (int i=0; i<vLines.size(); ++i)
        {
            sScript += vLines[i];
        }

        if (m_luaState==NULL)
            throw LuaException(QString("Can't execute Lua code fragment \"%1\": Lua state is not initialized").arg(sScript));

        doString(sScript, pFile->getName());
        emit finished();
    }
    catch(LuaException &exc)
    {
        exc.setFile(pFile);

        QString sMsg = QString("%1 in Line %2").arg(exc.getMessage())
                                               .arg(exc.getLine());
        emit error(sMsg);
    }
    catch(Exception &exc)
    {
        emit error(exc.getMessage());
    }
    catch(std::exception &exc)
    {
        emit error(exc.what());
    }
    catch(...)
    {
        emit error("Internal error: FrmConsole::executeCommand");
    }
}

//-------------------------------------------------------------------------------------------------
void LuaWorker::on_doProject(const IProject *pProject)
{
}


//-------------------------------------------------------------------------------------------------
void LuaWorker::on_checkFile(const IFile *pFile)
{
    if (m_pConsole==NULL || pFile==NULL)
        return;

    try
    {
        Q_ASSERT(pFile!=NULL);
        Locker lock(pFile);

        if (m_luaState==NULL)
            throw LuaException(QString("Can't execute Lua code fragment \"%1\": Lua state is not initialized").arg(pFile->getName()));

    //    qDebug() << "syntaxCheck(" << pFile->getName() << ")";

        const QVector<QString> &vLines = pFile->getLines();
        QString sScript;
        for (int i=0; i<vLines.size(); ++i)
        {
            const QString &sLine = vLines[i];
            sScript += sLine;
        }

        syntaxCheck(sScript, pFile->getName());
        emit syntaxCheckSuccess(pFile);
    }
    catch(LuaException &exc)
    {
        exc.setFile(pFile);

        QString sMsg = QString("%1 in Line %2").arg(exc.getMessage())
                                               .arg(exc.getLine());
        emit syntaxCheckFail(pFile, sMsg);
    }
    catch(Exception &exc)
    {
        emit syntaxCheckFail(pFile, exc.getMessage());
    }
    catch(std::exception &exc)
    {
        emit syntaxCheckFail(pFile, exc.what());
    }
    catch(...)
    {
        emit syntaxCheckFail(pFile, "Internal error: FrmConsole::executeCommand");
    }
}

//-------------------------------------------------------------------------------------------------
void LuaWorker::on_checkProject(const IProject *pProject)
{
}


//-------------------------------------------------------------------------------------------------
void LuaWorker::init()
{
    if (m_luaState!=NULL)
        throw std::runtime_error("LUA is already initialized");

    m_luaState = luaL_newstate();
    if (m_luaState == NULL)
        throw std::runtime_error("Can't create LUA state");

    // folgender code stammt aus linit.c:
    const luaL_Reg lualibs[] = {
                                {"", luaopen_base},
                                {LUA_LOADLIBNAME, luaopen_package},
                                {LUA_TABLIBNAME,  luaopen_table},
                                {LUA_IOLIBNAME,   luaopen_io},
                                {LUA_OSLIBNAME,   luaopen_os},
                                {LUA_STRLIBNAME,  luaopen_string},
                                {LUA_MATHLIBNAME, luaopen_math},
                                {LUA_DBLIBNAME,   luaopen_debug},
                                {NULL, NULL}
                               };

    const luaL_Reg *lib = lualibs;
    for (; lib->func; lib++)
    {
        lua_pushcfunction(m_luaState, lib->func);
        lua_pushstring(m_luaState, lib->name);
        lua_call(m_luaState, 1, 0);
    }

    splashScreen();
}

//-------------------------------------------------------------------------------------------------
void LuaWorker::splashScreen()
{
    if (m_pConsole==NULL)
        return;

    m_pConsole->addLine(" _____           _              _     _                  ");
    m_pConsole->addLine("|_   _|         | |            | |   | |                 ");
    m_pConsole->addLine("  | |  _ __  ___| |_ __ _ _ __ | |_  | |    _   _  __ _  ");
    m_pConsole->addLine("  | | | '_ \\/ __| __/ _` | '_ \\| __| | |   | | | |/ _` |");
    m_pConsole->addLine(" _| |_| | | \\__ \\ || (_| | | | | |_  | |___| |_| | (_| |");
    m_pConsole->addLine("|_____|_| |_|___/\\__\\__,_|_| |_|\\__| |______\\__,_|\\__,_|");
    m_pConsole->addLine(" (C) 2012 Ingo Berg    http://instant_lua.beltoforion.de");
    m_pConsole->addLine("");
    m_pConsole->addLine(getCopyright());
    m_pConsole->addLine("");

}

//-------------------------------------------------------------------------------------------------
QString LuaWorker::getVersion() const
{
    return QString("Lua %1.%2.%3").arg(LUA_VERSION_MAJOR)
                                  .arg(LUA_VERSION_MINOR)
                                  .arg(LUA_VERSION_RELEASE);
}

//-------------------------------------------------------------------------------------------------
QString LuaWorker::getCopyright() const
{
    return QString(LUA_COPYRIGHT"\n"LUA_AUTHORS);
}

//-------------------------------------------------------------------------------------------------
LuaWorker& LuaWorker::operator<<(const ILuaValue &arg)
{
  arg.Push(m_luaState);
  return *this;
}

//-------------------------------------------------------------------------------------------------
LuaWorker& LuaWorker::operator>>(ILuaValue &arg)
{
  arg.Pop(m_luaState);
  return *this;
}

//-------------------------------------------------------------------------------------------------
void LuaWorker::setVariable(QString sName, ILuaValue &type)
{
  if (m_luaState==NULL)
    throw InternalError("LUA engine is not initialized.");

  type.Push(m_luaState);
  lua_setglobal(m_luaState, sName.toUtf8().constData());
}

//-------------------------------------------------------------------------------------------------
void LuaWorker::syntaxCheck(const QString &sLuaCode, const QString &sChunkName)
{
    if (m_luaState==NULL)
        throw LuaException(QString("Can't execute Lua code fragment \"%1\": Lua state is not initialized").arg(sChunkName));

    checkLuaError(luaL_loadbuffer(m_luaState,
                                  sLuaCode.toAscii(),
                                  sLuaCode.size(),
                                  sChunkName.toAscii()));
}

//-------------------------------------------------------------------------------------------------
void LuaWorker::checkLuaError(int errc)
{
    if (!errc)
        return;

    int nStackSize = lua_gettop(m_luaState);
    if (nStackSize>=1)
    {
        QString sErr = lua_tostring(m_luaState, -1);
        lua_pop(m_luaState, 1);
        throw LuaException(sErr);
    }
    else
        throw LuaException("Lua error (no details available)");
}

//-------------------------------------------------------------------------------------------------
void LuaWorker::doString(const QString &sLuaCode, const QString &sChunkName)
{
    if (m_luaState==NULL)
        throw LuaException(QString("Can't execute Lua code fragment \"%1\": Lua state is not initialized").arg(sLuaCode));

    m_luaState->stop_now = 0;

    syntaxCheck(sLuaCode, sChunkName);

    checkLuaError(lua_pcall(m_luaState, 0, 0, 0));
}
