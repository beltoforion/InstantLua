#include "LuaExtensions.h"

//--- Standard includes --------------------------------------------------------------------------
#include <cstdlib>

//--- QT includes ---------------------------------------------------------------------------------
#include <QDebug>

#include "lauxlib.h"


using namespace std;


namespace lua_ex
{
    //---------------------------------------------------------------------------------------------
    void error(lua_State *L, const char *fmt, ...)
    {
      static char err_msg[4096];
      va_list     ap;

      luaL_where(L, 1);

      va_start(ap, fmt);
      vsprintf(err_msg, fmt, ap);
      va_end(ap);

      lua_pushstring(L, err_msg);

      lua_concat(L, 2);
      lua_error(L);
    }

    //---------------------------------------------------------------------------------------------
    void stackDump(lua_State *L)
    {
        int i;
        int top = lua_gettop(L);
        for (i = 1; i <= top; i++)
        {
          /* repeat for each level */
          int t = lua_type(L, i);
          switch (t)
          {
            case LUA_TSTRING:  /* strings */
              qDebug("`%s'", lua_tostring(L, i));
              break;

            case LUA_TBOOLEAN:  /* booleans */
              qDebug(lua_toboolean(L, i) ? "true" : "false");
              break;

            case LUA_TNUMBER:  /* numbers */
              printf("%g", lua_tonumber(L, i));
              break;

            default:  /* other values */
              qDebug("%s", lua_typename(L, t));
              break;

          }
          qDebug("  ");  /* put a separator */
        }
        qDebug("\n");  /* end the listing */
    }
}
