#ifndef LUATAB_MESSAGE_BOX_H
#define LUATAB_MESSAGE_BOX_H

//--- Qt includes ---------------------------------------------------------------------------------
#include <QThread>
#include <QMessageBox>

#include "ILuaTable.h"


//-------------------------------------------------------------------------------------------------
class LuaTabMessageBox : public ILuaTable
{
public:
    LuaTabMessageBox();

    virtual const SProperty* getProperties() const;
    virtual const SFunction* getFunctions() const;
    virtual const char* getName() const;
    virtual QString toString() const;
    virtual int create(lua_State *L);

private:

    QMessageBox *m_pMessageBox;

    //---------------------------------------------------------------------------------------------
    // Aktionen für Qt Lib funktionen, die im Hauptthread ausgeführt werden müssen
    //---------------------------------------------------------------------------------------------

    struct ActShow : IAction
    {
        ActShow();
        virtual void execute_impl();
        const char *text;
        const char *detailed_text;
        QMessageBox *msgbox;
    } static actShow;

    //---------------------------------------------------------------------------------------------
    struct ActCreate : IAction
    {
        ActCreate();
        virtual void execute_impl();
        QMessageBox *msgbox;
    } static actCreate;

    //---------------------------------------------------------------------------------------------
    struct ActDelete : IAction
    {
        ActDelete();
        virtual void execute_impl();
        QMessageBox *msgbox;
    } static actDelete;

    //---------------------------------------------------------------------------------------------
    // Lua function callbacks
    //---------------------------------------------------------------------------------------------

    static int show(lua_State *L);

    //---------------------------------------------------------------------------------------------
    // Lua Property callbacks
    //---------------------------------------------------------------------------------------------
};


#endif // LUATAB_MESSAGE_BOX_H
