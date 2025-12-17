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
        "Manual Text...\n"
    );
}