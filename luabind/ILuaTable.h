#ifndef ILUA_TABLE_H
#define ILUA_TABLE_H

//-------------------------------------------------------------------------------------------------
#include <QString>
#include <QVector>

//--- LUA includes --------------------------------------------------------------------------------
#include "lualib.h"


//-------------------------------------------------------------------------------------------------
class ILuaTable
{
protected:

    struct SProperty
    {
        const char *name;
        lua_CFunction ptr_read;
        lua_CFunction ptr_write;
    };

    struct SFunction
    {
        const char *name;
        lua_CFunction ptr;
    };

public:

    ILuaTable();
    virtual ~ILuaTable();

    void bindToLua(lua_State *pState);

    virtual const SProperty* getProperties() const = 0;
    virtual const SFunction* getFunctions() const = 0;
    virtual const char* getName() const = 0;
    virtual QString toString() const = 0;

private:

    // Hilfsfunktionen
    static const ILuaTable* getTableFromStack(lua_State *pState, int idx);

    // Spezielle meta funktionscallbacks von lua
    static int __index(lua_State *lua);
    static int __newindex(lua_State *lua);
    static int __tostring(lua_State *lua);
};

#endif
