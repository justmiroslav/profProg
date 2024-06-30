package com.pizza;

import static org.junit.Assert.*;
import org.junit.Test;
import java.util.Map;

public class PizzaDirectorTest {

    @Test
    public void testMakePizza() {
        Map<String, Ingredient> ingredients = Map.of(
                "Cheese", new Ingredient(1.0, true, 1),
                "Pepperoni", new Ingredient(1.5, false, 1),
                "Olives", new Ingredient(0.75, false, 1)
        );

        PizzaBuilder builder = new ConcretePizzaBuilder(ingredients);
        PizzaDirector director = new PizzaDirector(builder);
        builder.addIngredient("Pepperoni", 2);

        Pizza pizza = director.makePizza();
        assertEquals(1, pizza.getIngredientCount("Cheese"));
        assertEquals(2, pizza.getIngredientCount("Pepperoni"));
    }
}