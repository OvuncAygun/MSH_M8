#pragma once

#include <string>
class IModeStrategy {
public:
    virtual ~IModeStrategy() {}

    virtual void configureDevices() = 0;

    virtual std::string getModeName() const = 0;
};