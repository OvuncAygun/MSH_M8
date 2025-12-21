#include "PoweronDeviceAction.h"
#include "MenuDisplayer.h"
#include "InputHandler.h"
#include "MSHMenuManager.h"
#include "IPoweronDeviceCommand.h"
#include "IGetDeviceByTypeCommand.h"

#include <sstream>

PoweronDeviceAction::PoweronDeviceAction() = default;
PoweronDeviceAction::~PoweronDeviceAction() = default;

void PoweronDeviceAction::execute() {
    MenuDisplayer menuDisplayer;
    InputHandler inputHandler;
    MSHMenuManager* mshMenuManager = MSHMenuManager::getInstance();
    IPoweronDeviceCommand* poweronDeviceCommand = 
        dynamic_cast<IPoweronDeviceCommand*>(mshMenuManager->getCommandMap()["poweronDevice"]);
    IGetDeviceByTypeCommand* getDeviceByTypeCommand = 
        dynamic_cast<IGetDeviceByTypeCommand*>(mshMenuManager->getCommandMap()["getDeviceByType"]);

    menuDisplayer.showFormattedText("Choose a device to power on\n");
    menuDisplayer.showFormattedText("(L)ight, Smoke & Gas (D)etectors, (C)amera, (T)V, (S)ound System:\n");
    std::string deviceTypeInput = inputHandler.handleSelectionInput();

    std::vector<IDevice*> devices;

    if(deviceTypeInput == "L") {
        getDeviceByTypeCommand->type = DeviceType::TYPE_Light;
        getDeviceByTypeCommand->execute();
        devices.insert(
            devices.end(), 
            getDeviceByTypeCommand->devices.begin(), 
            getDeviceByTypeCommand->devices.end()
        );
    } else if(deviceTypeInput == "D") {
        getDeviceByTypeCommand->type = DeviceType::TYPE_GasDetector;
        getDeviceByTypeCommand->execute();
        devices.insert(
            devices.end(), 
            getDeviceByTypeCommand->devices.begin(), 
            getDeviceByTypeCommand->devices.end()
        );

        getDeviceByTypeCommand->type = DeviceType::TYPE_SmokeDetector;
        getDeviceByTypeCommand->execute();
        devices.insert(
            devices.end(), 
            getDeviceByTypeCommand->devices.begin(), 
            getDeviceByTypeCommand->devices.end()
        );
    } else if(deviceTypeInput == "C") {
        getDeviceByTypeCommand->type = DeviceType::TYPE_Camera;
        getDeviceByTypeCommand->execute();
        devices.insert(
            devices.end(), 
            getDeviceByTypeCommand->devices.begin(), 
            getDeviceByTypeCommand->devices.end()
        );
    } else if(deviceTypeInput == "T") {
        getDeviceByTypeCommand->type = DeviceType::TYPE_TV;
        getDeviceByTypeCommand->execute();
        devices.insert(
            devices.end(), 
            getDeviceByTypeCommand->devices.begin(), 
            getDeviceByTypeCommand->devices.end()
        );
    } else if(deviceTypeInput == "S") {
        getDeviceByTypeCommand->type = DeviceType::TYPE_Music;
        getDeviceByTypeCommand->execute();
        devices.insert(
            devices.end(), 
            getDeviceByTypeCommand->devices.begin(), 
            getDeviceByTypeCommand->devices.end()
        );
    } else {
        menuDisplayer.showText("Invalid device type selected.");
        inputHandler.waitForInput();
    }

    for (IDevice* device : devices) {
        std::stringstream ss;
        ss << device->getIndex() << ": " << device->getName() << "\n";
        std::string text = ss.str();
        menuDisplayer.showFormattedText(text);
    }

    menuDisplayer.showFormattedText("Enter the Device ID to power on: ");
    std::string deviceId = inputHandler.handleSelectionInput();

    int index;
    std::stringstream(deviceId) >> index;

    poweronDeviceCommand->device = NULL;
    for (IDevice* device : devices) {
        if (device->getIndex() == index) {
            poweronDeviceCommand->device = device;
            break;
        }
    }
    if (poweronDeviceCommand->device != NULL) {
        poweronDeviceCommand->execute();
        menuDisplayer.showFormattedText("Device " + deviceId + " on.\n");
    } else {
        menuDisplayer.showFormattedText("Invalid Device ID.\n");
    }

    menuDisplayer.showFormattedText("Device " + deviceId + " on.\n");
}