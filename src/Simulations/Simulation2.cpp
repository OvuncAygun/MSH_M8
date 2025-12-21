#include "Simulation2.h"
#include "MSHMenuManager.h"
#include "IArmSecurityCommand.h"

Simulation2::Simulation2() = default;
Simulation2::~Simulation2() = default;

void Simulation2::execute() {
    MSHMenuManager* mshMenuManager = MSHMenuManager::getInstance();
    IArmSecurityCommand* armSecurityCommand = 
        dynamic_cast<IArmSecurityCommand*>(mshMenuManager->getCommandMap()["armSecurity"]);
    armSecurityCommand->execute();
    ISecurityManager* securityManager = mshMenuManager->getSecurityManager();
    securityManager->onMotionDetected(15000);
}