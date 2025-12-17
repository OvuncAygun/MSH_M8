#include "RemoveDeviceAction.h"
#include "MSHMenuManager.h"
#include "IRemoveDeviceCommand.h"
#include "IGetDeviceByTypeCommand.h"

#include <sstream>

RemoveDeviceAction::RemoveDeviceAction() = default;
RemoveDeviceAction::~RemoveDeviceAction() = default;

void RemoveDeviceAction::execute() {
    MenuDisplayer menuDisplayer;
    InputHandler inputHandler;
    MSHMenuManager* mshMenuManager = MSHMenuManager::getInstance();
    IRemoveDeviceCommand* removeDeviceCommand = 
        static_cast<IRemoveDeviceCommand*>(mshMenuManager->getCommandMap()["removeDevice"]);
    IGetDeviceByTypeCommand* getDeviceByTypeCommand = 
        static_cast<IGetDeviceByTypeCommand*>(mshMenuManager->getCommandMap()["getDeviceByType"]);

    menuDisplayer.showFormattedText("Choose a device to remove\n");
    menuDisplayer.showFormattedText("(L)ight, Smoke & Gas (D)etectors, (C)amera, (T)V:\n");
    std::string deviceTypeInput = inputHandler.handleSelectionInput();

    std::vector<IDevice*> devices;

    if(deviceTypeInput == "L") {
        getDeviceByTypeCommand->type = DeviceType::TYPE_Light;
        getDeviceByTypeCommand->execute();
        devices.insert(
            devices.end(), 
            getDeviceByTypeCommand->listResult->begin(), 
            getDeviceByTypeCommand->listResult->end()
        );
    } else if(deviceTypeInput == "D") {
        getDeviceByTypeCommand->type = DeviceType::TYPE_GasDetector;
        getDeviceByTypeCommand->execute();
        devices.insert(
            devices.end(), 
            getDeviceByTypeCommand->listResult->begin(), 
            getDeviceByTypeCommand->listResult->end()
        );

        getDeviceByTypeCommand->type = DeviceType::TYPE_SmokeDetector;
        getDeviceByTypeCommand->execute();
        devices.insert(
            devices.end(), 
            getDeviceByTypeCommand->listResult->begin(), 
            getDeviceByTypeCommand->listResult->end()
        );
    } else if(deviceTypeInput == "C") {
        getDeviceByTypeCommand->type = DeviceType::TYPE_Camera;
        getDeviceByTypeCommand->execute();
        devices.insert(
            devices.end(), 
            getDeviceByTypeCommand->listResult->begin(), 
            getDeviceByTypeCommand->listResult->end()
        );
    } else if(deviceTypeInput == "T") {
        getDeviceByTypeCommand->type = DeviceType::TYPE_TV;
        getDeviceByTypeCommand->execute();
        devices.insert(
            devices.end(), 
            getDeviceByTypeCommand->listResult->begin(), 
            getDeviceByTypeCommand->listResult->end()
        );
    } else {
        menuDisplayer.showText("Invalid device type selected.");
    }

    for (IDevice* device : devices) {
        std::stringstream ss;
        ss << device->getIndex() << ": " << device->getName() << "\n";
        std::string text = ss.str();
        menuDisplayer.showFormattedText(text);
    }

    menuDisplayer.showFormattedText("Enter the Device ID to remove: ");
    std::string deviceId = inputHandler.handleSelectionInput();

    int index;
    std::stringstream(deviceId) >> index;

    removeDeviceCommand->index = index;
    removeDeviceCommand->execute();

    menuDisplayer.showFormattedText("Device " + deviceId + " removed.\n");
    inputHandler.waitForInput();
}