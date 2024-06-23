#include "MegaDataPool.hpp"
#include "UnitTests.hpp"

int main() {
    UnitTests testSuite;

    testSuite.addTest("PoolConstructorTest",
    []() {
        // Build:
        size_t size = 5;

        // Operate:
        MegaDataPool pool(size);

        // Check:
        ASSERT_EQ(pool.getUsedCount(), 0)
    });

    testSuite.addTest("PoolAcquireTest",
    []() {
        // Build:
        size_t size = 5;

        // Operate:
        MegaDataPool pool(size);
        auto obj = pool.acquire();

        // Check:
        ASSERT_NEQ(obj, nullptr)
        ASSERT_EQ(pool.getUsedCount(), 1)
    });

    testSuite.addTest("PoolReleaseTest",
    []() {
        // Build:
        size_t size = 5;

        // Operate:
        MegaDataPool pool(size);
        auto obj = pool.acquire();
        pool.release(obj);

        // Check:
        ASSERT_EQ(pool.getUsedCount(), 0)
    });

    testSuite.addTest("PoolAcquireNullptrTest",
    []() {
        // Build:
        size_t size = 1;

        // Operate:
        MegaDataPool pool(size);
        pool.acquire();

        // Check:
        ASSERT_EQ(pool.acquire(), nullptr)
    });

    testSuite.run();
    return 0;
}
