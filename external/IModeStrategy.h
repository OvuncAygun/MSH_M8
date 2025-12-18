#pragma once

#include <string>
class IModeStrategy {
public:
    virtual ~IModeStrategy() {}

    virtual std::string getModeName() const = 0;
};