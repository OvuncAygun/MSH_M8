#pragma once

#include "ICommand.h"
#include "MSHMenuManager.h"

#include <vector>
#include <map>
#include <string>

class MSH_M8 {
public:
    MSH_M8();
    ~MSH_M8();

    MSHMenuManager* getMenuManager();
    void setMenuManager(MSHMenuManager* menuManager);

    void initializeCommands(std::vector<ICommand*> commands);

    void applyMSHMMenuManagerCommands();

private:
    std::map<std::string, ICommand*> commandMap;
    MSHMenuManager* mshMenuManager;
};