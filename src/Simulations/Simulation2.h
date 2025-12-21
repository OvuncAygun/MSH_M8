#pragma once

#include "MenuAction.h"

class Simulation2 : public MenuAction {
public:
    Simulation2();
    ~Simulation2();

    void execute() override;
};