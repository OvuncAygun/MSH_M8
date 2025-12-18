#ifndef IPOWEROFFDEVICECOMMAND_H
#define IPOWEROFFDEVICECOMMAND_H

#include "ICommand.h"
#include "DeviceType.h"
#include "IDevice.h"

class IPoweroffDeviceCommand : public ICommand {
public:
    virtual ~IPoweroffDeviceCommand() {};
    
    IDevice* device;

    virtual void execute() = 0;
};
#endif 
