#ifndef IFILEOBSERVER_H
#define IFILEOBSERVER_H

#include "fwddecl.h"

//-------------------------------------------------------------------------------------------------
class IFileObserver
{
public:
    virtual void notifyFileActivate(const IFile *pFile) = 0;
    virtual void notifyFileLoad(const IFile *pFile) = 0;
    virtual void notifyBeforeFileSave(IFile *pFile) = 0;
    virtual void notifyFileModified(const IFile *pFile) = 0;
};

#endif // IFILEOBSERVER_H
