#ifndef ICHANGESTATECOMMAND_H
#define ICHANGESTATECOMMAND_H

#include "ICommand.h"
#include "IState.h"

class IChangeStateCommand : public ICommand {
public:
    virtual ~IChangeStateCommand() = 0;

    IState* newState; // M4'teki somut bir durum olmal�

    virtual void execute() = 0;
};
#endif 