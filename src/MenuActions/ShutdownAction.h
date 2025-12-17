#pragma once

#include "MenuAction.h"

class ShutdownAction : public MenuAction {
public:
    ShutdownAction();
    ~ShutdownAction();

    void execute() override;
};