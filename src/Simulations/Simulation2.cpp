#include "Simulation2.h"
#include "MSHMenuManager.h"

Simulation2::Simulation2() = default;
Simulation2::~Simulation2() = default;

void Simulation2::execute() {
    MSHMenuManager* menuManager = MSHMenuManager::getInstance();
    ISecurityManager* securityManager = menuManager->getSecurityManager();
    securityManager->onMotionDetected(10000);
}