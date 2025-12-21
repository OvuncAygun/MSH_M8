#include "InputHandler.h"

#include <iostream>
#include <limits>

InputHandler::InputHandler() = default;
InputHandler::~InputHandler() = default;

std::string InputHandler::handleSelectionInput() {
    std::string input;
    std::cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input;
}

std::string InputHandler::handleConfigurationInput() {
    std::string input;
    std::getline(std::cin, input);
    return input;
}

void InputHandler::waitForInput() {
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.get();
}