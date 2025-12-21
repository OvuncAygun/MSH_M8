#pragma once

#include "MenuAction.h"

class Simulation3 : public MenuAction {
public:
    Simulation3();
    ~Simulation3();

    void execute() override;
};