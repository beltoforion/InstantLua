#include "LuaTabWindow.h"

//-------------------------------------------------------------------------------------------------
LuaTabWindow::LuaTabWindow()
    :ILuaTable()
    ,m_nWidth(640)
    ,m_nHeight(480)
{}


//-------------------------------------------------------------------------------------------------
const ILuaTable::SProperty* LuaTabWindow::getProperties() const
{
    static const SProperty prop[] =
                    {
                        { "width",  LuaTabWindow::prop_width_read,  LuaTabWindow::prop_width_write  },
                        { "height", LuaTabWindow::prop_height_read, LuaTabWindow::prop_height_write },
                        { NULL, NULL, NULL }
                    };

    return prop;
}

//-------------------------------------------------------------------------------------------------
const ILuaTable::SFunction* LuaTabWindow::getFunctions() const
{
    static const SFunction func[] =
                    {
                        { "new", LuaTabWindow::create },
                        { NULL, NULL }
                    };
    return func;
}

//-------------------------------------------------------------------------------------------------
const char* LuaTabWindow::getName() const
{
    return "window";
}

//-------------------------------------------------------------------------------------------------
QString LuaTabWindow::toString() const
{
    return getName();
}

//-------------------------------------------------------------------------------------------------
//
// Lua function callbacks
//
//-------------------------------------------------------------------------------------------------

int LuaTabWindow::create(lua_State *pState)
{
    int argc = lua_gettop(pState);
    if (argc != 0)
        return luaL_error(pState, "Got %d arguments expected none.", argc);

    return 0;
}

//-------------------------------------------------------------------------------------------------
int LuaTabWindow::finalize(lua_State *pState)
{
    return 0;
}

//-------------------------------------------------------------------------------------------------
//
// Lua Property callbacks
//
//-------------------------------------------------------------------------------------------------

int LuaTabWindow::prop_width_read(lua_State *L)
{
    lua_pushnumber(L, 640); //m_nWidth);
    return 1;
}

//-------------------------------------------------------------------------------------------------
int LuaTabWindow::prop_width_write(lua_State *pState)
{
    return 0;
}

//-------------------------------------------------------------------------------------------------
int LuaTabWindow::prop_height_read(lua_State *L)
{
    lua_pushnumber(L, 480); //m_nHeight);
    return 1;
}

//-------------------------------------------------------------------------------------------------
int LuaTabWindow::prop_height_write(lua_State *pState)
{
    return 0;
}
