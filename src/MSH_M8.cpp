#include "MSH_M8.h"
#include "GetHomeStatusAction.h"
#include "AddDeviceAction.h"
#include "RemoveDeviceAction.h"
#include "PoweronDeviceAction.h"
#include "PoweroffDeviceAction.h"
#include "ChangeModeAction.h"
#include "ChangeStateAction.h"
#include "ManualAction.h"
#include "AboutAction.h"
#include "ShutdownAction.h"
#include "MSHMenuManager.h"
#include "Simulation1.h"
#include "Simulation2.h"
#include "Simulation3.h"


MSH_M8::MSH_M8() = default;
MSH_M8::~MSH_M8() = default;

void MSH_M8::initializeMenuManager() {
    mshMenuManager = MSHMenuManager::getInstance();
}

void MSH_M8::initializeActions() {
    actionMap["1"] = new GetHomeStatusAction();
    actionMap["2"] = new AddDeviceAction();
    actionMap["3"] = new RemoveDeviceAction();
    actionMap["4"] = new PoweronDeviceAction();
    actionMap["5"] = new PoweroffDeviceAction();
    actionMap["6"] = new ChangeModeAction();
    actionMap["7"] = new ChangeStateAction();
    actionMap["8"] = new ManualAction();
    actionMap["9"] = new AboutAction();
    actionMap["10"] = new ShutdownAction();
    actionMap["11"] = new Simulation1();
    actionMap["12"] = new Simulation2();
    actionMap["13"] = new Simulation3();
}

void MSH_M8::applyMSHMMenuManagerActions() {
    mshMenuManager->setActionMap(actionMap);
}

void MSH_M8::initializeCommands(std::vector<ICommand*> commands) {
    commandMap["getMode"] = commands[0];
    commandMap["changeMode"] = commands[1];
    commandMap["getState"] = commands[2];
    commandMap["changeState"] = commands[3];
    commandMap["previousState"] = commands[4];
    commandMap["nextState"] = commands[5];
    commandMap["getDeviceByType"] = commands[6];
    commandMap["getDeviceByIndex"] = commands[7];
    commandMap["removeDevice"] = commands[8];
    commandMap["poweronDevice"] = commands[9];
    commandMap["poweroffDevice"] = commands[10];
    commandMap["addDevice"] = commands[11];
    commandMap["armSecurity"] = commands[12];
}

void MSH_M8::applyMSHMMenuManagerCommands() {
    mshMenuManager->setCommandMap(commandMap);
}

void MSH_M8::initializeModes(std::vector<IModeStrategy*> modes) {
    modeMap["normal"] = modes[0];
    modeMap["evening"] = modes[1];
    modeMap["party"] = modes[2];
    modeMap["cinema"] = modes[3];
}

void MSH_M8::applyMSHMMenuManagerModes() {
    mshMenuManager->setModeMap(modeMap);
}

void MSH_M8::initializeStates(std::vector<IState*> states) {
    stateMap["normal"] = states[0];
    stateMap["highPerformance"] = states[1];
    stateMap["lowPower"] = states[2];
    stateMap["sleep"] = states[3];
}

void MSH_M8::applyMSHMMenuManagerStates() {
    mshMenuManager->setStateMap(stateMap);
}

void MSH_M8::setSecurityManager(ISecurityManager* securityManager) {
    static_cast<MSHMenuManager*>(mshMenuManager)->setSecurityManager(securityManager);
}



IMSHMenuManager* MSH_M8::getMenuManager() {
    return mshMenuManager;
}   