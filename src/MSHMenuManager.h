#pragma once

#include "MenuAction.h"
#include "ICommand.h"

#include <map>

class MSHMenuManager {
public:
    ~MSHMenuManager();

    static MSHMenuManager* getInstance();
    
    void displayMenu();
    void handleInput();

    std::map<std::string, ICommand*> getCommandMap();
    void setCommandMap(std::map<std::string, ICommand*> commandMap);

private:
    static MSHMenuManager* instance;
    std::map<char, MenuAction*> actionMap;
    std::map<std::string, ICommand*> commandMap;

    MSHMenuManager();
};