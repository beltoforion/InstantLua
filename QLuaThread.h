#ifndef QLUATHREAD_H
#define QLUATHREAD_H

//-------------------------------------------------------------------------------------------------
#include <QThread>
#include <QVector>
#include <QMutex>

//-------------------------------------------------------------------------------------------------
#include "luabind/LuaContext.h"
#include "FwdDecl.h"
#include "IObserveable.h"
#include "IScriptEngine.h"

//-------------------------------------------------------------------------------------------------
class QLuaThread : public QThread,
                   public IScriptEngine
{
    Q_OBJECT
public:
    explicit QLuaThread(QObject *parent = NULL, IConsole *pConsole = NULL);
    virtual ~QLuaThread();

    void stop();

    //---------------------------------------------------------------------------------------------
    // IScriptEngine implementieren
    //---------------------------------------------------------------------------------------------

    virtual void doSyntaxCheck(const IFile *pFile);

protected:
    void run();

signals:
    void luaFunctionCall();
    void luaError(const LuaException &exc);
    void checkSyntax(const IFile *pFile);

public slots:

    // Ausführung von Lua-Code
    void on_doString(const QString &script);
    void on_doFile(IFile *pFile);
    void on_doProject(const IProject *pProject);

    // Syntaxüberprüfung
    void on_checkFile(const IFile *pFile);
    void on_checkProject(const IProject *pProject);

private:
    IConsole *m_pConsole;
    QMutex m_mtxTasks;
    LuaContext m_lua;

    void splashScreen();

};

#endif // QLUATHREAD_H
