#pragma once

#include "MenuAction.h"

class ManualAction : public MenuAction {
public:
    ManualAction();
    ~ManualAction();

    void execute() override;
};