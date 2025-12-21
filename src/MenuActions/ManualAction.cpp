#include "ManualAction.h"
#include "MenuDisplayer.h"
#include "InputHandler.h"
#include "MSHMenuManager.h"

ManualAction::ManualAction() = default;
ManualAction::~ManualAction() = default;

void ManualAction::execute() {
    MenuDisplayer menuDisplayer;
    InputHandler inputHandler;
    MSHMenuManager* mshMenuManager = MSHMenuManager::getInstance();
    menuDisplayer.showText(
        "Use keyboard to navigate between operations\n"
        "Case sensitive inputs are required.\n"
    );
}