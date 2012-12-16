#ifndef ISCRIPT_ENGINE_H
#define ISCRIPT_ENGINE_H

//-------------------------------------------------------------------------------------------------
#include "FwdDecl.h"


//-------------------------------------------------------------------------------------------------
/** \brief Basisklasse für die Lua engine.
*/
class IScriptEngine
{
public:
    virtual void doSyntaxCheck(const IFile *pFile) = 0;
    virtual void stop() = 0;
};

#endif // ISCRIPT_ENGINE_H
