#pragma once

#include "MenuAction.h"

class ChangeModeAction : public MenuAction {
public:
    ChangeModeAction();
    ~ChangeModeAction();

    void execute() override;
};