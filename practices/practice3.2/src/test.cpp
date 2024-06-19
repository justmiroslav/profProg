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
        ASSERT_EQ(result, 6.0)
    });

    testSuite.addTest("Dummy_test2",
    [](){
        // Build:
        Triangle triangle(4.0, 0.0, -6.0);

        // Operate:
        auto result = triangle.calculateArea();

        // Check:
        ASSERT_EQ(result, 0.0)
    });

    testSuite.addTest("Dummy_test3",
    [](){
        // Build:
        Triangle triangle(4.0, 4.0, 10.0);

        // Operate:
        auto result = triangle.calculateArea();

        // Check:
        ASSERT_EQ(result, -1.0)
    });

    testSuite.addTest("RGB_test1",
    [](){
        // Build:
        RGB RGB(255.0, 255.0, 255.0);

        // Operate:
        auto result = RGB.generateMagicColor();

        // Check:
        ASSERT_EQ(result.r, 126.5)
        ASSERT_EQ(result.g, 255.0)
        ASSERT_EQ(result.b, 255.0)
    });

    testSuite.addTest("RGB_test2",
    [](){
        // Build:
        RGB RGB(0.0, 25.0, 255.0);

        // Operate:
        auto result = RGB.generateMagicColor();

        // Check:
        ASSERT_EQ(result.r, 0.0)
        ASSERT_EQ(result.g, 48.0)
        ASSERT_EQ(result.b, 255.0)
    });

    testSuite.addTest("RGB_test3",
    [](){
        // Build:
        RGB RGB(-25.0, 25.0, 255.0);

        // Operate:
        auto result = RGB.generateMagicColor();

        // Check:
        ASSERT_EQ(result.r, -1.0)
        ASSERT_EQ(result.g, -1.0)
        ASSERT_EQ(result.b, -1.0)
    });

    testSuite.addTest("RGB_test4",
    [](){
        // Build:
        RGB RGB(2255.0, 25.0, 255.0);

        // Operate:
        auto result = RGB.generateMagicColor();

        // Check:
        ASSERT_EQ(result.r, -1.0)
        ASSERT_EQ(result.g, -1.0)
        ASSERT_EQ(result.b, -1.0)
    });

    testSuite.run();
}