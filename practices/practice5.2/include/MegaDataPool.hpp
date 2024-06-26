#pragma once
#include "MegaData.hpp"
#include <vector>
#include <mutex>

class MegaDataPool {
public:
    static MegaDataPool& getInstance(size_t size = 5);
    [[nodiscard]] MegaData& acquire();
    void release(MegaData& obj);
    [[nodiscard]] size_t getSize();
    [[nodiscard]] size_t getUsedCount();

private:
    explicit MegaDataPool(size_t size);
    MegaDataPool(const MegaDataPool&) = delete;
    MegaDataPool& operator=(const MegaDataPool&) = delete;
    MegaDataPool(MegaDataPool&&) = delete;
    MegaDataPool& operator=(MegaDataPool&&) = delete;

    std::vector<MegaData> dataPool;
    std::vector<bool> isDataUsed;
    std::mutex poolMutex;
};
