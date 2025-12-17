#pragma once

#include "MenuAction.h"

class AddDeviceAction : public MenuAction {
public:
    AddDeviceAction();
    ~AddDeviceAction();

    void execute() override;
};