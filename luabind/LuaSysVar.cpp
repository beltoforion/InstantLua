#include "LuaSysVar.h"

//-------------------------------------------------------------------------------------------------
// LuaSysVar
//-------------------------------------------------------------------------------------------------

LuaSysVar::LuaSysVar()
  :ILuaValue()
{
    m_data.m_bRunning = true;
}

//-------------------------------------------------------------------------------------------------
LuaSysVar::~LuaSysVar()
{}

//-------------------------------------------------------------------------------------------------
void LuaSysVar::Push(lua_State *luaState) const
{
    lua_newtable(luaState);

    // Push the key for the sub-table, then the sub table itself,
    // and then set the key into the outer table
    //lua_pushstring (L , "clientVersion");
    //lua_pushstring (L , "clientVersion");

    // Now we can set a global for the outer table
    //lua_setglobal (L , "_sys");
}

//-------------------------------------------------------------------------------------------------
void LuaSysVar::Pop(lua_State *luaState)
{
//  m_val = lua_tointeger(luaState, -1);
}

