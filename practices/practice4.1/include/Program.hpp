#pragma once
#include "PizzaDirector.hpp"
#include "ConcretePizzaBuilder.hpp"

class Program {
public:
    void run();

private:
    void loadIngredients();
    void handleAddCommand(PizzaBuilder* builder);
    void handleRemoveCommand(PizzaBuilder* builder);

    std::map<std::string, std::pair<double, bool>> ingredients;
    std::map<std::string, int> addedCounts;
    const std::string ingredientsFile = "data/ing.txt";
};
