#include "LuaWorker.h"
#include "Exceptions.h"

#include <QThread>
#include <QVector>
#include <QString>

#include "IFile.h"


//-------------------------------------------------------------------------------------------------
LuaWorker::LuaWorker(IConsole *pConsole)
    :QObject(NULL)
    ,m_pConsole(pConsole)
    ,m_mtxTasks()
{
    // Hier keine dynamische allokation, da diese im Hauptthread geschehen würde!

    if (m_pConsole==NULL)
        throw InternalError(tr("Can't create Lua worker with null console pointer"));

    init();

//    connect(this, SIGNAL(checkSyntax(const IFile*)), SLOT(on_checkFile(const IFile*)));
}

//-------------------------------------------------------------------------------------------------
LuaWorker::~LuaWorker()
{}

//-------------------------------------------------------------------------------------------------
void LuaWorker::doSyntaxCheck(const IFile *pFile)
{
    if (pFile!=NULL)
        emit checkSyntax(pFile);
}

//-------------------------------------------------------------------------------------------------
/** \brief Ausführen von Lua code aus einen String.

    Diese Funktion wird für die Konsolenanwendung benötigt.
*/
void LuaWorker::on_doString(const QString &sCmd)
{
    if (m_pConsole==NULL)
        return;

    qDebug("on_doString(%s); thread id: %d",
           sCmd.toStdString().c_str(),
           reinterpret_cast<int>(QThread::currentThreadId()));

    try
    {
        m_lua.execute(sCmd);
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

        m_lua.doString(sScript, pFile->getName());
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
        QVector<QString> vLines = pFile->getLines();
        QString sScript;
        for (int i=0; i<vLines.size(); ++i)
        {
            sScript += vLines[i];
        }

        m_lua.syntaxCheck(sScript, pFile->getName());

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
void LuaWorker::on_checkProject(const IProject *pProject)
{
}


//-------------------------------------------------------------------------------------------------
void LuaWorker::init()
{
    m_lua.init();

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
    m_pConsole->addLine(m_lua.getCopyright());
    m_pConsole->addLine("");
}
