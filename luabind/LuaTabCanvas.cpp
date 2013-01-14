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
#include "Exceptions.h"


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
TRY
{
    LuaTabCanvas *pTable = (LuaTabCanvas*)checkArguments(L, 3, "Canvas:moveTo(x, y)");

    struct ActMoveTo : IAction
    {
        virtual void execute_impl()
        {
            if (canvas!=NULL)
                canvas->moveTo(x, y);
        }

        WndCanvas *canvas;
        double x;
        double y;
    } static actMoveTo;

    actMoveTo.canvas = pTable->m_pCanvas;
    actMoveTo.x = luaL_checknumber(L, 2);
    actMoveTo.y = luaL_checknumber(L, 3);
    ILuaTable::s_pSyncContext->doAction(&actMoveTo);

    return 0;
}
CATCH

//-------------------------------------------------------------------------------------------------
int LuaTabCanvas::drawTo(lua_State *L)
TRY
{
    LuaTabCanvas *pTable = (LuaTabCanvas*)checkArguments(L, 3, "Canvas:drawTo(x, y)");

    struct ActDrawTo : IAction
    {
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
CATCH

//-------------------------------------------------------------------------------------------------
int LuaTabCanvas::drawEllipse(lua_State *L)
TRY
{
    LuaTabCanvas *pTable = (LuaTabCanvas*)checkArguments(L, 5, "Canvas:drawEllipse(x, y)");

    struct ActDrawEllipse : IAction
    {
        virtual void execute_impl()
        {
            if (canvas)
                canvas->drawEllipse(x1, y1, x2, y2);
        }

        double x1, y1, x2, y2;
        WndCanvas *canvas;
    } static actDrawEllipse;

    actDrawEllipse.canvas = pTable->m_pCanvas;
    actDrawEllipse.x1 = luaL_checknumber(L, 2);
    actDrawEllipse.y1 = luaL_checknumber(L, 3);
    actDrawEllipse.x2 = luaL_checknumber(L, 4);
    actDrawEllipse.y2 = luaL_checknumber(L, 5);
    ILuaTable::s_pSyncContext->doAction(&actDrawEllipse);

    return 0;
}
CATCH

//-------------------------------------------------------------------------------------------------
int LuaTabCanvas::drawCircle(lua_State *L)
TRY
{
    LuaTabCanvas *pTable = (LuaTabCanvas*)checkArguments(L, 4, "Canvas:drawCircle(x, y, r)");

    struct ActDrawCicrle : IAction
    {
        virtual void execute_impl()
        {
            if (canvas)
                canvas->drawCircle(x, y, r);
        }

        double x, y, r;
        WndCanvas *canvas;
    } static actDrawCircle;

    actDrawCircle.canvas = pTable->m_pCanvas;
    actDrawCircle.x = luaL_checknumber(L, 2);
    actDrawCircle.y = luaL_checknumber(L, 3);
    actDrawCircle.r = luaL_checknumber(L, 4);
    ILuaTable::s_pSyncContext->doAction(&actDrawCircle);

    return 0;
}
CATCH

//-------------------------------------------------------------------------------------------------
int LuaTabCanvas::drawPoint(lua_State *L)
TRY
{
    LuaTabCanvas *pTable = (LuaTabCanvas*)checkArguments(L, 3, "Canvas:drawPoint(x, y)");

    struct ActDrawPoint : IAction
    {
        virtual void execute_impl()
        {
            if (canvas)
                canvas->drawPoint(x, y);
        }

        double x, y;
        WndCanvas *canvas;
    } static actDrawPoint;

    actDrawPoint.canvas = pTable->m_pCanvas;
    actDrawPoint.x = luaL_checknumber(L, 2);
    actDrawPoint.y = luaL_checknumber(L, 3);
    ILuaTable::s_pSyncContext->doAction(&actDrawPoint);

    return 0;
}
CATCH

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

    lua_pushcfunction(L, LuaTabCanvas::drawEllipse);
    lua_setfield(L, -2, "drawEllipse");

    lua_pushcfunction(L, LuaTabCanvas::drawCircle);
    lua_setfield(L, -2, "drawCircle");

    lua_pushcfunction(L, LuaTabCanvas::drawPoint);
    lua_setfield(L, -2, "drawPoint");

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


