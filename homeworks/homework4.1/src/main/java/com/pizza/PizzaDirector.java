package com.pizza;

public class PizzaDirector {
    private final PizzaBuilder pizzaBuilder;

    public PizzaDirector(PizzaBuilder pizzaBuilder) {
        this.pizzaBuilder = pizzaBuilder;
    }

    public Pizza makePizza() {
        return pizzaBuilder.getPizza();
    }
}
