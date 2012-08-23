#ifndef IPROJECT_H
#define IPROJECT_H

#include "Types.h"

//-------------------------------------------------------------------------------------------------
/** \brief Eine Klasse, die ein Projekt repräsentiert.

  Projekte bestehen aus mindestens einem Lua file, die alle in Lua geladen werden
  müssen, da sie wechselseitige referenzen enthalten.
*/
class IProject
{
public:
    IProject();
    virtual ~IProject();

    virtual void AddFile(const string_type &sFileName) = 0;
    virtual void DeleteFile(const string_type &sFileName) = 0;
    virtual void Open(const string_type &sProject) = 0;
    virtual string_type GetName() const = 0;
};

#endif // IPROJECT_H
