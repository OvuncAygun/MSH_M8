#include "PowerOffDeviceAction.h"
#include "MenuDisplayer.h"
#include "InputHandler.h"
#include "MSHMenuManager.h"
#include "IPoweroffDeviceCommand.h"
#include "IGetDeviceByTypeCommand.h"

#include <sstream>

PoweroffDeviceAction::PoweroffDeviceAction() = default;
PoweroffDeviceAction::~PoweroffDeviceAction() = default;

void PoweroffDeviceAction::execute() {
    MenuDisplayer menuDisplayer;
    InputHandler inputHandler;
    MSHMenuManager* mshMenuManager = MSHMenuManager::getInstance();
    IPoweroffDeviceCommand* poweroffDeviceCommand = 
        static_cast<IPoweroffDeviceCommand*>(mshMenuManager->getCommandMap()["poweroffDevice"]);
    IGetDeviceByTypeCommand* getDeviceByTypeCommand = 
        static_cast<IGetDeviceByTypeCommand*>(mshMenuManager->getCommandMap()["getDeviceByType"]);

    menuDisplayer.showFormattedText("Choose a device to power off\n");
    menuDisplayer.showFormattedText("(L)ight, Smoke & Gas (D)etectors, (C)amera, (T)V, (S)ound System:\n");
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
    } else if(deviceTypeInput == "S") {
        getDeviceByTypeCommand->type = DeviceType::TYPE_Music;
        getDeviceByTypeCommand->execute();
        devices.insert(
            devices.end(), 
            getDeviceByTypeCommand->listResult->begin(), 
            getDeviceByTypeCommand->listResult->end()
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

    menuDisplayer.showFormattedText("Enter the Device ID to power off: ");
    std::string deviceId = inputHandler.handleSelectionInput();

    int index;
    std::stringstream(deviceId) >> index;

    poweroffDeviceCommand->index = index;
    poweroffDeviceCommand->execute();

    menuDisplayer.showFormattedText("Device " + deviceId + " off.\n");
}