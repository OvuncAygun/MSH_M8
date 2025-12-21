#pragma once

#include "MenuAction.h"

class PoweronDeviceAction : public MenuAction {
public:
    PoweronDeviceAction();
    ~PoweronDeviceAction();

    void execute() override;
};