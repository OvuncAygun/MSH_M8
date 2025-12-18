#pragma once

#include "MenuAction.h"
#include "ICommand.h"
#include "IModeStrategy.h"
#include "IState.h"

#include <map>
#include <string>

class IMSHMenuManager {
public:
    virtual ~IMSHMenuManager() = 0;
    
    virtual void displayMenu() = 0;
    virtual void handleInput() = 0;

    virtual std::map<std::string, MenuAction*> getActionMap() = 0;
    virtual void setActionMap(std::map<std::string, MenuAction*> actionMap) = 0;
    virtual std::map<std::string, ICommand*> getCommandMap() = 0;
    virtual void setCommandMap(std::map<std::string, ICommand*> commandMap) = 0;

    virtual std::map<std::string, IModeStrategy*> getModeMap() = 0;
    virtual void setModeMap(std::map<std::string, IModeStrategy*> modeMap) = 0;
    virtual std::map<std::string, IState*> getStateMap() = 0;
    virtual void setStateMap(std::map<std::string, IState*> stateMap) = 0;

    virtual bool getIsRunning() const = 0;
    virtual void setIsRunning(bool isRunning) = 0;
};