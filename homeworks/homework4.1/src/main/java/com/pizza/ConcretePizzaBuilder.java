package com.pizza;

import java.util.Map;

public class ConcretePizzaBuilder implements PizzaBuilder {
    private final Pizza pizza;
    private final Map<String, Ingredient> ingredients;

    public ConcretePizzaBuilder(Map<String, Ingredient> ingredients) {
        this.ingredients = ingredients;
        this.pizza = new Pizza(ingredients);
    }

    @Override
    public void addIngredient(String name, int count) {
        Ingredient ingredient = ingredients.get(name);
        if (ingredient != null) {
            pizza.addIngredient(name, ingredient.getPrice(), ingredient.isRequired(), count);
        }
    }

    @Override
    public void removeIngredient(String name, int count) {
        pizza.removeIngredient(name, count);
    }

    @Override
    public Pizza getPizza() {
        return pizza;
    }
}
