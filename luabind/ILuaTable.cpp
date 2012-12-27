#include "ILuaTable.h"


//-------------------------------------------------------------------------------------------------
ILuaTable::ILuaTable(const QString &sTabName)
    :m_sName(sTabName)
    ,m_vProperties()
    ,m_vFunctions()
{}

//-------------------------------------------------------------------------------------------------
ILuaTable::~ILuaTable()
{}

//-------------------------------------------------------------------------------------------------
void ILuaTable::addToLua(lua_State *pState)
{
    if (pState==NULL)
        return;
/*
    lua_newtable(pState);
    lua_pushstring(pState, "__index");

    // add functions
    for (int i=0; i<m_vFunctions.size(); ++i)
    {
        const SFunction func = m_vFunctions[i];
        lua_pushcfunction(pState, func.ptr);
        lua_setfield(pState, -2, func.name.toAscii());
    }

    // add properties
    for (int i=0; i<m_vProperties.size(); ++i)
    {

    }
*/
}

//-------------------------------------------------------------------------------------------------
void ILuaTable::addProperty(const QString &name, lua_CFunction read, lua_CFunction write)
{
    SProperty prop;
    prop.name  = name;
    prop.read  = read;
    prop.write = write;
    m_vProperties.push_back(prop);
}

//-------------------------------------------------------------------------------------------------
void ILuaTable::addFunc(const QString &name,lua_CFunction ptr)
{
    SFunction func;
    func.name = name;
    func.ptr = ptr;
    m_vFunctions.push_back(func);
}

//-------------------------------------------------------------------------------------------------
void ILuaTable::addInteger(const QString &sName)
{
}

//-------------------------------------------------------------------------------------------------
void ILuaTable::addDouble(const QString &sName)
{
}

//-------------------------------------------------------------------------------------------------
const QString& ILuaTable::getName() const
{
    return m_sName;
}

