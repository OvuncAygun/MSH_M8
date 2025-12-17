#pragma once

#include <string>

class InputHandler {
public:
    InputHandler();
    ~InputHandler();

    std::string handleSelectionInput();
    std::string handleConfigurationInput();
    void waitForInput();
};