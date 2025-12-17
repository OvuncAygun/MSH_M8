#pragma once

#include "MenuAction.h"

class GetHomeStatusAction : public MenuAction {
public:
    GetHomeStatusAction();
    ~GetHomeStatusAction();

    void execute() override;
};