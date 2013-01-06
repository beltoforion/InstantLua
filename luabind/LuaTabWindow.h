#ifndef LUATABWINDOW_H
#define LUATABWINDOW_H

//-------------------------------------------------------------------------------------------------
#include "ILuaTable.h"

//--- Lua includes --------------------------------------------------------------------------------
#include "lualib.h"
#include "lauxlib.h"

//-------------------------------------------------------------------------------------------------
#include "FwdDecl.h"


//-------------------------------------------------------------------------------------------------
class LuaTabWindow : public ILuaTable
{
public:
    LuaTabWindow();

    virtual const SProperty* getProperties() const;
    virtual const SFunction* getFunctions() const;
    virtual const char* getName() const;
    virtual QString toString() const;

private:

    int m_nWidth;
    int m_nHeight;

    //---------------------------------------------------------------------------------------------
    // Lua function callbacks
    //---------------------------------------------------------------------------------------------


    //---------------------------------------------------------------------------------------------
    // Lua Property callbacks
    //---------------------------------------------------------------------------------------------

    static int prop_width_read(lua_State *pState);
    static int prop_width_write(lua_State *pState);

    static int prop_height_read(lua_State *pState);
    static int prop_height_write(lua_State *pState);
};

#endif // LUATABWINDOW_H
