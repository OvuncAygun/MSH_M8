#include "ShutdownAction.h"
#include "MenuDisplayer.h"
#include "InputHandler.h"
#include "MSHMenuManager.h"

ShutdownAction::ShutdownAction() = default;
ShutdownAction::~ShutdownAction() = default;

void ShutdownAction::execute() {
    MSHMenuManager* mshMenuManager = MSHMenuManager::getInstance();
    mshMenuManager->setIsRunning(false);
}