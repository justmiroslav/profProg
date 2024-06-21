#include "MyTest.hpp"
#include "ConcretePizzaBuilder.hpp"

void ConcretePizzaBuilderTest(UnitTests& testSuite) {
    testSuite.addTest("ConcretePizzaBuilderAddIngredient",
    [](){
        // Build:
        std::map<std::string, std::pair<double, bool>> ingredients = {
                {"Cheese", {1.0, true}},
                {"Pepperoni", {1.5, false}},
                {"Olives", {0.75, false}}
        };

        // Operate:
        ConcretePizzaBuilder builder(ingredients);
        builder.addIngredient("Ham", 2);

        // Check:
        ASSERT_EQ(builder.getPizza()->getIngredientCount("Ham"), 2)
    });

    testSuite.addTest("ConcretePizzaBuilderRemoveIngredient",
    [](){
        // Build:
        std::map<std::string, std::pair<double, bool>> ingredients = {
                {"Cheese", {1.0, true}},
                {"Pepperoni", {1.5, false}},
                {"Olives", {0.75, false}}
        };

        // Operate:
        ConcretePizzaBuilder builder(ingredients);
        builder.addIngredient("Olives", 2);
        builder.removeIngredient("Olives", 1);

        // Check:
        ASSERT_EQ(builder.getPizza()->getIngredientCount("Olives"), 1)
    });
}
