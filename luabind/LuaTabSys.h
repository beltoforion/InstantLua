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

    struct MyThread : QThread
    {
      using QThread::msleep;
    };

    //---------------------------------------------------------------------------------------------
    // Aktionen für Qt Lib funktionen, die im Hauptthread ausgeführt werden müssen
    //---------------------------------------------------------------------------------------------

    struct ActMessageBox : IAction
    {
        ActMessageBox();
        virtual void execute_impl();
        const char *msg;
    } static actMessageBox;

    //---------------------------------------------------------------------------------------------
    // Lua function callbacks
    //---------------------------------------------------------------------------------------------

    static int func_delay(lua_State *L);
    static int func_msgbox(lua_State *L);

    //---------------------------------------------------------------------------------------------
    // Lua Property callbacks
    //---------------------------------------------------------------------------------------------

    static int prop_time_read(lua_State *L);
    static int prop_time_str_read(lua_State *L);
    static int prop_client_name_read(lua_State *L);
};


#endif // LUATABSYS_H
