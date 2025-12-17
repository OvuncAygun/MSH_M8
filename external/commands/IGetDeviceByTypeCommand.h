#ifndef IGETDEVICEBYTYPECOMMAND_H
#define IGETDEVICEBYTYPECOMMAND_H

#include "ICommand.h"
#include "IDevice.h"
#include "DeviceType.h"
#include <vector>

class IGetDeviceByTypeCommand : public ICommand {
public:
    virtual ~IGetDeviceByTypeCommand() = 0;

    DeviceType type;
    std::vector<IDevice*>* listResult; // M8'deki listenin adresi

    virtual void execute() = 0;
};
#endif