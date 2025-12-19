#include "ChangeModeAction.h"
#include "MenuDisplayer.h"
#include "InputHandler.h"
#include "MSHMenuManager.h"
#include "IChangeModeCommand.h"
#include "IModeStrategy.h"

#include <sstream>

ChangeModeAction::ChangeModeAction() = default;
ChangeModeAction::~ChangeModeAction() = default;

void ChangeModeAction::execute() {
    MenuDisplayer menuDisplayer;
    InputHandler inputHandler;
    MSHMenuManager* mshMenuManager = MSHMenuManager::getInstance();
    IChangeModeCommand* changeModeCommand = 
        dynamic_cast<IChangeModeCommand*>(mshMenuManager->getCommandMap()["changeMode"]);

    menuDisplayer.showFormattedText("Choose a mode to change to\n");
    menuDisplayer.showFormattedText("(N)ormal, (E)vening, (P)arty, (C)inema:\n");
    std::string modeInput = inputHandler.handleSelectionInput();

    IModeStrategy* selectedMode;

    if(modeInput == "N") {
        selectedMode = mshMenuManager->getModeMap()["normal"];
    } else if(modeInput == "E") {
        selectedMode = mshMenuManager->getModeMap()["evening"];
    } else if(modeInput == "P") {
        selectedMode = mshMenuManager->getModeMap()["party"];
    } else if(modeInput == "C") {
        selectedMode = mshMenuManager->getModeMap()["cinema"];
    } else {
        menuDisplayer.showText("Invalid mode selected.");
    }

    changeModeCommand->mode = selectedMode;
    changeModeCommand->execute();
    
    menuDisplayer.showFormattedText("Mode changed to " + selectedMode->getModeName() + ".\n");
}