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
        MegaData* obj = &pool.acquire();

        // Check:
        ASSERT_EQ(obj->getBigArray()[0], 42.0)
        ASSERT_EQ(pool.getUsedCount(), 1)
    });

    testSuite.addTest("PoolReleaseTest",
    []() {
        // Build:
        size_t size = 5;

        // Operate:
        MegaDataPool pool(size);
        MegaData* obj = &pool.acquire();
        pool.release(*obj);

        // Check:
        ASSERT_EQ(pool.getUsedCount(), 0)
    });

    testSuite.run();
    return 0;
}
