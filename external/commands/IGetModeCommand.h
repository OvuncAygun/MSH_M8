#ifndef IGETMODECOMMAND_H
#define IGETMODECOMMAND_H

#include "ICommand.h"
#include <string>

class IGetModeCommand : public ICommand {
public:
    virtual ~IGetModeCommand() = 0;

    std::string* modeNameResult; // Mod�l 8'deki std::string de�i�keninin adresi

    virtual void execute() = 0;
};
#endif