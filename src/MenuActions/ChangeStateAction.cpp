#include "ChangeStateAction.h"
#include "MSHMenuManager.h"
#include "IChangeStateCommand.h"
#include "IPreviousStateCommand.h"
#include "IState.h"

#include <sstream>

ChangeStateAction::ChangeStateAction() = default;
ChangeStateAction::~ChangeStateAction() = default;

void ChangeStateAction::execute() {
    MenuDisplayer menuDisplayer;
    InputHandler inputHandler;
    MSHMenuManager* mshMenuManager = MSHMenuManager::getInstance();
    IChangeStateCommand* changeStateCommand = 
        static_cast<IChangeStateCommand*>(mshMenuManager->getCommandMap()["changeState"]);
    IPreviousStateCommand* previousStateCommand = 
        static_cast<IPreviousStateCommand*>(mshMenuManager->getCommandMap()["previousState"]);

    menuDisplayer.showFormattedText("Choose a state to change to\n");
    menuDisplayer.showFormattedText("(N)ormal, (H)igh Performance, (L)ow Power, (S)leep, (P)revious one:\n");
    std::string stateInput = inputHandler.handleSelectionInput();

    IState* selectedState;
    if(stateInput == "N") {
        selectedState = mshMenuManager->getStateMap()["NormalState"];
    } else if(stateInput == "H") {
        selectedState = mshMenuManager->getStateMap()["HighPerformanceState"];
    } else if(stateInput == "L") {
        selectedState = mshMenuManager->getStateMap()["LowPowerState"];
    } else if(stateInput == "S") {
        selectedState = mshMenuManager->getStateMap()["SleepState"];
    } else if(stateInput == "P") {
        selectedState = mshMenuManager->getStateMap()["PreviousState"];
    } else {
        menuDisplayer.showText("Invalid state selected.");
    }

    if (stateInput != "P") {
        if(stateInput == "N") {
            selectedState = mshMenuManager->getStateMap()["NormalState"];
        } else if(stateInput == "H") {
            selectedState = mshMenuManager->getStateMap()["HighPerformanceState"];
        } else if(stateInput == "L") {
            selectedState = mshMenuManager->getStateMap()["LowPowerState"];
        } else if(stateInput == "S") {
            selectedState = mshMenuManager->getStateMap()["SleepState"];
        } else {
            menuDisplayer.showText("Invalid state selected.");
        }
        
        changeStateCommand->newState = selectedState;
        changeStateCommand->execute();
    }
    else {
        previousStateCommand->execute();
    }
    
    menuDisplayer.showFormattedText("State changed to " + selectedState->getName() + ".\n");
    inputHandler.waitForInput();
}