#include "QLuaThread.h"
#include <QMutexLocker>

#include <iostream>
#include "Exceptions.h"
#include "IConsole.h"
#include "IFile.h"


//-------------------------------------------------------------------------------------------------
QLuaThread::QLuaThread(QObject *parent)
    :QThread(parent)
    ,m_pConsole(NULL)
    ,m_mtxTasks()
{
    setTerminationEnabled(false);
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
void QLuaThread::addTask()
{
    QMutexLocker lock(&m_mtxTasks);
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
void QLuaThread::on_doFile(const IFile *pFile)
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
void QLuaThread::run()
{
    m_lua.init();
    splashScreen();
    exec();
}

//-------------------------------------------------------------------------------------------------
void QLuaThread::splashScreen()
{
    m_pConsole->addLine(tr(" _____           _              _     _                  "));
    m_pConsole->addLine(tr("|_   _|         | |            | |   | |                 "));
    m_pConsole->addLine(tr("  | |  _ __  ___| |_ __ _ _ __ | |_  | |    _   _  __ _  "));
    m_pConsole->addLine(tr("  | | | '_ \\/ __| __/ _` | '_ \\| __| | |   | | | |/ _` |"));
    m_pConsole->addLine(tr(" _| |_| | | \\__ \\ || (_| | | | | |_  | |___| |_| | (_| |"));
    m_pConsole->addLine(tr("|_____|_| |_|___/\\__\\__,_|_| |_|\\__| |______\\__,_|\\__,_|"));
    m_pConsole->addLine(tr(" (C) 2012 Ingo Berg    http://instant_lua.beltoforion.de"));
    m_pConsole->addLine(tr(""));
    m_pConsole->addLine(m_lua.getCopyright());
    m_pConsole->addLine(tr(""));
}
