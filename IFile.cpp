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
    if (!hasObservers())
        return;

//    bool bOld = m_bModified;
    m_bModified = bStat;

//    if (bOld!=m_bModified)
    {
        // Meldung �ber �nderung am File an alle Observer absetzen
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
void IFile::activate() const
{
    if (!hasObservers())
        return;

    obs_list::const_iterator it = m_observer.begin();
    for ( ; it!=m_observer.end(); ++it)
    {
        (*it)->notifyFileActivate(this);
    }
}


//-------------------------------------------------------------------------------------------------
/** \brief Anzeigen und gegebenenfalls markieren einer bestimmten Zeile.
*/
void IFile::navigateToLine(int nLine, ETextMarker eMarker) const
{
    if (!hasObservers())
        return;

    obs_list::const_iterator it = m_observer.begin();
    for ( ; it!=m_observer.end(); ++it)
    {
        (*it)->notifyFileLineSelected(this, nLine, eMarker);
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
    if (!hasObservers())
        return;

    obs_list::iterator it = m_observer.begin();
    for ( ; it!=m_observer.end(); ++it)
    {
        (*it)->notifyBeforeFileSave(this);
    }

    saveImpl();
    m_bModified = false;
}
