#ifndef IGETSTATECOMMAND_H
#define IGETSTATECOMMAND_H

#include "ICommand.h"
#include "IState.h"

class IGetStateCommand : public ICommand {
public:
    virtual ~IGetStateCommand() {};

    IState* state;

    virtual void execute() = 0;
};
#endif