#include "UnitTests.hpp"
#include "Pizza.hpp"

void PizzaTest(UnitTests& testSuite) {

    testSuite.addTest("PizzaConstructionTest",
    [](){
        // Build:
        std::map<std::string, std::pair<double, bool>> ingredients = {
                {"Cheese", {1.0, true}},
                {"Pepperoni", {1.5, false}},
                {"Olives", {0.75, false}}
        };

        // Operate:
        Pizza pizza(ingredients);

        // Check:
        ASSERT_EQ(pizza.getIngredientCount("Cheese"), 1)
        ASSERT_EQ(pizza.getIngredientCount("Pepperoni"), 0)
        ASSERT_EQ(pizza.getIngredientCount("Olives"), 0)
    });

    testSuite.addTest("PizzaAddIngredientTest",
    [](){
        // Build:
        std::map<std::string, std::pair<double, bool>> ingredients = {
                {"Cheese", {1.0, true}},
                {"Pepperoni", {1.5, false}},
                {"Olives", {0.75, false}}
        };

        // Operate:
        Pizza pizza(ingredients);
        pizza.addIngredient("Pepperoni", 1.5, false, 2);

        // Check:
        ASSERT_EQ(pizza.getIngredientCount("Pepperoni"), 2)
    });

    testSuite.addTest("PizzaRemoveIngredientTest",
    []() {
        // Build:
        std::map<std::string, std::pair<double, bool>> ingredients = {
                {"Cheese", {1.0, true}},
                {"Pepperoni", {1.5, false}},
                {"Olives", {0.75, false}}
        };

        // Operate:
        Pizza pizza(ingredients);
        pizza.addIngredient("Olives", 0.75, false, 2);
        pizza.removeIngredient("Olives", 1);

        // Check:
        ASSERT_EQ(pizza.getIngredientCount("Olives"), 1)
    });

    testSuite.addTest("PizzaCalculatePriceTest",
    []() {
        // Build:
        std::map<std::string, std::pair<double, bool>> ingredients = {
                {"Cheese", {1.0, true}},
                {"Pepperoni", {1.5, false}},
                {"Olives", {0.75, false}}
        };

        // Operate:
        Pizza pizza(ingredients);
        pizza.addIngredient("Cheese", 1.0, true, 2);

        // Check:
        ASSERT_EQ(pizza.calculatePrice(), 3.0)
    });
}
