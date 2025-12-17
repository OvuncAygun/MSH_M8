#include "MenuDisplayer.h"

MenuDisplayer::MenuDisplayer() = default;
MenuDisplayer::~MenuDisplayer() = default;

void MenuDisplayer::showMainMenu() {
    std::cout << "MY SWEET HOME (MSH)" << std::endl;
    std::cout << "[1] Get Home Status" << std::endl;
    std::cout << "[2] Add Device" << std::endl;
    std::cout << "[3] Remove Device" << std::endl;
    std::cout << "[4] Power on Device" << std::endl;
    std::cout << "[5] Power off Device" << std::endl;
    std::cout << "[6] Change Mode" << std::endl;
    std::cout << "[7] Change State" << std::endl;
    std::cout << "[8] Manual" << std::endl;
    std::cout << "[9] About" << std::endl;
    std::cout << "[10] Shutdown" << std::endl;
}

void MenuDisplayer::showText(std::string text) {
    std::cout << text << std::endl;
}

void MenuDisplayer::showFormattedText(std::string text) {
    std::cout << text;
}

std::vector<std::string> MenuDisplayer::getDeviceCreationConfigNames(DeviceCreationType type) {
    std::vector<std::string> configNames;

    switch(type) {
        case DEVICE_LIGHT:
            configNames = {"Name", "Color", "Illum (%)"};
            break;
        case DEVICE_DETECTOR:
            configNames = {"Name (S&G Detector)"};
            break;
        case DEVICE_CAMERA:
            configNames = {"Motion Detection (ON/OFF)", "FPS", "Night Vision (YES/NO)"};
            break;
        case DEVICE_TV:
            configNames = {"Model (Samsung/LG)"};
            break;
        default:
            break;
    }

    return configNames;
}