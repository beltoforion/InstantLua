#ifndef LUAWORKER_H
#define LUAWORKER_H

//--- QT-Library ----------------------------------------------------------------------------------
#include <QObject>
#include <QMutex>
#include <QSharedPointer>
#include <QString>

#include "FwdDecl.h"
#include "IConsole.h"
#include "IScriptEngine.h"

//--- LUA includes --------------------------------------------------------------------------------
#include "lauxlib.h"
#include "lualib.h"

//-------------------------------------------------------------------------------------------------
class LuaWorker : public QObject,
                  public IScriptEngine
{
    Q_OBJECT

public:
    explicit LuaWorker(IConsole *pConsole);
    virtual ~LuaWorker();

    LuaWorker& operator<<(const ILuaValue &arg);
    LuaWorker& operator>>(ILuaValue &arg);

    void setVariable(QString sName, ILuaValue &type);

    // IScriptEngine
    virtual void doSyntaxCheck(const IFile *pFile);
    virtual void stop();
    virtual QString getVersion() const;
    virtual QString getCopyright() const;

signals:
    void finished();
    void error(QString sErr);
    void syntaxCheckFail(const IFile *pFile, QString sErr);
    void syntaxCheckSuccess(const IFile *pFile);
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
    lua_State *m_luaState;
    QSharedPointer<ILuaValue> m_pSysVar;

    void init();
    void splashScreen();

    void checkLuaError(int errc);
    void syntaxCheck(const QString &sLuaCode, const QString &sChunkName);
    void doString(const QString &sLuaCode, const QString &sChunkName);
};

#endif // LUAWORKER_H
