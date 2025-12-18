#ifndef ICHANGEMODECOMMAND_H
#define ICHANGEMODECOMMAND_H

#include "ICommand.h"
#include "IModeStrategy.h"

class IChangeModeCommand : public ICommand {
public:
    virtual ~IChangeModeCommand() {};

    IModeStrategy* mode;

    virtual void execute() = 0;
};
#endif 