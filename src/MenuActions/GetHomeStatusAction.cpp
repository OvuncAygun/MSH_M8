#include "GetHomeStatusAction.h"
#include "MSHMenuManager.h"
#include "IGetModeCommand.h"
#include "IGetStateCommand.h"
#include "IGetDeviceByTypeCommand.h"
#include "IState.h"
#include "DeviceType.h"

#include <sstream>

GetHomeStatusAction::GetHomeStatusAction() = default;
GetHomeStatusAction::~GetHomeStatusAction() = default;

void GetHomeStatusAction::execute() {
    MenuDisplayer menuDisplayer;
    InputHandler inputHandler;
    MSHMenuManager* mshMenuManager = MSHMenuManager::getInstance();
    IGetModeCommand* getModeCommand = 
        static_cast<IGetModeCommand*>(mshMenuManager->getCommandMap()["getMode"]);
    IGetStateCommand* getStateCommand = 
        static_cast<IGetStateCommand*>(mshMenuManager->getCommandMap()["getState"]);
    IGetDeviceByTypeCommand* getDeviceByTypeCommand = 
        static_cast<IGetDeviceByTypeCommand*>(mshMenuManager->getCommandMap()["getDeviceByType"]);

    menuDisplayer.showFormattedText("Mode: ");
    getModeCommand->execute();
    std::string modeName = *getModeCommand->modeNameResult;
    menuDisplayer.showFormattedText(modeName + "\n");

    menuDisplayer.showFormattedText("State: ");
    getStateCommand->execute();
    IState* state = *getStateCommand->stateResult;
    menuDisplayer.showFormattedText(state->getName() + "\n");

    getDeviceByTypeCommand->type = DeviceType::TYPE_Light;
    getDeviceByTypeCommand->execute();
    std::vector<IDevice*> lights = *getDeviceByTypeCommand->listResult;

    for(IDevice* light : lights) {
        std::stringstream ss;
        ss << "Light " << light->getIndex() << " - " << light->getName() << ": " << 
            (light->getPowerState() ? "on" : "off") << "\n";
        std::string text = ss.str();
        menuDisplayer.showFormattedText(text);
    }

    getDeviceByTypeCommand->type = DeviceType::TYPE_TV;
    getDeviceByTypeCommand->execute();
    std::vector<IDevice*> tvs = *getDeviceByTypeCommand->listResult;
    for(IDevice* tv : tvs) {
        std::stringstream ss;
        ss << "TV " << tv->getIndex() << " - " << tv->getName() << ": " << 
            (tv->getOperationState() ? "on" : "off") << "\n";
        std::string text = ss.str();
        menuDisplayer.showFormattedText(text);
    }

    getDeviceByTypeCommand->type = DeviceType::TYPE_Music;
    getDeviceByTypeCommand->execute();
    std::vector<IDevice*> musicDevices = *getDeviceByTypeCommand->listResult;
    for(IDevice* musicDevice : musicDevices) {
        std::stringstream ss;
        ss << "TV " << musicDevice->getIndex() << " - " << musicDevice->getName() << ": " << 
            (musicDevice->getOperationState() ? "on" : "off") << "\n";
        std::string text = ss.str();
        menuDisplayer.showFormattedText(text);
    }

    getDeviceByTypeCommand->type = DeviceType::TYPE_Camera;
    getDeviceByTypeCommand->execute();
    std::vector<IDevice*> cameras = *getDeviceByTypeCommand->listResult;
    for(IDevice* camera : cameras) {
        std::stringstream ss;
        ss << "Camera " << camera->getIndex() << " - " << camera->getName() << ": " << 
            (camera->getOperationState() ? "on" : "off") << "\n";
        std::string text = ss.str();
        menuDisplayer.showFormattedText(text);
    }

    getDeviceByTypeCommand->type = DeviceType::TYPE_Alarm;
    getDeviceByTypeCommand->execute();
    std::vector<IDevice*> alarms = *getDeviceByTypeCommand->listResult;
    for(IDevice* alarm : alarms) {
        std::stringstream ss;
        ss << "Alarm " << alarm->getIndex() << " - " << alarm->getName() << ": " << 
            (alarm->getOperationState() ? "on" : "off") << "\n";
        std::string text = ss.str();
        menuDisplayer.showFormattedText(text);
    }

    getDeviceByTypeCommand->type = DeviceType::TYPE_SmokeDetector;
    getDeviceByTypeCommand->execute();
    std::vector<IDevice*> smokeDetectors = *getDeviceByTypeCommand->listResult;
    for(IDevice* smokeDetector : smokeDetectors) {
        std::stringstream ss;
        ss << "Smoke Detector " << smokeDetector->getIndex() << " - " << smokeDetector->getName() << ": " << 
            (smokeDetector->getOperationState() ? "on" : "off") << "\n";
        std::string text = ss.str();
        menuDisplayer.showFormattedText(text);
    }

    getDeviceByTypeCommand->type = DeviceType::TYPE_GasDetector;
    getDeviceByTypeCommand->execute();
    std::vector<IDevice*> gasDetectors = *getDeviceByTypeCommand->listResult;
    for(IDevice* gasDetector : gasDetectors) {
        std::stringstream ss;
        ss << "Gas Detector " << gasDetector->getIndex() << " - " << gasDetector->getName() << ": " << 
            (gasDetector->getOperationState() ? "on" : "off") << "\n";
        std::string text = ss.str();
        menuDisplayer.showFormattedText(text);
    }

    inputHandler.waitForInput();
}