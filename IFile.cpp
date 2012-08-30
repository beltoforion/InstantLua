#include "IFile.h"

//-------------------------------------------------------------------------------------------------
IFile::IFile()
    :m_vObserver()
    ,m_bModified(false)
{}

//-------------------------------------------------------------------------------------------------
IFile::~IFile()
{}

//-------------------------------------------------------------------------------------------------
void IFile::setModified(bool bStat)
{
    bool bOld = m_bModified;
    m_bModified = bStat;

    if (bOld!=m_bModified && hasObservers())
    {
        // Meldung über Änderung am File an alle Observer absetzen
        obs_list::iterator it = m_observer.begin();
        for (; it!=m_observer.end(); ++it)
        {
            (*it)->notifyFileModified(this);
        }
    }
}

//-------------------------------------------------------------------------------------------------
bool IFile::wasModified() const
{
    return m_bModified;
}

//-------------------------------------------------------------------------------------------------
void IFile::loadImpl()
{}

//-------------------------------------------------------------------------------------------------
void IFile::saveImpl()
{}

//-------------------------------------------------------------------------------------------------
void IFile::activate()
{
    if (hasObservers())
    {
        obs_list::iterator it = m_observer.begin();
        for ( ; it!=m_observer.end(); ++it)
        {
            (*it)->notifyFileActivate(this);
        }
    }
}


//-------------------------------------------------------------------------------------------------
void IFile::navigateToLine(int nLine) const
{
    if (hasObservers())
    {
        obs_list::const_iterator it = m_observer.begin();
        for ( ; it!=m_observer.end(); ++it)
        {
            (*it)->notifyFileLineSelected(this, nLine);
        }
    }
}

//-------------------------------------------------------------------------------------------------
void IFile::load()
{
    loadImpl();

    if (hasObservers())
    {
        obs_list::iterator it = m_observer.begin();
        for ( ; it!=m_observer.end(); ++it)
        {
            (*it)->notifyFileLoad(this);
        }
    }

    m_bModified = false;
}

//-------------------------------------------------------------------------------------------------
void IFile::save()
{
    if (hasObservers())
    {
        obs_list::iterator it = m_observer.begin();
        for ( ; it!=m_observer.end(); ++it)
        {
            (*it)->notifyBeforeFileSave(this);
        }
    }

    saveImpl();
    m_bModified = false;
}
