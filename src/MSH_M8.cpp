#include "MSH_M8.h"

MSH_M8::MSH_M8() = default;
MSH_M8::~MSH_M8() = default;

void MSH_M8::setMenuManager(MSHMenuManager* menuManager) {
    mshMenuManager = menuManager;
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