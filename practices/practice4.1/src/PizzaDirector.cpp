#include "../include/PizzaDirector.hpp"

PizzaDirector::PizzaDirector(PizzaBuilder* builder) : pizzaBuilder(builder) {}

Pizza* PizzaDirector::makePizza() {
    return pizzaBuilder->getPizza();
}
