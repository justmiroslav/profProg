#include "MegaDataPool.hpp"
#include <algorithm>
#include <sstream>

MegaDataPool::MegaDataPool(size_t size) : dataPool(size), isDataUsed(size, false) {}

MegaData& MegaDataPool::acquire() {
    for (size_t i = 0; i < dataPool.size(); ++i) {
        if (!isDataUsed[i]) {
            isDataUsed[i] = true;
            return dataPool[i];
        }
    }
    throw std::runtime_error("No available data objects in the pool");
}

void MegaDataPool::release(MegaData& obj) {
    for (size_t i = 0; i < dataPool.size(); ++i) {
        if (&dataPool[i] == &obj) {
            isDataUsed[i] = false;
            return;
        }
    }
}

size_t MegaDataPool::getSize() const {
    return dataPool.size();
}

size_t MegaDataPool::getUsedCount() const {
    return std::ranges::count(isDataUsed, true);
}
