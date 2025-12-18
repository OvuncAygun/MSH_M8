#pragma once

#include "ICommand.h"
#include "IMSHMenuManager.h"

#include <vector>
#include <map>
#include <string>

class MSH_M8 {
public:
    MSH_M8();
    ~MSH_M8();

    void initializeMenuManager();

    void initializeCommands(std::vector<ICommand*> commands);
    void applyMSHMMenuManagerCommands();

    void initializeActions();
    void applyMSHMMenuManagerActions();

    void initializeModes(std::vector<IModeStrategy*> modes);
    void applyMSHMMenuManagerModes();

    void initializeStates(std::vector<IState*> states);
    void applyMSHMMenuManagerStates();

private:
    IMSHMenuManager* mshMenuManager;
    std::map<std::string, ICommand*> commandMap;
    std::map<std::string, MenuAction*> actionMap;
    std::map<std::string, IModeStrategy*> modeMap;
    std::map<std::string, IState*> stateMap;
};