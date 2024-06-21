#include "ConcretePizzaBuilder.hpp"

ConcretePizzaBuilder::ConcretePizzaBuilder(const std::map<std::string, std::pair<double, bool>>& ingredients) : ingredients(ingredients) {
    pizza = new Pizza(ingredients);
}

ConcretePizzaBuilder::~ConcretePizzaBuilder() {
    delete pizza;
}

void ConcretePizzaBuilder::addIngredient(const std::string& ingredient, int count) {
    pizza->addIngredient(ingredient, ingredients[ingredient].first, ingredients[ingredient].second, count);
}

void ConcretePizzaBuilder::removeIngredient(const std::string& ingredient, int count) {
    pizza->removeIngredient(ingredient, count);
}

Pizza* ConcretePizzaBuilder::getPizza() {
    return pizza;
}
