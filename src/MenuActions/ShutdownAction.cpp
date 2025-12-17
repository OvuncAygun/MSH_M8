#include "ShutdownAction.h"
#include "MSHMenuManager.h"

ShutdownAction::ShutdownAction() = default;
ShutdownAction::~ShutdownAction() = default;

void ShutdownAction::execute() {
    MSHMenuManager* mshMenuManager = MSHMenuManager::getInstance();
    mshMenuManager->setIsRunning(false);
}