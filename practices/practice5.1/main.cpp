#include "MegaDataPool.hpp"
#include <print>

int main() {
    MegaDataPool pool(5);

    try {
        auto obj1 = pool.acquire();
        auto obj2 = pool.acquire();

        std::println("Acquired obj1 and obj2");

        double *bigArray = obj1->getBigArray();
        bigArray[0] = 2.71;

        float* smallArray = obj2->getSmallArray();
        smallArray[1] = 3.14f;

        std::println("obj1 bigArray first element: {}", bigArray[0]);
        std::println("obj2 smallArray second element: {}", smallArray[1]);
        std::println("Pool size: {}, Used size: {}", pool.getSize(), pool.getUsedCount());

        pool.release(obj1);
        pool.release(obj2);

        std::println("Released obj1 and obj2");
        std::println("Pool size: {}, Used size: {}", pool.getSize(), pool.getUsedCount());
    } catch (const std::exception& e) {
        std::println("Exception caught: {}", e.what());
    }
    return 0;
}
