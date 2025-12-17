#pragma once

#include "MenuDisplayer.h"
#include "InputHandler.h"

class MenuAction {
public:
    virtual ~MenuAction() = default;
    virtual void execute() = 0;
};