#ifndef LUATABWINDOW_H
#define LUATABWINDOW_H

//-------------------------------------------------------------------------------------------------
#include "ILuaTable.h"

//--- Lua includes --------------------------------------------------------------------------------
#include "lualib.h"

//-------------------------------------------------------------------------------------------------
class LuaTabWindow : public ILuaTable
{
public:
    LuaTabWindow();

private:

    //---------------------------------------------------------------------------------------------
    // Lua function callbacks
    //---------------------------------------------------------------------------------------------

    static int create(lua_State *pState);
    static int finalize(lua_State *pState);

    //---------------------------------------------------------------------------------------------
    // Lua Property callbacks
    //---------------------------------------------------------------------------------------------

    static int prop_width_read(lua_State *pState);
    static int prop_width_write(lua_State *pState);

    static int prop_height_read(lua_State *pState);
    static int prop_height_write(lua_State *pState);
};

#endif // LUATABWINDOW_H
