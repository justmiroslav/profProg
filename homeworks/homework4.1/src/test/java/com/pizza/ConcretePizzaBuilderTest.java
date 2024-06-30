package com.pizza;

import static org.junit.Assert.*;
import org.junit.Test;
import java.util.Map;

public class ConcretePizzaBuilderTest {

    @Test
    public void testAddIngredient() {
        Map<String, Ingredient> ingredients = Map.of(
                "Cheese", new Ingredient(1.0, true, 1),
                "Pepperoni", new Ingredient(1.5, false, 1),
                "Olives", new Ingredient(0.75, false, 1)
        );

        ConcretePizzaBuilder builder = new ConcretePizzaBuilder(ingredients);
        builder.addIngredient("Pepperoni", 2);

        assertEquals(2, builder.getPizza().getIngredientCount("Pepperoni"));
    }

    @Test
    public void testRemoveIngredient() {
        Map<String, Ingredient> ingredients = Map.of(
                "Cheese", new Ingredient(1.0, true, 1),
                "Pepperoni", new Ingredient(1.5, false, 1),
                "Olives", new Ingredient(0.75, false, 1)
        );

        ConcretePizzaBuilder builder = new ConcretePizzaBuilder(ingredients);
        builder.addIngredient("Olives", 2);
        builder.removeIngredient("Olives", 1);

        assertEquals(1, builder.getPizza().getIngredientCount("Olives"));
    }
}
