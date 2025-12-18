#pragma once

#include <string>

class IState {
public:
    virtual ~IState() = default;

    virtual std::string getName() const = 0;
};