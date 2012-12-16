#ifndef LUA_CONTEXT_H
#define LUA_CONTEXT_H

//--- Standard includes ---------------------------------------------------------------------------
#include <memory>

//--- QT Lib includes -----------------------------------------------------------------------------
#include <QString>
#include <QSharedPointer>

//--- LUA includes --------------------------------------------------------------------------------
#include "lauxlib.h"
#include "lualib.h"

//-------------------------------------------------------------------------------------------------
#include "ILuaValue.h"


//-------------------------------------------------------------------------------------------------
class LuaContext
{
public:
  LuaContext();
  virtual ~LuaContext();

  void init();
  void checkLuaError(int errc);

  QString getVersion() const;
  QString getCopyright() const;

  virtual void execute(const QString &sCmd);

  void doString(const QString &sLuaCode, const QString &sChunkName);
  void syntaxCheck(const QString &sLuaCode, const QString &sChunkName);
  int doCall(int nArg, int clear);

  void setVariable(QString sName, ILuaValue &type);
  void stop();

  LuaContext& operator<<(const ILuaValue &arg);
  LuaContext& operator>>(ILuaValue &arg);

private:
  LuaContext(const LuaContext&);
  LuaContext& operator=(const LuaContext&);

  lua_State *m_luaState;

  QSharedPointer<ILuaValue> m_pSysVar;
};

#endif
