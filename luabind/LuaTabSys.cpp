#include "LuaTabSys.h"

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

#include "ILuaAction.h"
#include "ISyncContext.h"


using namespace std;

LuaTabSys::ActMessageBox LuaTabSys::actMessageBox;

//-------------------------------------------------------------------------------------------------
LuaTabSys::ActMessageBox::ActMessageBox()
    :IAction(IAction::SYNC)
    ,text(NULL)
    ,subtext(NULL)
    ,buttons(QMessageBox::Ok)
    ,result(QMessageBox::NoButton)
{}

//-------------------------------------------------------------------------------------------------
void LuaTabSys::ActMessageBox::execute_impl()
{
    if (text!=NULL)
    {
        QMessageBox msgBox;
        msgBox.setText(text);

        if (subtext!=NULL)
            msgBox.setInformativeText(subtext);

        result = static_cast<QMessageBox::StandardButton>(msgBox.exec());
    }
}

//-------------------------------------------------------------------------------------------------
LuaTabSys::LuaTabSys()
    :ILuaTable()
{}

//-------------------------------------------------------------------------------------------------
const ILuaTable::SProperty* LuaTabSys::getProperties() const
{
    static const SProperty prop[] =
                    {
                        { "time",     LuaTabSys::prop_time_read,  NULL },
                        { "time_str", LuaTabSys::prop_time_str_read, NULL },
                        { "client",   LuaTabSys::prop_client_name_read, NULL },
                        { NULL, NULL, NULL }
                    };

    return prop;
}

//-------------------------------------------------------------------------------------------------
const ILuaTable::SFunction* LuaTabSys::getFunctions() const
{
    static const SFunction func[] =
                    {
                        { "delay",  LuaTabSys::func_delay },
                        { "msgbox", LuaTabSys::func_msgbox },
                        { NULL, NULL }
                    };

    return func;
}

//-------------------------------------------------------------------------------------------------
const char* LuaTabSys::getName() const
{
    return "sys";
}

//-------------------------------------------------------------------------------------------------
QString LuaTabSys::toString() const
{
    return "sys";
}

//-------------------------------------------------------------------------------------------------
int LuaTabSys::prop_time_read(lua_State *L)
{
    double ms = QDateTime::currentMSecsSinceEpoch();
    lua_pushnumber(L, ms / 1000.0);
    return 1;
}

//-------------------------------------------------------------------------------------------------
int LuaTabSys::prop_time_str_read(lua_State *L)
{
    char str[256];
    time_t t;

    time(&t);
    strftime(str, sizeof(str), "%H:%M:%S %Y-%m-%d", localtime(&t));

    lua_pushstring(L, str);
    return 1;
}

//-------------------------------------------------------------------------------------------------
int LuaTabSys::prop_client_name_read(lua_State *L)
{
    lua_pushstring(L, "InstantLua");
    return 1;
}

//-----------------------------------------------------------------------------
int LuaTabSys::func_msgbox(lua_State *L)
{
    // execute the action in the main thread
    if (ILuaTable::s_pSyncContext!=NULL)
    {
        actMessageBox.text    = luaL_checklstring(L, 1, NULL);
        actMessageBox.subtext = luaL_checklstring(L, 2, NULL);
        ILuaTable::s_pSyncContext->doAction(&actMessageBox);

        int nResult = (int)actMessageBox.result;

        // todo: push to stack for the lua script to deal with...
    }

    return 0;
}

//-----------------------------------------------------------------------------
int LuaTabSys::func_delay(lua_State *L)
{
    lua_Number sec = luaL_checknumber(L, 1);

    if (sec > 0)
    {
        unsigned long dly = (unsigned long)(sec * 1000.0);

        while ((dly > 0) && !L->stop_now)
        {
            if (dly > 1000)
            {
                MyThread::msleep(1000);
                dly -= 1000;
            }
            else
            {
                MyThread::msleep(dly);
                dly = 0;
            }
        }
  }

  return 0;
}
