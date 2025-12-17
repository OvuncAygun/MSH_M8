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
    
    virtual void displayMenu();
    virtual void handleInput();

    virtual std::map<std::string, MenuAction*> getActionMap();
    virtual void setActionMap(std::map<std::string, MenuAction*> actionMap);

    virtual std::map<std::string, ICommand*> getCommandMap();
    virtual void setCommandMap(std::map<std::string, ICommand*> commandMap);

    virtual std::map<std::string, IModeStrategy*> getModeMap();
    virtual void setModeMap(std::map<std::string, IModeStrategy*> modeMap);

    virtual std::map<std::string, IState*> getStateMap();
    virtual void setStateMap(std::map<std::string, IState*> stateMap);

    virtual bool getIsRunning() const;
    virtual void setIsRunning(bool isRunning);
};