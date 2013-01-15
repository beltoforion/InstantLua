#include "ILuaTable.h"
#include "LuaExtensions.h"

//-------------------------------------------------------------------------------------------------

//--- Lua includes --------------------------------------------------------------------------------
#include "lauxlib.h"

#include "Exceptions.h"
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
ILuaTable* ILuaTable::getTableFromStack(lua_State *L, int idx)
{
    if (luaL_getmetafield(L, idx, "this_ptr"))
    {
        ILuaTable *pTable = (ILuaTable*)lua_touserdata(L, -1);
        lua_pop(L, 1);
        return pTable;
    }
    else
    {
        return NULL;
    }
}

//-------------------------------------------------------------------------------------------------
ILuaTable* ILuaTable::checkArguments(lua_State *L, int argRequired, const QString& sFunName)
{
    int argc = lua_gettop(L);
    if (argc!=argRequired)
        throw Exception(QString("Error in Canvas:moveTo(x, y): Invalid number of arguments.").arg(sFunName));

    // Parameter 1 muss eine Lua Tabelle sein
    luaL_checktype(L, 1, LUA_TTABLE);

    if (!luaL_getmetafield(L, 1, "this_ptr"))
        throw Exception(QString("Internal error in %1: No meta table found.").arg(sFunName).toAscii());

    ILuaTable *pTable = (ILuaTable*)lua_touserdata(L, -1);
    lua_pop(L, 1);

    if (pTable==NULL)
        throw Exception(QString("Internal error in %1: No meta table found.").arg(sFunName).toAscii());

    return pTable;
}

//-------------------------------------------------------------------------------------------------
void* ILuaTable::checkAndUnwrap(lua_State *L, int argRequired, const QString& sFunName)
{
    int argc = lua_gettop(L);
    if (argc!=argRequired)
        throw Exception(QString("Error in Canvas:moveTo(x, y): Invalid number of arguments.").arg(sFunName));

    // Parameter 1 muss eine Lua Tabelle sein
    luaL_checktype(L, 1, LUA_TTABLE);

    if (!luaL_getmetafield(L, 1, "wrapped_ptr"))
        throw Exception(QString("Internal error in %1: No meta table found.").arg(sFunName).toAscii());

    void *pTable = lua_touserdata(L, -1);
    lua_pop(L, 1);

    if (pTable==NULL)
        throw Exception(QString("Internal error in %1: No meta table found.").arg(sFunName).toAscii());

    return pTable;
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
        return 0;
    }
    else
    {

        return 0;
    }
}

//-----------------------------------------------------------------------------
int ILuaTable::__call(lua_State *L)
{
    int argc = lua_gettop(L);
    ILuaTable *pLuaTable = getTableFromStack(L, -argc);

    if (pLuaTable!=NULL)
    {
        return pLuaTable->create(L);
    }
    else
    {
        lua_ex::error(L, "This lua table has no constructor.");
        return 0;
    }
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

    // Einsprungpunkt für Lua Konstruktor
    lua_pushstring(pState, "__call");
    lua_pushcfunction(pState, ILuaTable::__call);
    lua_settable(pState, -3);

    // store pointer to this as light userdata
    lua_pushstring(pState, "this_ptr");
    lua_pushlightuserdata(pState, (void*)this);
    lua_settable(pState, -3);

    lua_setmetatable(pState, -2);

    lua_setglobal(pState, getName());
}

//-------------------------------------------------------------------------------------------------
int ILuaTable::create(lua_State *L)

{
    // Nichts machen, abgeleitete Klassen können hier
    // ihren lua Konstruktor implementieren
    return 0;
}
