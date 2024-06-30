package com.pizza;

public interface PizzaBuilder {
    void addIngredient(String name, int count);
    void removeIngredient(String name, int count);
    Pizza getPizza();
}
