#ifndef IACTION_H
#define IACTION_H

//-------------------------------------------------------------------------------------------------
class IAction
{
public:
    IAction();
    virtual ~IAction();
    virtual int execute() = 0;
};

#endif // IACTION_H
