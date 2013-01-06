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
