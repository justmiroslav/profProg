#include "../include/Helpers.hpp"
#include "../include/UnitTests.hpp"

int main() {
    UnitTests testSuite;

    testSuite.addTest("Dummy_test1",
    [](){
        // Build:
        double value = -4.0;

        // Operate:
        auto result = dummyFunc(value);

        // Check:
        ASSERT_EQ(result, 0.0)
    });

    testSuite.addTest("Dummy_test2",
    [](){
        // Build:
        double value = 4.0;

        // Operate:
        auto result = dummyFunc(value);

        // Check:
        ASSERT_EQ(result, 4.0)
    });

    testSuite.addTest("Dummy_test3",
    [](){
        // Build:
        double value = 0.4;

        // Operate:
        auto result = dummyFunc(value);

        // Check:
        ASSERT_EQ(result, 0.4)
    });

    testSuite.addTest("RepeatStr_test1",
    [](){
        // Build:
        std::vector<int> values = {1, 2, 3};
        std::string str = "a";

        // Operate:
        auto result = repeatStrFunc(values, str);

        // Check:
        ASSERT_EQ(result, "aaa")
    });

    testSuite.addTest("RepeatStr_test2",
    [](){
        // Build:
        std::vector<int> values = {8, 11, 4, 5};
        std::string str = "b";

        // Operate:
        auto result = repeatStrFunc(values, str);

        // Check:
        ASSERT_EQ(result, "bbbbbbbbbbb")
    });

    testSuite.addTest("RepeatStr_test3",
    [](){
        // Build:
        std::vector<int> values = {-23, -1, -5};
        std::string str = "c";

        // Operate:
        auto result = repeatStrFunc(values, str);

        // Check:
        ASSERT_EQ(result, "")
    });

    testSuite.addTest("RepeatStr_test4",
    [](){
        // Build:
        std::vector<int> values = {};
        std::string str = "d";

        // Operate:
        auto result = repeatStrFunc(values, str);

        // Check:
        ASSERT_EQ(result, "")
    });

    testSuite.addTest("RepeatStr_test5",
    [](){
        // Build:
        std::vector<int> values = {0, 0, 0};
        std::string str = "e";

        // Operate:
        auto result = repeatStrFunc(values, str);

        // Check:
        ASSERT_EQ(result, "")
    });

    testSuite.run();
}
