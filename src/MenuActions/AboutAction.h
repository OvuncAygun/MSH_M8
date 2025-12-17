#pragma once

#include "MenuAction.h"

class AboutAction : public MenuAction {
public:
    AboutAction();
    ~AboutAction();

    void execute() override;
};