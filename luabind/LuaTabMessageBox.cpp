#include "LuaTabMessageBox.h"

//--- Standard includes ---------------------------------------------------------------------------
#include <ctime>
#include <cassert>

//--- QT Lib includes -----------------------------------------------------------------------------
#include <QDateTime>
#include <QThread>
#include <QMessageBox>

//--- Lua includes --------------------------------------------------------------------------------
#include "lstate.h"
#include "lauxlib.h"

#include "LuaExtensions.h"
#include "ILuaAction.h"
#include "ISyncContext.h"


using namespace std;

LuaTabMessageBox::ActShow LuaTabMessageBox::actShow;

//-------------------------------------------------------------------------------------------------
LuaTabMessageBox::ActShow::ActShow()
    :IAction(IAction::SYNC)
    ,text("")
    ,detailed_text("")
    ,msgbox(NULL)
{}

//-------------------------------------------------------------------------------------------------
void LuaTabMessageBox::ActShow::execute_impl()
{
    if (msgbox!=NULL)
    {
        msgbox->setText(text);
        msgbox->setDetailedText(detailed_text);
        msgbox->exec();
    }
}

//-------------------------------------------------------------------------------------------------
//  LuaTabMessageBox::ActCreate
//-------------------------------------------------------------------------------------------------

LuaTabMessageBox::ActCreate LuaTabMessageBox::actCreate;

//-------------------------------------------------------------------------------------------------
LuaTabMessageBox::ActCreate::ActCreate()
    :IAction(IAction::SYNC)
{}

//-------------------------------------------------------------------------------------------------
void LuaTabMessageBox::ActCreate::execute_impl()
{
    msgbox = new QMessageBox;
}

//-------------------------------------------------------------------------------------------------
//  LuaTabMessageBox::ActDelete
//-------------------------------------------------------------------------------------------------

LuaTabMessageBox::ActDelete LuaTabMessageBox::actDelete;

//-------------------------------------------------------------------------------------------------
LuaTabMessageBox::ActDelete::ActDelete()
    :IAction(IAction::SYNC)
    ,msgbox(NULL)
{}

//-------------------------------------------------------------------------------------------------
void LuaTabMessageBox::ActDelete::execute_impl()
{
    delete msgbox;
    msgbox = NULL;
}

//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------

LuaTabMessageBox::LuaTabMessageBox()
    :ILuaTable()
    ,m_pMessageBox(NULL)
{}

//-------------------------------------------------------------------------------------------------
const ILuaTable::SProperty* LuaTabMessageBox::getProperties() const
{
    static const SProperty prop[] =
                    {
                        { NULL, NULL, NULL }
                    };

    return prop;
}

//-------------------------------------------------------------------------------------------------
const ILuaTable::SFunction* LuaTabMessageBox::getFunctions() const
{
    static const SFunction func[] =
                    {
                        { NULL, NULL }
                    };

    return func;
}

//-------------------------------------------------------------------------------------------------
const char* LuaTabMessageBox::getName() const
{
    return "MessageBox";
}

//-------------------------------------------------------------------------------------------------
QString LuaTabMessageBox::toString() const
{
    return "MessageBox";
}

//-------------------------------------------------------------------------------------------------
int LuaTabMessageBox::show(lua_State *L)
{
    int argc = lua_gettop(L);
    if (argc!=1)
        return luaL_error(L, "Error in MessageBox.show(): Invalid number of arguments.");

    // Parameter 1 muss eine Lua Tabelle sein
    luaL_checktype(L, 1, LUA_TTABLE);



    if (luaL_getmetafield(L, 1, "this_ptr"))
    {
        LuaTabMessageBox *pTable = (LuaTabMessageBox*)lua_touserdata(L, -1);
        lua_pop(L, 1);

        if (pTable==NULL)
            return luaL_error(L, "Internal error in LuaTabMessageBox::show(...): No MessageBox object found on the stack");

        lua_getfield(L, 1, "text");
        actShow.text = luaL_checkstring(L, -1);
        lua_pop(L, 1);

        lua_getfield(L, 1, "detailed_text");
        actShow.detailed_text = luaL_checkstring(L, -1);
        lua_pop(L, 1);

        actShow.msgbox = pTable->m_pMessageBox;
        ILuaTable::s_pSyncContext->doAction(&actShow);
    }
    else
    {
        return luaL_error(L, "Internal error in LuaTabMessageBox::show(...): No meta table found.");
    }

    return 0;
}

//-------------------------------------------------------------------------------------------------
int LuaTabMessageBox::create(lua_State *L)
{
    int argc = lua_gettop(L);
    const char *szText = "";
    const char *szDetailedText  = "";

    if (ILuaTable::s_pSyncContext==NULL)
        return luaL_error(L, "Internal error in LuaTabMessageBox::create no synchronization context!");

    if (argc==1)
        return luaL_error(L, "MessageBox(...) at least one argument required for object construction (got %d).", argc-1);

    if (argc>3)
        return luaL_error(L, "MessageBox(...) too many arguments.");

    // Hinweis: Auf stack platz 1 liegt die Tabelle!

    szText = luaL_checkstring(L, 2);

    // SubText ist optional
    if (argc==3)
      szDetailedText = luaL_checkstring(L, 3);


    lua_newtable(L);

    lua_pushstring(L, szText);
    lua_setfield(L, -2, "text");

    lua_pushstring(L, szDetailedText);
    lua_setfield(L, -2, "detailed_text");

    lua_pushcfunction(L, show);
    lua_setfield(L, -2, "show");

    // Metatabelle eintrichten und this_ptr darin abspeichern
    lua_newtable(L);

    lua_pushstring(L, "this_ptr");
    lua_pushlightuserdata(L, (void*)this);

    lua_settable(L, -3);

    lua_setmetatable(L, -2);


    // Anlegen bzw. Zerstören der Messagebox geht nur im Hauptthread!
    if (m_pMessageBox!=NULL)
    {
        actDelete.msgbox = m_pMessageBox;
        ILuaTable::s_pSyncContext->doAction(&actDelete);
    }

    ILuaTable::s_pSyncContext->doAction(&actCreate);
    m_pMessageBox = actCreate.msgbox;

    return 1;
}


