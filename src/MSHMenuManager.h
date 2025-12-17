#pragma once

#include "IMSHMenuManager.h"
#include "MenuAction.h"
#include "ICommand.h"
#include "IModeStrategy.h"
#include "IState.h"

#include <map>

class MSHMenuManager : public IMSHMenuManager {
public:
    ~MSHMenuManager();

    static MSHMenuManager* getInstance();
    
    void displayMenu();
    void handleInput();

    std::map<std::string, MenuAction*> getActionMap();
    void setActionMap(std::map<std::string, MenuAction*> actionMap);

    std::map<std::string, ICommand*> getCommandMap();
    void setCommandMap(std::map<std::string, ICommand*> commandMap);

    std::map<std::string, IModeStrategy*> getModeMap();
    void setModeMap(std::map<std::string, IModeStrategy*> modeMap);

    std::map<std::string, IState*> getStateMap();
    void setStateMap(std::map<std::string, IState*> stateMap);

    bool getIsRunning() const;
    void setIsRunning(bool isRunning);

private:
    static MSHMenuManager* instance;
    std::map<std::string, MenuAction*> actionMap;
    std::map<std::string, ICommand*> commandMap;
    std::map<std::string, IModeStrategy*> modeMap;
    std::map<std::string, IState*> stateMap;

    bool isRunning = true;

    MSHMenuManager() = default;
};