#ifndef IPREVIOUSSTATECOMMAND_H
#define IPREVIOUSSTATECOMMAND_H

#include "ICommand.h"

class IPreviousStateCommand : public ICommand {
public:
    virtual ~IPreviousStateCommand() {};

    virtual void execute() = 0;
};
#endif 