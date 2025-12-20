#include "ChangeStateAction.h"
#include "MenuDisplayer.h"
#include "InputHandler.h"
#include "MSHMenuManager.h"
#include "IChangeStateCommand.h"
#include "IPreviousStateCommand.h"
#include "IGetStateCommand.h"
#include "IState.h"

#include <sstream>

ChangeStateAction::ChangeStateAction() = default;
ChangeStateAction::~ChangeStateAction() = default;

void ChangeStateAction::execute() {
    MenuDisplayer menuDisplayer;
    InputHandler inputHandler;
    MSHMenuManager* mshMenuManager = MSHMenuManager::getInstance();
    IChangeStateCommand* changeStateCommand = 
        dynamic_cast<IChangeStateCommand*>(mshMenuManager->getCommandMap()["changeState"]);
    IPreviousStateCommand* previousStateCommand = 
        dynamic_cast<IPreviousStateCommand*>(mshMenuManager->getCommandMap()["previousState"]);
    IGetStateCommand* getStateCommand = 
        dynamic_cast<IGetStateCommand*>(mshMenuManager->getCommandMap()["getState"]);

    menuDisplayer.showFormattedText("Choose a state to change to\n");
    menuDisplayer.showFormattedText("(N)ormal, (H)igh Performance, (L)ow Power, (S)leep, (P)revious one:\n");
    std::string stateInput = inputHandler.handleSelectionInput();

    IState* selectedState;
    if (stateInput != "P") {
        if(stateInput == "N") {
            selectedState = mshMenuManager->getStateMap()["normal"];
        } else if(stateInput == "H") {
            selectedState = mshMenuManager->getStateMap()["highPerformance"];
        } else if(stateInput == "L") {
            selectedState = mshMenuManager->getStateMap()["lowPower"];
        } else if(stateInput == "S") {
            selectedState = mshMenuManager->getStateMap()["sleep"];
        } else {
            menuDisplayer.showText("Invalid state selected.");
        }
        
        changeStateCommand->state = selectedState;
        changeStateCommand->execute();
    }
    else {
        previousStateCommand->execute();
        selectedState = getStateCommand->state;
    }
    
    menuDisplayer.showFormattedText("State changed to " + selectedState->getName() + ".\n");
}