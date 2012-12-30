#ifndef LUAEXTENSIONS_H
#define LUAEXTENSIONS_H

#include "lua.h"


namespace lua_ex
{
    void stackDump(lua_State *pState);
    void error(lua_State *lua, const char *fmt, ...);
}

#endif // LUAEXTENSIONS_H
