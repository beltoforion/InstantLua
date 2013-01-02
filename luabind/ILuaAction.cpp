#include "ILuaAction.h"

#include <cassert>


//-------------------------------------------------------------------------------------------------
IAction::IAction(EActionType eType)
    :m_mtxAction()
    ,m_eType(eType)
{}

//-------------------------------------------------------------------------------------------------
IAction::~IAction()
{}

//-------------------------------------------------------------------------------------------------
IAction::EActionType IAction::getType() const
{
    return m_eType;
}

//-------------------------------------------------------------------------------------------------
void IAction::execute()
{
    try
    {
        execute_impl();

        if (m_eType==IAction::SYNC)
            m_wait.wakeAll();
    }
    catch(...)
    {
        if (m_eType==IAction::SYNC)
            m_wait.wakeAll();

        throw;
    }
}

//-------------------------------------------------------------------------------------------------
void IAction::wait()
{
    m_wait.wait(&m_mtxAction);
}

//-------------------------------------------------------------------------------------------------
// ActionWaiter
//-------------------------------------------------------------------------------------------------

ActionWaiter::ActionWaiter(IAction *pAction)
    :m_pAction(pAction)
{
    assert(m_pAction!=NULL);
    m_pAction->m_mtxAction.lock();
}

//-------------------------------------------------------------------------------------------------
ActionWaiter::~ActionWaiter()
{
    m_pAction->m_wait.wait(&m_pAction->m_mtxAction);
    m_pAction->m_mtxAction.unlock();
}
