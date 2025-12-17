#pragma once

#include "MenuAction.h"

class PowerOnDeviceAction : public MenuAction {
public:
    PowerOnDeviceAction();
    ~PowerOnDeviceAction();

    void execute() override;
};