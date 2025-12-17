#pragma once

#include "MenuAction.h"

class RemoveDeviceAction : public MenuAction {
public:
    RemoveDeviceAction();
    ~RemoveDeviceAction();

    void execute() override;
};