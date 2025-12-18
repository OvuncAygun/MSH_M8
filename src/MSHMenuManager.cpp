#include "MSHMenuManager.h"
#include "MenuDisplayer.h"
#include "InputHandler.h"

#include <sstream>

MSHMenuManager::~MSHMenuManager() = default;

MSHMenuManager* MSHMenuManager::instance = NULL;

MSHMenuManager* MSHMenuManager::getInstance() {
    if (instance == 0) {
        instance = new MSHMenuManager();
    }
    return instance;
}

void MSHMenuManager::displayMenu() {
    MenuDisplayer menuDisplayer;
    menuDisplayer.showMainMenu();
}

void MSHMenuManager::handleInput() {
    InputHandler inputHandler;
    std::string input = inputHandler.handleSelectionInput();
    actionMap[input]->execute();
    inputHandler.waitForInput();
}

std::map<std::string, MenuAction*> MSHMenuManager::getActionMap() {
    return actionMap;
}
void MSHMenuManager::setActionMap(std::map<std::string, MenuAction*> actionMap) {
    this->actionMap = actionMap;
}

std::map<std::string, ICommand*> MSHMenuManager::getCommandMap() {
    return commandMap;
}
void MSHMenuManager::setCommandMap(std::map<std::string, ICommand*> commandMap) {
    this->commandMap = commandMap;
}

std::map<std::string, IModeStrategy*> MSHMenuManager::getModeMap() {
    return modeMap;
}
void MSHMenuManager::setModeMap(std::map<std::string, IModeStrategy*> modeMap) {
    this->modeMap = modeMap;
}

std::map<std::string, IState*> MSHMenuManager::getStateMap() {
    return stateMap;
}
void MSHMenuManager::setStateMap(std::map<std::string, IState*> stateMap) {
    this->stateMap = stateMap;
}

bool MSHMenuManager::getIsRunning() const {
    return isRunning;
}
void MSHMenuManager::setIsRunning(bool isRunning) {
    this->isRunning = isRunning;
}