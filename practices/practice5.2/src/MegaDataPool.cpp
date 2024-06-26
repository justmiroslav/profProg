#include "MegaDataPool.hpp"
#include <algorithm>

MegaDataPool::MegaDataPool(size_t size) : dataPool(size), isDataUsed(size, false) {}

MegaDataPool& MegaDataPool::getInstance(size_t size) {
    static MegaDataPool instance(size);
    return instance;
}

MegaData& MegaDataPool::acquire() {
    std::lock_guard<std::mutex> lock(poolMutex);
    for (size_t i = 0; i < dataPool.size(); ++i) {
        if (!isDataUsed[i]) {
            isDataUsed[i] = true;
            return dataPool[i];
        }
    }
    throw std::runtime_error("No available data objects in the pool");
}

void MegaDataPool::release(MegaData& obj) {
    std::lock_guard<std::mutex> lock(poolMutex);
    for (size_t i = 0; i < dataPool.size(); ++i) {
        if (&dataPool[i] == &obj) {
            isDataUsed[i] = false;
            return;
        }
    }
}

size_t MegaDataPool::getSize() {
    std::lock_guard<std::mutex> lock(poolMutex);
    return dataPool.size();
}

size_t MegaDataPool::getUsedCount() {
    std::lock_guard<std::mutex> lock(poolMutex);
    return std::ranges::count(isDataUsed, true);
}
