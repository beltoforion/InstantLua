#include "LuaTabWindow.h"

//-------------------------------------------------------------------------------------------------
LuaTabWindow::LuaTabWindow()
    :ILuaTable(QString("window"))
{
    // Add functions
    addFunc("create", LuaTabWindow::create);
    addFunc("finalize", LuaTabWindow::finalize);

    // Add Properties
    addProperty("width", LuaTabWindow::prop_width_read, LuaTabWindow::prop_width_write);
    addProperty("height", LuaTabWindow::prop_height_read, LuaTabWindow::prop_height_write);

    // Add Values
//    addInteger("valInt");
//    addDouble("valDouble");
}


//-------------------------------------------------------------------------------------------------
//
// Lua function callbacks
//
//-------------------------------------------------------------------------------------------------

int LuaTabWindow::create(lua_State *pState)
{
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

int LuaTabWindow::prop_width_read(lua_State *pState)
{
    return 0;
}

//-------------------------------------------------------------------------------------------------
int LuaTabWindow::prop_width_write(lua_State *pState)
{
    return 0;
}

//-------------------------------------------------------------------------------------------------
int LuaTabWindow::prop_height_read(lua_State *pState)
{
    return 0;
}

//-------------------------------------------------------------------------------------------------
int LuaTabWindow::prop_height_write(lua_State *pState)
{
    return 0;
}
