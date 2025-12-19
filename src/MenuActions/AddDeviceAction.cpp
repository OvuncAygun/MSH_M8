#include "AddDeviceAction.h"
#include "MenuDisplayer.h"
#include "InputHandler.h"
#include "MSHMenuManager.h"
#include "DeviceCreationType.h"
#include "IAddDeviceCommand.h"

#include <sstream>

AddDeviceAction::AddDeviceAction() = default;
AddDeviceAction::~AddDeviceAction() = default;


void AddDeviceAction::execute() {
    MenuDisplayer menuDisplayer;
    InputHandler inputHandler;
    MSHMenuManager* mshMenuManager = MSHMenuManager::getInstance();
    IAddDeviceCommand* addDeviceCommand = 
        dynamic_cast<IAddDeviceCommand*>(mshMenuManager->getCommandMap()["addDevice"]);

    menuDisplayer.showFormattedText("Choose a device to add\n");
    menuDisplayer.showFormattedText("(L)ight, Smoke & Gas (D)etectors, (C)amera, (T)V:\n");
    std::string deviceTypeInput = inputHandler.handleSelectionInput();

    DeviceCreationType deviceType;

    if(deviceTypeInput == "L") {
        deviceType = DEVICE_LIGHT;
    } else if(deviceTypeInput == "D") {
        deviceType = DEVICE_DETECTOR;
    } else if(deviceTypeInput == "C") {
        deviceType = DEVICE_CAMERA;
    } else if(deviceTypeInput == "T") {
        deviceType = DEVICE_TV;
    } else {
        menuDisplayer.showText("Invalid device type selected.");
    }

    menuDisplayer.showFormattedText("Enter Quantity: ");
    std::stringstream ss;
    ss << inputHandler.handleConfigurationInput();
    int quantity;
    ss >> quantity;

    for(int i = 1; i <= quantity; ++i) {
        menuDisplayer.showFormattedText("Enter Device Name: ");
        std::string deviceName = inputHandler.handleConfigurationInput();

        std::vector<std::string> deviceConfig;
        std::vector<std::string> configNames = menuDisplayer.getDeviceCreationConfigNames(deviceType);

        for(const std::string& configName : configNames) {
            menuDisplayer.showFormattedText("Enter " + configName + ":");
            std::string configValue = inputHandler.handleConfigurationInput();
            deviceConfig.push_back(configValue);
        }

        if (i != quantity) {
            menuDisplayer.showFormattedText("Do you want to copy this configuration to the rest of the devices? (YES/NO)\n");
            std::string copyConfigInput = inputHandler.handleSelectionInput();
            if (copyConfigInput == "YES") {
                addDeviceCommand->deviceCreationType = static_cast<DeviceCreationType>(deviceType);
                addDeviceCommand->count = quantity - i;
                addDeviceCommand->name = deviceName;
                addDeviceCommand->config = deviceConfig;
                addDeviceCommand->execute();
                break;
            }
            else {
                addDeviceCommand->deviceCreationType = static_cast<DeviceCreationType>(deviceType);
                addDeviceCommand->count = 1;
                addDeviceCommand->name = deviceName;
                addDeviceCommand->config = deviceConfig;
                addDeviceCommand->execute();
            }
        }
        else {
            
            addDeviceCommand->deviceCreationType = static_cast<DeviceCreationType>(deviceType);
            addDeviceCommand->count = 1;
            addDeviceCommand->name = deviceName;
            addDeviceCommand->config = deviceConfig;
            addDeviceCommand->execute();
        }
        
    }
}