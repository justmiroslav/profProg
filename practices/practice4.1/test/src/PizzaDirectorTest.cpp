#include "MyTest.hpp"
#include "PizzaDirector.hpp"
#include "ConcretePizzaBuilder.hpp"

void PizzaDirectorTest(UnitTests& testSuite) {
    testSuite.addTest("PizzaDirectorMakePizzaTest",
    [](){
        // Build:
        std::map<std::string, std::pair<double, bool>> ingredients = {
              {"Cheese", {1.0, true}},
              {"Pepperoni", {1.5, false}},
              {"Olives", {0.75, false}}
        };

        // Operate:
        PizzaBuilder* builder = new ConcretePizzaBuilder(ingredients);
        PizzaDirector director(builder);
        builder->addIngredient("Pepperoni", 2);

        // Check:
        ASSERT_EQ(director.makePizza()->getIngredientCount("Cheese"), 1)
        ASSERT_EQ(director.makePizza()->getIngredientCount("Pepperoni"), 2)
    });
}
