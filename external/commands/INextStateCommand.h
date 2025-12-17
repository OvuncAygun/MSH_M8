#ifndef INEXTSTATECOMMAND_H
#define INEXTSTATECOMMAND_H

#include "ICommand.h"

class INextStateCommand : public ICommand {
public:
    virtual ~INextStateCommand() = 0;

    virtual void execute() = 0;
};
#endif 