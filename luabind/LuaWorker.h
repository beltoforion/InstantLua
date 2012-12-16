#ifndef LUAWORKER_H
#define LUAWORKER_H

#include <QObject>
#include <QMutex>

#include "FwdDecl.h"
#include "IConsole.h"
#include "IScriptEngine.h"
#include "LuaContext.h"


//-------------------------------------------------------------------------------------------------
class LuaWorker : public QObject,
                  public IScriptEngine
{
    Q_OBJECT
public:
    explicit LuaWorker(IConsole *pConsole);
    virtual ~LuaWorker();

    // IScriptEngine
    virtual void doSyntaxCheck(const IFile *pFile);
    virtual void stop();

signals:
    void finished();
    void aborted();
    void stop_requested();
    void error(QString sErr);

//    void luaFunctionCall();
//    void luaError(const LuaException &exc);
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

    void init();
};

#endif // LUAWORKER_H
