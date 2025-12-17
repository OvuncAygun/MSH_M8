#pragma once

#include "DeviceCreationType.h"

#include <string>
#include <iostream>
#include <vector>

class MenuDisplayer {
public:
    MenuDisplayer();
    ~MenuDisplayer();

    void showMainMenu();

    void showText(std::string text);

    void showFormattedText(std::string text);

    std::vector<std::string> getDeviceCreationConfigNames(DeviceCreationType type);
};