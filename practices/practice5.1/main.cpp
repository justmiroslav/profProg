#include "MegaDataPool.hpp"
#include <print>

int main() {
    MegaDataPool pool(5);
    MegaData* obj1;
    MegaData* obj2;

    try {
        obj1 = &pool.acquire();
        obj2 = &pool.acquire();
    } catch (const std::exception& e) {
        std::println("Exception caught: {}", e.what());
        return 1;
    }

    std::println("Acquired obj1 and obj2");

    double* bigArray = obj1->getBigArray();
    bigArray[0] = 2.71;

    float* smallArray = obj2->getSmallArray();
    smallArray[1] = 3.14f;

    std::println("obj1 bigArray first and second elements: {}, {}", bigArray[0], bigArray[1]);
    std::println("obj2 smallArray first and second elements: {}, {}", smallArray[0], smallArray[1]);
    std::println("Pool size: {}, Used size: {}", pool.getSize(), pool.getUsedCount());

    pool.release(*obj1);
    pool.release(*obj2);

    std::println("Released obj1 and obj2");
    std::println("Pool size: {}, Used size: {}", pool.getSize(), pool.getUsedCount());
    return 0;
}
