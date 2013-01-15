#ifndef LUATAB_CANVAS_BOX_H
#define LUATAB_CANVAS_BOX_H

//--- Qt includes ---------------------------------------------------------------------------------
#include <QThread>
#include <QMessageBox>

//-------------------------------------------------------------------------------------------------
#include "ILuaTable.h"
#include "WndCanvas.h"


//-------------------------------------------------------------------------------------------------
class LuaTabCanvas : public ILuaTable
{
public:
    LuaTabCanvas();

    virtual const SProperty* getProperties() const;
    virtual const SFunction* getFunctions() const;
    virtual const char* getName() const;
    virtual QString toString() const;
    virtual int create(lua_State *L);

private:

    //---------------------------------------------------------------------------------------------
    // Aktionen für Qt Lib funktionen, die im Hauptthread ausgeführt werden müssen
    //---------------------------------------------------------------------------------------------

    //---------------------------------------------------------------------------------------------
    struct ActDelete : IAction
    {
        ActDelete();
        virtual void execute_impl();
        WndCanvas *canvas;
    } static actDelete;

    //---------------------------------------------------------------------------------------------
    // Lua function callbacks
    //---------------------------------------------------------------------------------------------

    static int moveTo(lua_State *L);
    static int drawTo(lua_State *L);
    static int drawEllipse(lua_State *L);
    static int drawCircle(lua_State *L);
    static int drawPoint(lua_State *L);

    //---------------------------------------------------------------------------------------------
    // Lua Property callbacks
    //---------------------------------------------------------------------------------------------
};


#endif // LUATAB_CANVAS_H
