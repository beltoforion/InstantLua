#ifndef QLUATHREAD_H
#define QLUATHREAD_H

//-------------------------------------------------------------------------------------------------
#include <QThread>
#include <QVector>
#include <QMutex>

//-------------------------------------------------------------------------------------------------
#include "luabind/LuaContext.h"
#include "FwdDecl.h"


//-------------------------------------------------------------------------------------------------
class QLuaThread : public QThread
{
    Q_OBJECT
public:
    explicit QLuaThread(QObject *parent = 0);
    virtual ~QLuaThread();

    void addTask();
    void stop();
    void bindToConsole(IConsole *pConsole);

protected:
    void run();

signals:
    void luaSyntaxCheckDone();
    void luaExecutionFinished();
    void luaFunctionCall();
    void luaError(const LuaException &exc);

public slots:

    // Ausf�hrung von Lua-Code
    void on_doString(const QString &script);
    void on_doFile(IFile *pFile);
    void on_doProject(const IProject *pProject);

    // Syntax�berpr�fung
    void on_checkFile(const IFile *pFile);
    void on_checkProject(const IProject *pProject);

private:
    IConsole *m_pConsole;
    QMutex m_mtxTasks;
    LuaContext m_lua;

    void splashScreen();

};

#endif // QLUATHREAD_H
