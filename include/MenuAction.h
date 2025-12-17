#pragma once

class MenuAction {
public:
    virtual ~MenuAction() = default;
    virtual void execute() = 0;
};