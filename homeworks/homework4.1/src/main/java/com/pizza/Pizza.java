package com.pizza;

import java.util.Map;
import java.util.HashMap;

public class Pizza {
    private final Map<String, Ingredient> ingredients = new HashMap<>();

    public Pizza(Map<String, Ingredient> ingredients) {
        ingredients.forEach((name, ingredient) -> {
            if (ingredient.isRequired()) {
                this.ingredients.put(name, ingredient);
            }
        });
    }

    public void addIngredient(String name, double price, boolean required, int count) {
        ingredients.putIfAbsent(name, new Ingredient(price, required, 0));
        Ingredient ingredient = ingredients.get(name);
        ingredient.addCount(count);
    }

    public void removeIngredient(String name, int count) {
        if (ingredients.containsKey(name)) {
            Ingredient ingredient = ingredients.get(name);
            ingredient.removeCount(count);
            if (ingredient.getCount() <= 0) {
                ingredients.remove(name);
            }
        }
    }

    public int getIngredientCount(String name) {
        return ingredients.getOrDefault(name, new Ingredient(0, false, 0)).getCount();
    }

    public void showPizza() {
        System.out.println("Pizza ingredients:");
        ingredients.forEach((name, ingredient) -> System.out.printf("Ingredient: %s, price: $%.2f, count - %d\n",
                name, ingredient.getPrice(), ingredient.getCount()));
        System.out.printf("Total price: $%.2f\n", calculatePrice());
    }

    public double calculatePrice() {
        return ingredients.values().stream()
                .mapToDouble(ingredient -> ingredient.getPrice() * ingredient.getCount())
                .sum();
    }
}
