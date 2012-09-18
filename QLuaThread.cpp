#include "QLuaThread.h"
#include <QMutexLocker>
#include <QTextStream>

#include <iostream>
#include "Exceptions.h"
#include "IConsole.h"
#include "IFile.h"


//-------------------------------------------------------------------------------------------------
QLuaThread::QLuaThread(QObject *parent, IConsole *pConsole)
    :QThread(parent)
    ,m_pConsole(NULL)
    ,m_mtxTasks()
{
    bindToConsole(pConsole);

    setTerminationEnabled(false);

    connect(this, SIGNAL(checkSyntax(const IFile*)), SLOT(on_checkFile(const IFile*)));
}

//-------------------------------------------------------------------------------------------------
QLuaThread::~QLuaThread()
{}

//-------------------------------------------------------------------------------------------------
void QLuaThread::bindToConsole(IConsole *pConsole)
{
    m_pConsole = pConsole;
}

//-------------------------------------------------------------------------------------------------
/** \brief Ausführen von Lua code aus einen String.

    Diese Funktion wird für die Konsolenanwendung benötigt.
*/
void QLuaThread::on_doString(const QString &sCmd)
{
    if (m_pConsole==NULL)
        return;

    try
    {
        m_lua.execute(sCmd);
    }
    catch(Exception &exc)
    {
        m_pConsole->addLine(exc.getMessage(), Qt::red);
    }
    catch(std::exception &exc)
    {
        m_pConsole->addLine(exc.what(), Qt::red);
    }
    catch(...)
    {
        m_pConsole->addLine("Internal error: FrmConsole::executeCommand", Qt::red);
    }
}

//-------------------------------------------------------------------------------------------------
void QLuaThread::on_doFile(IFile *pFile)
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

        m_lua.doString(sScript, pFile->getName());
    }
    catch(LuaException &exc)
    {
        exc.setFile(pFile);

        QString sMsg = QString("%1 in Line %2").arg(exc.getMessage())
                                               .arg(exc.getLine());
        m_pConsole->addLine(sMsg, Qt::red);

        emit luaError(exc);
    }
    catch(Exception &exc)
    {
        m_pConsole->addLine(exc.getMessage(), Qt::red);
    }
    catch(std::exception &exc)
    {
        m_pConsole->addLine(exc.what(), Qt::red);
    }
    catch(...)
    {
        m_pConsole->addLine("Internal error: FrmConsole::executeCommand", Qt::red);
    }
}

//-------------------------------------------------------------------------------------------------
void QLuaThread::on_doProject(const IProject *pProject)
{
    if (m_pConsole==NULL || pProject==NULL)
        return;

    try
    {
        //m_lua.execute(sCmd);
    }
    catch(Exception &exc)
    {
        m_pConsole->addLine(exc.getMessage(), Qt::red);
    }
    catch(std::exception &exc)
    {
        m_pConsole->addLine(exc.what(), Qt::red);
    }
    catch(...)
    {
        m_pConsole->addLine("Internal error: FrmConsole::executeCommand", Qt::red);
    }
}

//-------------------------------------------------------------------------------------------------
/** \brief Anstossen eines Syntax checks.

    Der Check wird in dieser Klasse ausgeführt allerdings über Signal/Slot
    in den Hauptthread verlagert.
*/
void QLuaThread::doSyntaxCheck(const IFile *pFile)
{
    if (pFile!=NULL)
        emit checkSyntax(pFile);
}

//-------------------------------------------------------------------------------------------------
void QLuaThread::on_checkFile(const IFile *pFile)
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
        m_pConsole->addLine(sMsg, Qt::red);

        emit luaError(exc);
    }
    catch(Exception &exc)
    {
        m_pConsole->addLine(exc.getMessage(), Qt::red);
    }
    catch(std::exception &exc)
    {
        m_pConsole->addLine(exc.what(), Qt::red);
    }
    catch(...)
    {
        m_pConsole->addLine("Internal error: FrmConsole::executeCommand", Qt::red);
    }
}

//-------------------------------------------------------------------------------------------------
void QLuaThread::on_checkProject(const IProject *pProject)
{
    if (m_pConsole==NULL || pProject==NULL)
        return;

    try
    {
        //m_lua.execute(sCmd);
    }
    catch(Exception &exc)
    {
        m_pConsole->addLine(exc.getMessage(), Qt::red);
    }
    catch(std::exception &exc)
    {
        m_pConsole->addLine(exc.what(), Qt::red);
    }
    catch(...)
    {
        m_pConsole->addLine("Internal error: FrmConsole::executeCommand", Qt::red);
    }
}

//-------------------------------------------------------------------------------------------------
void QLuaThread::run()
{
    m_lua.init();
    splashScreen();
    exec();
}

//-------------------------------------------------------------------------------------------------
void QLuaThread::splashScreen()
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
    m_pConsole->addLine(m_lua.getCopyright());
    m_pConsole->addLine("");
}
