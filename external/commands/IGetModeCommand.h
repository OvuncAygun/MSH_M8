#ifndef IGETMODECOMMAND_H
#define IGETMODECOMMAND_H

#include "ICommand.h"
#include <string>
#include "IModeStrategy.h"

class IGetModeCommand : public ICommand {
public:
    virtual ~IGetModeCommand() {};

    std::string modeName;

    virtual void execute() = 0;
};
#endif