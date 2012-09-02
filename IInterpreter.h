#ifndef IINTERPRETER_H
#define IINTERPRETER_H

//--- Qt lib includes -----------------------------------------------------------------------------
#include <QString>

//-------------------------------------------------------------------------------------------------
class IInterpreter
{
public:
    virtual void execute(const QString &sCmd) = 0;
};

#endif // IINTERPRETER_H
