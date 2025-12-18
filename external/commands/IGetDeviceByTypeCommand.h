#ifndef IGETDEVICEBYTYPECOMMAND_H
#define IGETDEVICEBYTYPECOMMAND_H

#include "ICommand.h"
#include "IDevice.h"
#include "DeviceType.h"
#include <vector>

class IGetDeviceByTypeCommand : public ICommand {
public:
    virtual ~IGetDeviceByTypeCommand() {};

    DeviceType type;
    std::vector<IDevice*> devices;

    virtual void execute() = 0;
};
#endif