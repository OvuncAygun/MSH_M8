#ifndef INEXTSTATECOMMAND_H
#define INEXTSTATECOMMAND_H

#include "ICommand.h"

class INextStateCommand : public ICommand {
public:
    virtual ~INextStateCommand() {};

    virtual void execute() = 0;
};
#endif 