#include "ConcretePizzaBuilder.hpp"

ConcretePizzaBuilder::ConcretePizzaBuilder(const std::map<std::string, std::pair<double, bool>>& ingredients) : ingredients(ingredients) {
    pizza = std::make_unique<Pizza>(ingredients);
}

void ConcretePizzaBuilder::addIngredient(const std::string& ingredient, int count) {
    pizza->addIngredient(ingredient, ingredients[ingredient].first, ingredients[ingredient].second, count);
}

void ConcretePizzaBuilder::removeIngredient(const std::string& ingredient, int count) {
    pizza->removeIngredient(ingredient, count);
}

std::unique_ptr<Pizza> ConcretePizzaBuilder::getPizza() {
    std::unique_ptr<Pizza> oldPizza = std::move(pizza);
    pizza = std::make_unique<Pizza>(ingredients);
    return oldPizza;
}
