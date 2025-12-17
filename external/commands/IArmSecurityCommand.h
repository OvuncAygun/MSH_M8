#ifndef IARMSECURITYCOMMAND_H
#define IARMSECURITYCOMMAND_H

#include "ICommand.h"

class IArmSecurityCommand : public ICommand {
public:
    virtual ~IArmSecurityCommand() = 0;

    virtual void execute() = 0;
};
#endif 