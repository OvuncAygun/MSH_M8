#ifndef IGETDEVICEBYINDEXCOMMAND_H
#define IGETDEVICEBYINDEXCOMMAND_H

#include "ICommand.h"
#include "IDevice.h"

class IGetDeviceByIndexCommand : public ICommand {
public:
    virtual ~IGetDeviceByIndexCommand() = 0;

    int index;
    IDevice** resultHolder; // Mod�l 8'deki IDevice* de�i�keninin adresi

    virtual void execute() = 0;
};
#endif