#include "../include/UnitTests.hpp"
#include "../include/Helpers.hpp"

int main() {
    UnitTests testSuite;

    testSuite.addTest("Dummy_test1",
    [](){
        // Build:
        Triangle triangle(3.0, 4.0, 5.0);

        // Operate:
        auto result = triangle.calculateArea();

        // Check:
        ASSERT_EQ(result, 6.0);
    });

    testSuite.addTest("Dummy_test2",
    [](){
        // Build:
        Triangle triangle(4.0, 0.0, -6.0);

        // Operate:
        auto result = triangle.calculateArea();

        // Check:
        ASSERT_EQ(result, 0.0);
    });

    testSuite.addTest("RGB_test1",
    [](){
        // Build:
        double r = 255.0;
        double g = 255.0;
        double b = 255.0;

        // Operate:
        auto result = generateMagicColor(r, g, b);

        // Check:
        ASSERT_EQ(result.r, 126.5);
        ASSERT_EQ(result.g, 508.0);
        ASSERT_EQ(result.b, 255.0);
    });

    testSuite.addTest("RGB_test2",
    [](){
        // Build:
        double r = 0.0;
        double g = 25.0;
        double b = 255.0;

        // Operate:
        auto result = generateMagicColor(r, g, b);

        // Check:
        ASSERT_EQ(result.r, 0.0);
        ASSERT_EQ(result.g, 48.0);
        ASSERT_EQ(result.b, 255.0);
    });

    testSuite.addTest("RGB_test3",
    [](){
        // Build:
        double r = -25.0;
        double g = 25.0;
        double b = 255.0;

        // Operate:
        auto result = generateMagicColor(r, g, b);

        // Check:
        ASSERT_EQ(result.r, 0.0);
        ASSERT_EQ(result.g, 0.0);
        ASSERT_NEQ(result.b, 255.0);
    });

    testSuite.addTest("RGB_test4",
    [](){
        // Build:
        double r = 2255.0;
        double g = 25.0;
        double b = 255.0;

        // Operate:
        auto result = generateMagicColor(r, g, b);

        // Check:
        ASSERT_EQ(result.r, -1.0);
        ASSERT_EQ(result.g, -1.0);
        ASSERT_EQ(result.b, -1.0);
    });

    testSuite.run();
}