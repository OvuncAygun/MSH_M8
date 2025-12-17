#include "InputHandler.h"

#include <iostream>

InputHandler::InputHandler() = default;
InputHandler::~InputHandler() = default;

std::string InputHandler::handleSelectionInput() {
    std::string input;
    std::cin >> input;
    return input;
}

std::string InputHandler::handleConfigurationInput() {
    std::string input;
    std::getline(std::cin, input);
    return input;
}

void InputHandler::waitForInput() {
    std::cin.get();
}