#ifndef IPOWERONDEVICECOMMAND_H
#define IPOWERONDEVICECOMMAND_H

#include "ICommand.h"
#include "DeviceType.h"
#include "IDevice.h"

class IPoweronDeviceCommand : public ICommand {
public:
    virtual ~IPoweronDeviceCommand() {};

    IDevice* device;

    virtual void execute() = 0;
};
#endif 