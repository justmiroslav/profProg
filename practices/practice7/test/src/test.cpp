#include "UnitTests.hpp"
#include "RectangleManager.hpp"

int main() {
    UnitTests testSuite;

    testSuite.addTest("Rectangle Constructor", []() {
        Rectangle rect(10, 20);
        ASSERT_EQ(rect.getWidth(), 10)
        ASSERT_EQ(rect.getHeight(), 20)
    });

    testSuite.addTest("Rectangle Area", []() {
        Rectangle rect(10, 20);
        ASSERT_EQ(rect.getArea(), 200)
    });

    testSuite.addTest("Rectangle Bigger Side", []() {
        Rectangle rect(10, 20);
        ASSERT_EQ(rect.getBiggerSide(), 20)
    });

    testSuite.addTest("Rectangle canBePlacedInside - True", []() {
        Rectangle rect1(10, 20);
        Rectangle rect2(20, 30);
        ASSERT_EQ(rect1.canBePlacedInside(rect2), true)
    });

    testSuite.addTest("Rectangle canBePlacedInside - False", []() {
        Rectangle rect1(10, 20);
        Rectangle rect2(5, 10);
        ASSERT_EQ(rect1.canBePlacedInside(rect2), false)
    });

    testSuite.addTest("RectangleManager addRectangle", []() {
        RectangleManager manager;
        manager.addRectangle(Rectangle(10, 20));
        ASSERT_EQ(manager.getRectangles().size(), 1)
    });

    testSuite.run();
    return 0;
}