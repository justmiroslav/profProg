#include "Program.hpp"
#include <print>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

enum Commands {
    ADD = 1,
    REMOVE = 2,
    DONE = 3
};

void Program::run() {
    loadIngredients();

    std::unique_ptr<PizzaBuilder> builder = std::make_unique<ConcretePizzaBuilder>(ingredients);
    PizzaDirector director(builder);

    while (true) {
        std::string commandStr;
        int command;

        std::println("Enter the command: (1-add, 2-remove, 3-done)");
        std::getline(std::cin, commandStr);
        commandStr.erase(remove_if(commandStr.begin(), commandStr.end(), isspace), commandStr.end());

        try {
            command = std::stoi(commandStr);
        } catch (...) {
            std::println("Enter a number");
            continue;
        }

        if (command == DONE) break;
        else if (command == ADD) handleAddCommand(builder);
        else if (command == REMOVE) handleRemoveCommand(builder);
        else std::println("Invalid number");
    }

    std::unique_ptr<Pizza> pizza = director.makePizza();
    pizza->showPizza();
}

void Program::loadIngredients() {
    std::ifstream file(ingredientsFile);

    if (!file.is_open()) {
        std::println("Failed to open the file {}", ingredientsFile);
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.rfind(',');
        std::string ingredient = line.substr(0, pos1);
        double price = std::stod(line.substr(pos1 + 1, pos2 - pos1 - 1));
        bool required = line.substr(pos2 + 1) == "true";
        ingredients[ingredient] = {price, required};
        addedCounts[ingredient] = 0;
    }

    file.close();
}

void Program::handleAddCommand(std::unique_ptr<PizzaBuilder>& builder) {
    std::vector<std::string> addedIngredients;
    std::println("Available ingredients to add:");
    for (const auto& [ingredient, pair] : ingredients) {
        if (!pair.second && addedCounts[ingredient] < 3) {
            std::println("Ingredient: {}, price: ${}", ingredient, pair.first);
            addedIngredients.push_back(ingredient);
        }
    }

    if (addedIngredients.empty()) {
        std::println("No ingredients to add");
        return;
    }

    std::string input;
    std::println("Enter the ingredient:");
    std::getline(std::cin, input);
    input.erase(remove_if(input.begin(), input.end(), isspace), input.end());

    if (input.empty() || std::find(addedIngredients.begin(), addedIngredients.end(), input) == addedIngredients.end()) {
        std::println("You can't add this ingredient");
        return;
    }

    std::string countStr;
    int count;
    std::println("Enter the count:");
    std::getline(std::cin, countStr);
    countStr.erase(remove_if(countStr.begin(), countStr.end(), isspace), countStr.end());

    try {
        count = std::stoi(countStr);
    } catch (...) {
        std::println("Enter a number");
        return;
    }

    if (count <= 0 || count > 3 - builder->getPizza()->getIngredientCount(input)) {
        std::println("Invalid count");
        return;
    }
    builder->addIngredient(input, count);
    addedCounts[input] += count;
}

void Program::handleRemoveCommand(std::unique_ptr<PizzaBuilder>& builder) {
    std::vector<std::string> removedIngredients;
    std::println("Available ingredients to remove:");
    for (const auto& [ingredient, pair] : ingredients) {
        if (!pair.second && addedCounts[ingredient] > 0) {
            std::println("Ingredient: {}, count: {}", ingredient, addedCounts[ingredient]);
            removedIngredients.push_back(ingredient);
        }
    }

    if (removedIngredients.empty()) {
        std::println("No ingredients to remove");
        return;
    }

    std::string input;
    std::println("Enter the ingredient:");
    std::getline(std::cin, input);
    input.erase(remove_if(input.begin(), input.end(), isspace), input.end());

    if (input.empty() || std::find(removedIngredients.begin(), removedIngredients.end(), input) == removedIngredients.end()) {
        std::println("You can't remove this ingredient");
        return;
    }

    std::string countStr;
    int count;
    std::println("Enter the count:");

    std::getline(std::cin, countStr);
    countStr.erase(remove_if(countStr.begin(), countStr.end(), isspace), countStr.end());

    try {
        count = std::stoi(countStr);
    } catch (...) {
        std::println("Enter a number");
        return;
    }

    if (count <= 0 || count > addedCounts[input]) {
        std::println("Invalid count");
        return;
    }
    builder->removeIngredient(input, count);
    addedCounts[input] -= count;
}
