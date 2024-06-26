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
        std::unique_ptr<PizzaBuilder> builder = std::make_unique<ConcretePizzaBuilder>(ingredients);
        PizzaDirector director(builder);
        builder->addIngredient("Pepperoni", 2);
        std::unique_ptr<Pizza> pizza = director.makePizza();

        // Check:
        ASSERT_EQ(pizza->getIngredientCount("Cheese"), 1)
        ASSERT_EQ(pizza->getIngredientCount("Pepperoni"), 2)
    });
}
