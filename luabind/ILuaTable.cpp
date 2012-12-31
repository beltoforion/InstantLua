#include "ILuaTable.h"
#include "LuaExtensions.h"

//--- Lua includes --------------------------------------------------------------------------------
#include "lauxlib.h"

#include "ISyncContext.h"

//-------------------------------------------------------------------------------------------------
ISyncContext *ILuaTable::s_pSyncContext = NULL;

//-------------------------------------------------------------------------------------------------
void ILuaTable::setSyncContext(ISyncContext *pContext)
{
    ILuaTable::s_pSyncContext = pContext;
}

//-------------------------------------------------------------------------------------------------
ILuaTable::ILuaTable()
{}

//-------------------------------------------------------------------------------------------------
ILuaTable::~ILuaTable()
{}

//-------------------------------------------------------------------------------------------------
ILuaTable* ILuaTable::getTableFromStack(lua_State *pState, int idx)
{
    if (luaL_getmetafield(pState, idx, "this_ptr"))
    {
        ILuaTable *pTable = (ILuaTable*)lua_touserdata(pState, -1);
        lua_pop(pState, 1);
        return pTable;
    }
    else
    {
        return NULL;
    }
}


//-------------------------------------------------------------------------------------------------
/** \brief Implementierung von Property read-only zugriffen durch implementieren der
           Lua eigenen __index metafunktion.
*/
int ILuaTable::__index(lua_State *L)
{
    // Lua parameter für __index:
    //      1. Tabelle -> pLuaTable
    //      2. key     -> szKey

    lua_ex::stackDump(L);

    const ILuaTable *pLuaTable = ILuaTable::getTableFromStack(L, -2);
    if (pLuaTable!=NULL)
    {
        // Nachsehen, ob eine Property aufgerufen wurde
        const char *szKey = lua_tostring(L, -1);

        const SProperty *pProp = pLuaTable->getProperties();
        for ( ; pProp->name!=NULL; ++pProp)
        {
            if (strcmp(szKey, pProp->name)==0)
            {
                pProp->ptr_read(L);
                return 1;
            }
        }

        lua_ex::error(L, "Table has no property or function \"%s\".", szKey);
        return 0;
    }
    else
        return 0;
/*
    const SProperty *pProp = lua_table_get_property(pState, -2);
    if (!pProp)
        return 0;

    if (pProp->ptr_read)
    {
        pProp->ptr_read(pState);
        return 1;
    }
    else
    {
        lua_throw_error_from_c(pState,
                               "Cannot read from write only table property %s!",
                               pProp->name.toAscii());
    }
*/
    return 0;
}

//-------------------------------------------------------------------------------------------------
int ILuaTable::__newindex(lua_State *pState)
{
/*
    const SProperty *pProp = lua_table_get_property(pState, -3);
    if (!pProp)
        return 0;

    if (pProp->ptr_write)
    {
        pProp->ptr_write(pState);
    }
    else
    {
        lua_throw_error_from_c(pState,
                               "Cannot write to read only table property %s!", property->name);
    }
*/
    return 0;
}

//-----------------------------------------------------------------------------
int ILuaTable::__tostring(lua_State *pState)
{
    const ILuaTable *pLuaTable = ILuaTable::getTableFromStack(pState, -1);
    if (pLuaTable!=NULL)
    {
        lua_pushfstring(pState, pLuaTable->toString().toAscii());
        return 1;
    }
    else
    {
        return 0;
    }
/*
    // push the ILuaTable pointer to the stack
    int stat = luaL_getmetafield(pState, -1, "this_ptr");
    if (!stat)
        return 0;

    const ILuaTable *pLuaTable = (const ILuaTable*)lua_touserdata(pState, -1);
    lua_pop(pState, 1); // eintrag vom stack nehmen

    if (pLuaTable!=NULL)
    {
        lua_pushfstring(pState, pLuaTable->toString().toAscii());
        return 1;
    }
    else
    {
        return 0;
    }
*/
}

//-------------------------------------------------------------------------------------------------
void ILuaTable::bindToLua(lua_State *pState)
{
    if (pState==NULL)
        return;

    lua_newtable(pState);

    // Funktionen registrieren
    const SFunction  *pFun  = getFunctions();
    if (pFun!=NULL)
    {
        for (; pFun->ptr!=NULL; ++pFun)
        {
            lua_pushcfunction(pState, pFun->ptr);
            lua_setfield(pState, -2, pFun->name);
        }
    }

    lua_newtable(pState);

    // überladen der __index funktion um properties zu implementieren
    lua_pushstring(pState, "__index");
    lua_pushcfunction(pState, ILuaTable::__index);
    lua_settable(pState, -3);

    // überladen der __newindex funktion um properties zu implementieren
    lua_pushstring(pState, "__newindex");
    lua_pushcfunction(pState, ILuaTable::__newindex);
    lua_settable(pState, -3);

    // function for table to string conversion
    lua_pushstring(pState, "__tostring");
    lua_pushcfunction(pState, ILuaTable::__tostring);
    lua_settable(pState, -3);

    // store pointer to this as light userdata
    lua_pushstring(pState, "this_ptr");
    lua_pushlightuserdata(pState, (void*)this);
    lua_settable(pState, -3);

    lua_setmetatable(pState, -2);

    lua_setglobal(pState, getName());
}
