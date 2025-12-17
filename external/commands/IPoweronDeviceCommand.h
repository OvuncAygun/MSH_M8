#ifndef IPOWERONDEVICECOMMAND_H
#define IPOWERONDEVICECOMMAND_H

#include "ICommand.h"
#include "DeviceType.h"

class IPoweronDeviceCommand : public ICommand {
public:
    virtual ~IPoweronDeviceCommand() = 0;

    DeviceType deviceType;
    int index;

    virtual void execute() = 0;
};
#endif 