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
//  lua_pushinteger(luaState, m_val);
/*
    lua_newtable(luaState);
    for (int i = 1; i <= 5; i++)
    {
        lua_pushnumber(L, i);   // Push the table index
        lua_pushnumber(L, i*2); // Push the cell value
        lua_rawset(L, -3);      // Stores the pair in the table
    }

    lua_setglobal(L, "_sys");
*/
}

//-------------------------------------------------------------------------------------------------
void LuaSysVar::Pop(lua_State *luaState)
{
//  m_val = lua_tointeger(luaState, -1);
}

