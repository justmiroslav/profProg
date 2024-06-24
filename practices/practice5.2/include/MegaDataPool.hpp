#pragma once
#include "MegaData.hpp"
#include <vector>
#include <mutex>

class MegaDataPool {
public:
    static MegaDataPool& getInstance(size_t size = 5);
    MegaData* acquire();
    void release(MegaData* obj);
    size_t getSize();
    size_t getUsedCount();

private:
    explicit MegaDataPool(size_t size);
    MegaDataPool(const MegaDataPool&) = delete;
    MegaDataPool& operator=(const MegaDataPool&) = delete;

    std::vector<MegaData> dataPool;
    std::vector<bool> isDataUsed;
    std::mutex poolMutex;
};
