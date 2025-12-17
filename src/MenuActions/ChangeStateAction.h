#pragma once

#include "MenuAction.h"

class ChangeStateAction : public MenuAction {
public:
    ChangeStateAction();
    ~ChangeStateAction();

    void execute() override;
};