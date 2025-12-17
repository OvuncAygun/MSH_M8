#ifndef IPREVIOUSSTATECOMMAND_H
#define IPREVIOUSSTATECOMMAND_H

#include "ICommand.h"

class IPreviousStateCommand : public ICommand {
public:
    virtual ~IPreviousStateCommand() = 0;

    virtual void execute() = 0;
};
#endif 