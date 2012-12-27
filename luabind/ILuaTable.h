#ifndef ILUA_TABLE_H
#define ILUA_TABLE_H

//-------------------------------------------------------------------------------------------------
#include <QString>
#include <QVector>

//--- LUA includes --------------------------------------------------------------------------------
//#include "lauxlib.h"
#include "lualib.h"
//#include "lua.h"


//-------------------------------------------------------------------------------------------------
class ILuaTable
{
public:
    ILuaTable(const QString &sName);
    virtual ~ILuaTable();

    void addToLua(lua_State *pState);

    const QString& getName() const;

protected:

    struct SProperty
    {
        QString name;
        lua_CFunction read;
        lua_CFunction write;
    };

    struct SFunction
    {
        QString name;
        lua_CFunction ptr;
    };

    void addFunc(const QString &sFuncName,lua_CFunction ptrFun);
    void addProperty(const QString &sPropName, lua_CFunction funcRead, lua_CFunction funcWrite);
    void addInteger(const QString &sName);
    void addDouble(const QString &sName);

private:
    QString m_sName;
    QVector<SProperty> m_vProperties;
    QVector<SFunction> m_vFunctions;

};

#endif
