#include "Program.hpp"
#include <print>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <filesystem>

enum Commands {
    ADD = 1,
    REMOVE = 2,
    DONE = 3
};

void Program::run() {
    loadIngredients();

    PizzaBuilder* builder = new ConcretePizzaBuilder(ingredients);
    PizzaDirector director(builder);

    while (true) {
        int command;

        std::println("Enter the command: (1-add, 2-remove, 3-done)");
        std::cin >> command;

        if (command == DONE) break;
        else if (command == ADD) handleAddCommand(builder);
        else if (command == REMOVE) handleRemoveCommand(builder);
        else std::println("Invalid command");
    }

    Pizza* pizza = director.makePizza();
    pizza->showPizza();
    delete pizza;
    delete builder;
}

void Program::loadIngredients() {
    std::ifstream file(ingredientsFile);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file at " << std::filesystem::absolute(ingredientsFile) << std::endl;
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

void Program::handleAddCommand(PizzaBuilder* builder) {
    std::vector<std::string> addedIngredients;
    std::string input;
    int count;

    std::println("Available ingredients to add:");
    std::ranges::for_each(ingredients, [this, &addedIngredients](const auto& pair) {
        if (!pair.second.second && addedCounts[pair.first] < 3) {
            std::println("Ingredient: {}, price: ${}", pair.first, pair.second.first);
            addedIngredients.push_back(pair.first);
        }
    });
    std::println("Enter the ingredient:");
    std::cin >> input;
    if (std::find(addedIngredients.begin(), addedIngredients.end(), input) == addedIngredients.end()) {
        std::println("You can't add this ingredient");
        return;
    }
    std::println("Enter the count:");
    std::cin >> count;
    if (count <= 0 || count > 3 - builder->getPizza()->getIngredientCount(input)) {
        std::println("Invalid count");
        return;
    }
    builder->addIngredient(input, count);
    addedCounts[input] += count;
}

void Program::handleRemoveCommand(PizzaBuilder* builder) {
    std::vector<std::string> removedIngredients;
    std::string input;
    int count;

    std::println("Available ingredients to remove:");
    std::ranges::for_each(ingredients, [this, &removedIngredients](const auto &pair) {
        if (!pair.second.second && addedCounts[pair.first] > 0) {
            std::println("Ingredient: {}, count: {}", pair.first, addedCounts[pair.first]);
            removedIngredients.push_back(pair.first);
        }
    });
    std::println("Enter the ingredient:");
    std::cin >> input;
    if (std::find(removedIngredients.begin(), removedIngredients.end(), input) == removedIngredients.end()) {
        std::println("You can't remove this ingredient");
        return;
    }
    std::println("Enter the count:");
    std::cin >> count;
    if (count <= 0 || count > addedCounts[input]) {
        std::println("Invalid count");
        return;
    }
    builder->removeIngredient(input, count);
    addedCounts[input] -= count;
}
