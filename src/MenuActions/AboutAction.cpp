#include "AboutAction.h"
#include "MenuDisplayer.h"
#include "InputHandler.h"

AboutAction::AboutAction() = default;
AboutAction::~AboutAction() = default;

void AboutAction::execute() {
    MenuDisplayer menuDisplayer;
    InputHandler inputHandler;
    menuDisplayer.showFormattedText(
        "MSH Home Automation System\n"
        "Version: 1.0.0\n"
        "Developed by: Your Name\n"
        "This application allows you to manage and control your home automation devices easily.\n"
        "For more information, visit our website or contact support.\n");
}