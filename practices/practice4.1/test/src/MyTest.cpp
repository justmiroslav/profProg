#include "MyTest.hpp"

int main() {
    UnitTests testSuite;

    PizzaTest(testSuite);
    ConcretePizzaBuilderTest(testSuite);
    PizzaDirectorTest(testSuite);

    testSuite.run();
    return 0;
}
