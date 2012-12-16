#ifndef LUA_SYS_VAR_H
#define LUA_SYS_VAR_H

//--- Standard includes ---------------------------------------------------------------------------
#include "ILuaValue.h"


//-------------------------------------------------------------------------------------------------
class LuaSysVar : public ILuaValue
{
public:

    struct SSysVar
    {
        volatile int m_bRunning;
    };

    LuaSysVar();
    virtual ~LuaSysVar();

    virtual void Push(lua_State *state) const;
    virtual void Pop(lua_State *state);

    SSysVar m_data;
};

#endif
