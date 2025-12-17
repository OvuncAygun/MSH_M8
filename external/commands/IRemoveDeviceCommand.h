#ifndef IREMOVEDEVICECOMMAND_H
#define IREMOVEDEVICECOMMAND_H

#include "ICommand.h"
#include "DeviceType.h"

class IRemoveDeviceCommand : public ICommand {
public:
    virtual ~IRemoveDeviceCommand() = 0;

    DeviceType deviceType;
    int index;

    virtual void execute() = 0;
};
#endif 