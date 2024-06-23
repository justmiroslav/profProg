#pragma once
#include "MegaData.hpp"
#include <vector>

class MegaDataPool {
public:
    MegaDataPool(size_t size);
    MegaData* acquire();
    void release(MegaData* obj);
    size_t getSize() const;
    size_t getUsedCount() const;

private:
    std::vector<MegaData> dataPool;
    std::vector<bool> isDataUsed;
};
