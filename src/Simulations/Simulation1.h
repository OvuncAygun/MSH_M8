#pragma once

#include "MenuAction.h"

class Simulation1 : public MenuAction {
public:
    Simulation1();
    ~Simulation1();

    void execute() override;
};