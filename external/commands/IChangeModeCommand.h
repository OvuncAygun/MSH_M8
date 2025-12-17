#ifndef ICHANGEMODECOMMAND_H
#define ICHANGEMODECOMMAND_H

#include "ICommand.h"
#include "IModeStrategy.h"

class IChangeModeCommand : public ICommand {
public:
    virtual ~IChangeModeCommand() = 0;

    IModeStrategy* newMode;

    virtual void execute() = 0;
};
#endif 