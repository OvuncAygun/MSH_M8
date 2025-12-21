#include "Simulation1.h"
#include "MSHMenuManager.h"

Simulation1::Simulation1() = default;
Simulation1::~Simulation1() = default;

void Simulation1::execute() {
    MSHMenuManager* menuManager = MSHMenuManager::getInstance();
    ISecurityManager* securityManager = menuManager->getSecurityManager();
    securityManager->onSmokeDetected(10000);
}