#pragma once
#include "PizzaBuilder.hpp"

class PizzaDirector {
public:
    explicit PizzaDirector(PizzaBuilder* builder);
    Pizza* makePizza();

private:
    PizzaBuilder* pizzaBuilder;
};
