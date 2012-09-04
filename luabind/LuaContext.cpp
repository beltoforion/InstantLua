#include "LuaContext.h"

//--- Standard includes ---------------------------------------------------------------------------
#include "Exceptions.h"

//--- LUA includes --------------------------------------------------------------------------------
extern "C"
{
#include "lua.h"
}

//-------------------------------------------------------------------------------------------------
LuaContext::LuaContext()
  :m_luaState(NULL)
{}

//-------------------------------------------------------------------------------------------------
LuaContext::~LuaContext()
{
  if (m_luaState)
  {
    lua_close(m_luaState);
    m_luaState = NULL;
  }
}

//-------------------------------------------------------------------------------------------------
void LuaContext::init()
{
  if (m_luaState!=NULL)
    throw std::runtime_error("LUA is already initialized");

  m_luaState = luaL_newstate();
  if (m_luaState == NULL) 
    throw std::runtime_error("Can't create LUA state");

  // öffnen der LUA standardbibliotheken. Ab Lua 5.1, dürfen die
  // luaopen_xxx Befehle nicht mehr von c aus aufgerufen werden

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
}

//-------------------------------------------------------------------------------------------------
void LuaContext::execute(const QString &sCmd)
{
    doString(sCmd, "command_line_chunk");
}

//-------------------------------------------------------------------------------------------------
void LuaContext::checkLuaError(int errc)
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
void LuaContext::doString(const QString &sLuaCode, const QString &sChunkName)
{
    if (m_luaState==NULL)
        throw LuaException(QString("Can't execute Lua code fragment \"%1\": Lua state is not initialized").arg(sLuaCode));

    checkLuaError(luaL_loadbuffer(m_luaState,
                                  sLuaCode.toAscii(),
                                  sLuaCode.size(),
                                  sChunkName.toAscii()));

    checkLuaError(lua_pcall(m_luaState, 0, 0, 0));
}

//-------------------------------------------------------------------------------------------------
int LuaContext::doCall(int nArg, int clear)
{
  int nBase = lua_gettop(m_luaState) - nArg; // function index

  int status = lua_pcall(m_luaState, nArg, (clear ? 0 : LUA_MULTRET), nBase);
  QString sErr = lua_tostring(m_luaState, -1);

  // force a complete garbage collection in case of errors
  if (status != 0)
    lua_gc(m_luaState, LUA_GCCOLLECT, 0);
/*

//  lua_pushcfunction(m_luaState, traceback);  // push traceback function
  lua_insert(m_luaState, nBase);             // put it under chunk and args

  signal(SIGINT, laction);
  int status = lua_pcall(L, narg, (clear ? 0 : LUA_MULTRET), base);
  signal(SIGINT, SIG_DFL);

  lua_remove(m_luaState, base);  // remove traceback function

  // force a complete garbage collection in case of errors
  if (status != 0)
    lua_gc(m_luaState, LUA_GCCOLLECT, 0);

  return status;
*/
  return 0;
}

//-------------------------------------------------------------------------------------------------
void LuaContext::SetVariable(const char *szName, ILuaValue &type)
{
  if (m_luaState==NULL)
    throw std::runtime_error("LUA engine is not initialized.");
  
  type.Push(m_luaState);
  lua_setglobal(m_luaState, szName);
}

/* hinzufügen einer Tabelle:
  // test
  lua_newtable(L);
  for (int i = 1; i <= 5; i++) 
  {
        lua_pushnumber(L, i);   // Push the table index
        lua_pushnumber(L, i*2); // Push the cell value 
        lua_rawset(L, -3);      // Stores the pair in the table 
  }
  lua_setglobal(L, "xxx");
*/

//-------------------------------------------------------------------------------------------------
lua_State* LuaContext::GetState()
{
  return m_luaState;
}

//-------------------------------------------------------------------------------------------------
LuaContext& LuaContext::GenPCall(const std::string &sLuaCode)
{
  if (luaL_loadstring(m_luaState, sLuaCode.c_str()))
    throw std::runtime_error(lua_tostring(m_luaState, -1));

  return *this;
}

//-------------------------------------------------------------------------------------------------
LuaContext& LuaContext::operator<<(const ILuaValue &arg)
{
  arg.Push(m_luaState);
  return *this;
}

//-------------------------------------------------------------------------------------------------
LuaContext& LuaContext::operator>>(ILuaValue &arg)
{
  arg.Pop(m_luaState);
  return *this;
}



//-------------------------------------------------------------------------------------------------
/** \brief Loads a file as a lua chunk. 
*/
void LuaContext::LoadFile(const char *szFileName)
{
/*
  int stat = luaL_loadfile (m_luaState, szFileName);
  LUA_ERRFILE
*/
}

