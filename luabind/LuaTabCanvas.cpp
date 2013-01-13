#include "LuaTabCanvas.h"

//--- Standard includes ---------------------------------------------------------------------------
#include <cassert>

//--- QT Lib includes -----------------------------------------------------------------------------
#include <QMessageBox>

//--- Lua includes --------------------------------------------------------------------------------
#include "lstate.h"
#include "lauxlib.h"

#include "LuaExtensions.h"
#include "ILuaAction.h"
#include "ISyncContext.h"


using namespace std;

LuaTabCanvas::ActShow LuaTabCanvas::actShow;

//-------------------------------------------------------------------------------------------------
LuaTabCanvas::ActShow::ActShow()
    :IAction(IAction::SYNC)
    ,text("")
    ,detailed_text("")
    ,canvas(NULL)
{}

//-------------------------------------------------------------------------------------------------
void LuaTabCanvas::ActShow::execute_impl()
{
    if (canvas!=NULL)
    {
        canvas->show();
    }
}

//-------------------------------------------------------------------------------------------------
//  LuaTabCanvas::ActCreate
//-------------------------------------------------------------------------------------------------

LuaTabCanvas::ActCreate LuaTabCanvas::actCreate;

//-------------------------------------------------------------------------------------------------
LuaTabCanvas::ActCreate::ActCreate()
    :IAction(IAction::SYNC)
    ,canvas(NULL)
    ,width(500)
    ,height(500)
    ,title("Name to be defined")
{}

//-------------------------------------------------------------------------------------------------
void LuaTabCanvas::ActCreate::execute_impl()
{
    canvas = new WndCanvas(width, height, title);
    canvas->show();
}

//-------------------------------------------------------------------------------------------------
//  LuaTabCanvas::ActDelete
//-------------------------------------------------------------------------------------------------

LuaTabCanvas::ActDelete LuaTabCanvas::actDelete;

//-------------------------------------------------------------------------------------------------
LuaTabCanvas::ActDelete::ActDelete()
    :IAction(IAction::SYNC)
    ,canvas(NULL)
{}

//-------------------------------------------------------------------------------------------------
void LuaTabCanvas::ActDelete::execute_impl()
{
    delete canvas;
    canvas = NULL;
}

//-------------------------------------------------------------------------------------------------
//  LuaTabCanvas::ActMoveTo
//-------------------------------------------------------------------------------------------------

LuaTabCanvas::ActMoveTo LuaTabCanvas::actMoveTo;

//-------------------------------------------------------------------------------------------------
LuaTabCanvas::ActMoveTo::ActMoveTo()
    :IAction(IAction::SYNC)
    ,canvas(NULL)
    ,x(0)
    ,y(0)
{}

//-------------------------------------------------------------------------------------------------
void LuaTabCanvas::ActMoveTo::execute_impl()
{
    Q_ASSERT(canvas!=NULL);
    if (canvas==NULL)
        return;

    canvas->moveTo(x, y);
}

//-------------------------------------------------------------------------------------------------
//  class LuaTabCanvas
//-------------------------------------------------------------------------------------------------

LuaTabCanvas::LuaTabCanvas()
    :ILuaTable()
    ,m_pCanvas(NULL)
{}

//-------------------------------------------------------------------------------------------------
const ILuaTable::SProperty* LuaTabCanvas::getProperties() const
{
    static const SProperty prop[] =
                    {
                        { NULL, NULL, NULL }
                    };

    return prop;
}

//-------------------------------------------------------------------------------------------------
const ILuaTable::SFunction* LuaTabCanvas::getFunctions() const
{
    static const SFunction func[] =
                    {
                        { NULL, NULL }
                    };

    return func;
}

//-------------------------------------------------------------------------------------------------
const char* LuaTabCanvas::getName() const
{
    return "Canvas";
}

//-------------------------------------------------------------------------------------------------
QString LuaTabCanvas::toString() const
{
    return "Canvas";
}

//-------------------------------------------------------------------------------------------------
int LuaTabCanvas::moveTo(lua_State *L)
{
    int argc = lua_gettop(L);
    if (argc!=3)
        return luaL_error(L, "Error in Canvas:moveTo(x, y): Invalid number of arguments.");

    // Parameter 1 muss eine Lua Tabelle sein
    luaL_checktype(L, 1, LUA_TTABLE);

    if (!luaL_getmetafield(L, 1, "this_ptr"))
        return luaL_error(L, "Internal error in Canvas:moveTo(x, y): No meta table found.");

    LuaTabCanvas *pTable = (LuaTabCanvas*)lua_touserdata(L, -1);
    lua_pop(L, 1);

    if (pTable==NULL)
        return luaL_error(L, "Internal error in Canvas:moveTo(x, y): No Canvas object found on the stack");

    actMoveTo.canvas = pTable->m_pCanvas;
    actMoveTo.x = luaL_checknumber(L, 2);
    actMoveTo.y = luaL_checknumber(L, 3);
    ILuaTable::s_pSyncContext->doAction(&actMoveTo);

    return 0;
}

//-------------------------------------------------------------------------------------------------
int LuaTabCanvas::drawTo(lua_State *L)
{
    int argc = lua_gettop(L);
    if (argc!=3)
        return luaL_error(L, "Error in Canvas:drawTo(x, y): Invalid number of arguments.");

    // Parameter 1 muss eine Lua Tabelle sein
    luaL_checktype(L, 1, LUA_TTABLE);

    if (!luaL_getmetafield(L, 1, "this_ptr"))
        return luaL_error(L, "Internal error in Canvas:drawTo(x, y): No meta table found.");

    LuaTabCanvas *pTable = (LuaTabCanvas*)lua_touserdata(L, -1);
    lua_pop(L, 1);

    if (pTable==NULL)
        return luaL_error(L, "Internal error in Canvas:drawTo(x, y): No Canvas object found on the stack");

    struct ActDrawTo : IAction
    {
        ActDrawTo()
            :IAction(IAction::SYNC)
        {}

        virtual void execute_impl()
        {
            if (canvas)
                canvas->drawTo(x, y);
        }

        double x, y;
        WndCanvas *canvas;
    } static actDrawTo;

    actDrawTo.canvas = pTable->m_pCanvas;
    actDrawTo.x = luaL_checknumber(L, 2);
    actDrawTo.y = luaL_checknumber(L, 3);
    ILuaTable::s_pSyncContext->doAction(&actDrawTo);

    return 0;
}

//-------------------------------------------------------------------------------------------------
int LuaTabCanvas::create(lua_State *L)
{
    int argc = lua_gettop(L);

    if (ILuaTable::s_pSyncContext==NULL)
        return luaL_error(L, "Internal error in Canvas:create no synchronization context!");

    if (argc!=4)
        return luaL_error(L, "Canvas constructor takes three arguments: Canvas(width, height, title) ");

    // Hinweis: Auf stack platz 1 liegt die Tabelle!
    int width  = luaL_checkinteger(L, 2);
    int height = luaL_checkinteger(L, 3);
    const char *szTitle = luaL_checkstring(L, 4);

    lua_newtable(L);

    lua_pushinteger(L, width);
    lua_setfield(L, -2, "width");

    lua_pushinteger(L, height);
    lua_setfield(L, -2, "height");

    lua_pushstring(L, szTitle);
    lua_setfield(L, -2, "title");

    lua_pushcfunction(L, LuaTabCanvas::moveTo);
    lua_setfield(L, -2, "moveTo");

    lua_pushcfunction(L, LuaTabCanvas::drawTo);
    lua_setfield(L, -2, "drawTo");

    // Metatabelle eintrichten und this_ptr darin abspeichern
    lua_newtable(L);

    lua_pushstring(L, "this_ptr");
    lua_pushlightuserdata(L, (void*)this);

    lua_settable(L, -3);

    lua_setmetatable(L, -2);

    // Anlegen bzw. Zerstören des Graphikfensters
    if (m_pCanvas!=NULL)
    {
        actDelete.canvas = m_pCanvas;
        ILuaTable::s_pSyncContext->doAction(&actDelete);
    }

    actCreate.width = width;
    actCreate.height = height;
    actCreate.title = szTitle;
    ILuaTable::s_pSyncContext->doAction(&actCreate);
    m_pCanvas = actCreate.canvas;

    return 1;
}


