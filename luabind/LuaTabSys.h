#ifndef LUATABSYS_H
#define LUATABSYS_H

//--- Qt includes ---------------------------------------------------------------------------------
#include <QThread>

#include "ILuaTable.h"


//-------------------------------------------------------------------------------------------------
class LuaTabSys : public ILuaTable
{
public:
    LuaTabSys();

    virtual const SProperty* getProperties() const;
    virtual const SFunction* getFunctions() const;
    virtual const char* getName() const;
    virtual QString toString() const;

private:

    struct QThreadDelay : QThread
    {
      using QThread::msleep;
    };

    //---------------------------------------------------------------------------------------------
    // Lua function callbacks
    //---------------------------------------------------------------------------------------------

    static int func_delay(lua_State *L);

    //---------------------------------------------------------------------------------------------
    // Lua Property callbacks
    //---------------------------------------------------------------------------------------------

    static int prop_time_read(lua_State *L);
    static int prop_time_str_read(lua_State *L);
};


#endif // LUATABSYS_H
