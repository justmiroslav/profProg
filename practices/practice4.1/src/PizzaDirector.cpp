#include "../include/PizzaDirector.hpp"

PizzaDirector::PizzaDirector(std::unique_ptr<PizzaBuilder>& builder) : pizzaBuilder(builder) {}

std::unique_ptr<Pizza> PizzaDirector::makePizza() {
    return pizzaBuilder->getPizza();
}
