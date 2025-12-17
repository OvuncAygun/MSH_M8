#ifndef IPOWEROFFDEVICECOMMAND_H
#define IPOWEROFFDEVICECOMMAND_H

#include "ICommand.h"
#include "DeviceType.h"

class IPoweroffDeviceCommand : public ICommand {
public:
    virtual ~IPoweroffDeviceCommand() = 0;
    
    DeviceType deviceType;
    int index;

    virtual void execute() = 0;
};
#endif 
