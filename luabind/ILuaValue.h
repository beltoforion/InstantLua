#ifndef ILUA_VALUE_H
#define ILUA_VALUE_H

extern "C"
{
#include "lua.h"
#include "lualib.h"
}

//-------------------------------------------------------------------------------------------------
class ILuaValue
{
public:
  ILuaValue();
  virtual ~ILuaValue();
  virtual void Push(lua_State *state) const = 0;
  virtual void Pop(lua_State *state) = 0;
};

#endif
