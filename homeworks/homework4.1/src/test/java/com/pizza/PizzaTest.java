package com.pizza;

import static org.junit.Assert.*;
import org.junit.Test;
import java.util.Map;

public class PizzaTest {

    @Test
    public void testPizzaConstruction() {
        Map<String, Ingredient> ingredients = Map.of(
                "Cheese", new Ingredient(1.0, true, 1),
                "Pepperoni", new Ingredient(1.5, false, 1),
                "Olives", new Ingredient(0.75, false, 1)
        );

        Pizza pizza = new Pizza(ingredients);

        assertEquals(1, pizza.getIngredientCount("Cheese"));
        assertEquals(0, pizza.getIngredientCount("Pepperoni"));
        assertEquals(0, pizza.getIngredientCount("Olives"));
    }

    @Test
    public void testPizzaAddIngredient() {
        Map<String, Ingredient> ingredients = Map.of(
                "Cheese", new Ingredient(1.0, true, 1),
                "Pepperoni", new Ingredient(1.5, false, 1),
                "Olives", new Ingredient(0.75, false, 1)
        );

        Pizza pizza = new Pizza(ingredients);
        pizza.addIngredient("Pepperoni", 1.5, false, 2);

        assertEquals(2, pizza.getIngredientCount("Pepperoni"));
    }

    @Test
    public void testPizzaRemoveIngredient() {
        Map<String, Ingredient> ingredients = Map.of(
                "Cheese", new Ingredient(1.0, true, 1),
                "Pepperoni", new Ingredient(1.5, false, 1),
                "Olives", new Ingredient(0.75, false, 1)
        );

        Pizza pizza = new Pizza(ingredients);
        pizza.addIngredient("Olives", 0.75, false, 2);
        pizza.removeIngredient("Olives", 1);

        assertEquals(1, pizza.getIngredientCount("Olives"));
    }

    @Test
    public void testPizzaCalculatePrice() {
        Map<String, Ingredient> ingredients = Map.of(
                "Cheese", new Ingredient(1.0, true, 1),
                "Pepperoni", new Ingredient(1.5, false, 1),
                "Olives", new Ingredient(0.75, false, 1)
        );

        Pizza pizza = new Pizza(ingredients);
        pizza.addIngredient("Cheese", 1.0, true, 2);
        assertEquals(3.0, pizza.calculatePrice(), 0.0001);
    }
}
