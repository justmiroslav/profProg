#include "RectangleManager.hpp"
#include <iostream>
#include <print>
#include <sstream>

bool isInputValid(const std::string& input, double& width, double& height) {
    std::istringstream iss(input);
    iss >> std::ws;
    if (!(iss >> width)) {
        return false;
    }
    iss >> std::ws;
    if (!(iss >> height)) {
        return false;
    }
    std::string rest;
    if (iss >> rest) {
        return false;
    }
    return width >= 0 && height >= 0;
}

int main() {
    RectangleManager manager;

    for (int i = 1; i <= 5; ++i) {
        std::string input;
        double width, height;

        while (true) {
            std::println("Enter rectangle {} (width height):", i);
            std::getline(std::cin, input);
            if (isInputValid(input, width, height)) {
                manager.addRectangle(Rectangle(width, height));
                break;
            } else {
                std::println("Invalid input. Please enter two non-negative numbers.");
            }
        }
    }

    manager.printFittingInfo();
    manager.printStatistics();
    return 0;
}
