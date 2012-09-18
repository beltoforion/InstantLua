#ifndef LUA_CONTEXT_H
#define LUA_CONTEXT_H

//--- Standard includes ---------------------------------------------------------------------------
#include <string>

//--- QT Lib includes -----------------------------------------------------------------------------
#include <QString>

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

  // IInterpreter interface
  virtual void execute(const QString &sCmd);

  void doString(const QString &sLuaCode, const QString &sChunkName);
  void syntaxCheck(const QString &sLuaCode, const QString &sChunkName);
  int doCall(int nArg, int clear);

  LuaContext& GenPCall(const std::string &sLuaCode);
  LuaContext& operator<<(const ILuaValue &arg);
  LuaContext& operator>>(ILuaValue &arg);

  void SetVariable(const char *szName, ILuaValue &type);
  void LoadFile(const char *szFileName);

  lua_State* GetState();

private:
  LuaContext(const LuaContext&);
  LuaContext& operator=(const LuaContext&);

  lua_State *m_luaState;
};

#endif
