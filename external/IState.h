#pragma once

#include <string>

class IState {
public:
    virtual ~IState() = default;

    virtual std::string getName() const = 0;
    virtual void setName(const std::string& name) = 0;
};
