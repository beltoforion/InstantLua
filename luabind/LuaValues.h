#ifndef LUA_VALUES_H
#define LUA_VALUES_H

//--- Standard includes ---------------------------------------------------------------------------
#include <string>

#include "ILuaValue.h"


//-------------------------------------------------------------------------------------------------
class LuaValueInt : public ILuaValue
{
public:
  LuaValueInt(int v);
  virtual void Push(lua_State *state) const;
  virtual void Pop(lua_State *state);

private:
  int m_val;
};

//-------------------------------------------------------------------------------------------------
class LuaValueBool : public ILuaValue
{
public:
  LuaValueBool(bool v);
  virtual void Push(lua_State *state) const;
  virtual void Pop(lua_State *state);

private:
  bool m_val;
};

//-------------------------------------------------------------------------------------------------
class LuaValueString : public ILuaValue
{
public:
  LuaValueString(const std::string &s);
  virtual void Push(lua_State *state) const;
  virtual void Pop(lua_State *state);

private:
  std::string m_val;
};

//-------------------------------------------------------------------------------------------------
class LuaValueDouble : public ILuaValue
{
public:
  LuaValueDouble(double v);
  virtual void Push(lua_State *state) const;
  virtual void Pop(lua_State *state);

private:
  double m_val;
};

//-------------------------------------------------------------------------------------------------
class LuaValueNIL : public ILuaValue
{
public:
  LuaValueNIL();
  virtual void Push(lua_State *state) const;
  virtual void Pop(lua_State *state);
};

#endif
