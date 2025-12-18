#ifndef ICHANGESTATECOMMAND_H
#define ICHANGESTATECOMMAND_H

#include "ICommand.h"
#include "IState.h"

class IChangeStateCommand : public ICommand {
public:
    virtual ~IChangeStateCommand() {};

    IState* state;

    virtual void execute() = 0;
};
#endif 