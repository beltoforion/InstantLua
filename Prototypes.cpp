#include "Prototypes.h"

//-------------------------------------------------------------------------------------------------
#include "Exceptions.h"


//-------------------------------------------------------------------------------------------------
//
//
// class LanguageToken
//
//
//-------------------------------------------------------------------------------------------------

LanguageToken::LanguageToken(const QString& sName)
    :m_vChilds()
    ,m_sName(sName)
    ,m_pParent(NULL)
{}

//-------------------------------------------------------------------------------------------------
LanguageToken::LanguageToken(LanguageToken *pParent,
                             const QString& sName)
    :m_vChilds()
    ,m_sName(sName)
    ,m_pParent(NULL)
{
    if (pParent!=NULL)
    {
//        pParent->addChild();
    }
}

//-------------------------------------------------------------------------------------------------
LanguageToken::~LanguageToken()
{
    for (int i=0; i<m_vChilds.size(); ++i)
    {
        LanguageToken *pToken = m_vChilds[i];
        delete pToken;
    }

    m_vChilds.clear();
}

//-------------------------------------------------------------------------------------------------
const QString& LanguageToken::getName() const
{
    return m_sName;
}

//-------------------------------------------------------------------------------------------------
void LanguageToken::setParent(LanguageToken *pToken)
{
    if (m_pParent!=NULL)
        m_pParent->remove(this);

    m_pParent = pToken;
}

//-------------------------------------------------------------------------------------------------
LanguageToken* LanguageToken::getParent()
{
    return m_pParent;
}

//-------------------------------------------------------------------------------------------------
const LanguageToken* LanguageToken::getParent() const
{
    return m_pParent;
}

//-------------------------------------------------------------------------------------------------
void LanguageToken::setLine(int nLine)
{
    m_nLine = nLine;
}

//-------------------------------------------------------------------------------------------------
int LanguageToken::getLine() const
{
    return m_nLine;
}

//-------------------------------------------------------------------------------------------------
void LanguageToken::add(LanguageToken *pToken)
{
    if (pToken==NULL || m_vChilds.indexOf(pToken)==-1)
        return;

    LanguageToken *pParent = pToken->getParent();
    if (pParent!=NULL)
        throw InternalError("Token already has another parent.");

    pToken->setParent(this);
    m_vChilds.push_back(pToken);
}

//-------------------------------------------------------------------------------------------------
void LanguageToken::remove(LanguageToken *pToken)
{
    if (pToken==NULL)
        return;

    int n = m_vChilds.indexOf(pToken);
    if (n!=-1)
    {
        m_vChilds.remove(n);
        delete pToken;
    }
}

//-------------------------------------------------------------------------------------------------
//
//
// class Script
//
//
//-------------------------------------------------------------------------------------------------

Script::Script(const QString &sName)
    :LanguageToken(sName)
{}

//-------------------------------------------------------------------------------------------------
//
//
// class LanguageToken
//
//
//-------------------------------------------------------------------------------------------------

ClassDefinition::ClassDefinition(LanguageToken *pParent,
                                 const QString &sName)
    :LanguageToken(pParent, sName)
{}

//-------------------------------------------------------------------------------------------------
//
//
// class FunctionDefinition
//
//
//-------------------------------------------------------------------------------------------------

FunctionDefinition::FunctionDefinition(LanguageToken *pParent,
                                       const QString &sName,
                                       const QString &sArgs)
    :LanguageToken(pParent, sName)
    ,m_sArgs(sArgs)
{}
