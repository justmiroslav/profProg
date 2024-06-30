#pragma once
#include "PizzaBuilder.hpp"

class PizzaDirector {
public:
    explicit PizzaDirector(std::unique_ptr<PizzaBuilder>& builder);
    std::unique_ptr<Pizza> makePizza();

private:
    std::unique_ptr<PizzaBuilder>& pizzaBuilder;
};
