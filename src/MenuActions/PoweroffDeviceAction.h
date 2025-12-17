#pragma once

#include "MenuAction.h"

class PoweroffDeviceAction : public MenuAction {
public:
    PoweroffDeviceAction();
    ~PoweroffDeviceAction();

    void execute() override;
};