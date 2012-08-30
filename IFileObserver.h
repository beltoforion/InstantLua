#ifndef IFILEOBSERVER_H
#define IFILEOBSERVER_H

#include "FwdDecl.h"

//-------------------------------------------------------------------------------------------------
class IFileObserver
{
public:
    virtual void notifyFileActivate(const IFile *pFile) = 0;
    virtual void notifyFileLoad(const IFile *pFile) = 0;
    virtual void notifyBeforeFileSave(IFile *pFile) = 0;
    virtual void notifyFileModified(const IFile *pFile) = 0;
    virtual void notifyFileLineSelected(const IFile *pFile, int nLine) = 0;
};

#endif // IFILEOBSERVER_H
