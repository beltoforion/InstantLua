#include "LuaContext.h"
#include <QString>

//--- Standard includes ---------------------------------------------------------------------------
#include "Exceptions.h"

//--- LUA includes --------------------------------------------------------------------------------
#include "lua.h"
#include "lstate.h"


//-------------------------------------------------------------------------------------------------
LuaContext::LuaContext()
  :m_luaState(NULL)
  ,m_pSysVar(NULL)
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
QString LuaContext::getVersion() const
{
    return QString("Lua %1.%2.%3").arg(LUA_VERSION_MAJOR)
                                  .arg(LUA_VERSION_MINOR)
                                  .arg(LUA_VERSION_RELEASE);
}

//-------------------------------------------------------------------------------------------------
QString LuaContext::getCopyright() const
{
    return QString(LUA_COPYRIGHT"\n"LUA_AUTHORS);
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

    // Setzen der Systemeigenen Kontrollvariablen
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

    m_luaState->stop_now = 0;

//    checkLuaError(luaL_loadbuffer(m_luaState,
//                                  sLuaCode.toAscii(),
//                                  sLuaCode.size(),
//                                  sChunkName.toAscii()));
    syntaxCheck(sLuaCode, sChunkName);

    checkLuaError(lua_pcall(m_luaState, 0, 0, 0));
}

//-------------------------------------------------------------------------------------------------
void LuaContext::syntaxCheck(const QString &sLuaCode, const QString &sChunkName)
{
    if (m_luaState==NULL)
        throw LuaException(QString("Can't execute Lua code fragment \"%1\": Lua state is not initialized").arg(sLuaCode));

    checkLuaError(luaL_loadbuffer(m_luaState,
                                  sLuaCode.toAscii(),
                                  sLuaCode.size(),
                                  sChunkName.toAscii()));
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
void LuaContext::setVariable(QString sName, ILuaValue &type)
{
  if (m_luaState==NULL)
    throw InternalError("LUA engine is not initialized.");
  
  type.Push(m_luaState);
  lua_setglobal(m_luaState, sName.toUtf8().constData());
}

//-------------------------------------------------------------------------------------------------
/** \brief Anhalten von Lua zum nächstmöglichen Zeitpunkt.
*/
void LuaContext::stop()
{
    m_luaState->stop_now = 1;
}

//-------------------------------------------------------------------------------------------------
bool LuaContext::isStopFlagSet()
{
    return m_luaState->stop_now != 0;
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
