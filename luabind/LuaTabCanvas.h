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

    WndCanvas *m_pCanvas;

    //---------------------------------------------------------------------------------------------
    // Aktionen für Qt Lib funktionen, die im Hauptthread ausgeführt werden müssen
    //---------------------------------------------------------------------------------------------

    struct ActShow : IAction
    {
        ActShow();
        virtual void execute_impl();
        const char *text;
        const char *detailed_text;
        WndCanvas *canvas;
    } static actShow;

    //---------------------------------------------------------------------------------------------
    struct ActCreate : IAction
    {
        ActCreate();
        virtual void execute_impl();
        WndCanvas *canvas;
        int width;
        int height;
        QString title;
    } static actCreate;

    //---------------------------------------------------------------------------------------------
    struct ActDelete : IAction
    {
        ActDelete();
        virtual void execute_impl();
        WndCanvas *canvas;
    } static actDelete;

    //---------------------------------------------------------------------------------------------
    struct ActMoveTo : IAction
    {
        ActMoveTo();
        virtual void execute_impl();
        WndCanvas *canvas;
        double x;
        double y;
    } static actMoveTo;

    //---------------------------------------------------------------------------------------------
    // Lua function callbacks
    //---------------------------------------------------------------------------------------------

    static int moveTo(lua_State *L);
    static int drawTo(lua_State *L);

    //---------------------------------------------------------------------------------------------
    // Lua Property callbacks
    //---------------------------------------------------------------------------------------------
};


#endif // LUATAB_CANVAS_H
