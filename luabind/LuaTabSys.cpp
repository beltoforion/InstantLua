#include "LuaTabSys.h"
#include <QDateTime>
#include <QThread>
#include <ctime>

//#include "lua.h"
#include "lstate.h"
#include "lauxlib.h"

using namespace std;


//-------------------------------------------------------------------------------------------------
LuaTabSys::LuaTabSys()
{
}

//-------------------------------------------------------------------------------------------------
const ILuaTable::SProperty* LuaTabSys::getProperties() const
{
    static const SProperty prop[] =
                    {
                        { "time",     LuaTabSys::prop_time_read,  NULL },
                        { "time_str", LuaTabSys::prop_time_str_read, NULL },
                        { NULL, NULL, NULL }
                    };

    return prop;
}

//-------------------------------------------------------------------------------------------------
const ILuaTable::SFunction* LuaTabSys::getFunctions() const
{
    static const SFunction func[] =
                    {
                        { "delay", LuaTabSys::func_delay },
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
    char    str[64];
    time_t  t;

    time(&t);
    strftime(str, sizeof(str), "%H:%M:%S %Y-%m-%d", localtime(&t));

    lua_pushstring(L, str);
    return 1;
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
                QThreadDelay::msleep(1000);
                dly -= 1000;
            }
            else
            {
                QThreadDelay::msleep(dly);
                dly = 0;
            }
        }
  }

  return 0;
}
