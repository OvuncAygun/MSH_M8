#ifndef IREMOVEDEVICECOMMAND_H
#define IREMOVEDEVICECOMMAND_H

#include "ICommand.h"
#include "DeviceType.h"
#include "IDevice.h"

class IRemoveDeviceCommand : public ICommand {
public:
    virtual ~IRemoveDeviceCommand() {};

    IDevice* device;

    virtual void execute() = 0;
};
#endif 