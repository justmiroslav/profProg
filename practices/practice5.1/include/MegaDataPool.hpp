#pragma once
#include "MegaData.hpp"
#include <vector>

class MegaDataPool {
public:
    explicit MegaDataPool(size_t size);
    [[nodiscard]] MegaData& acquire();
    void release(MegaData& obj);
    [[nodiscard]] size_t getSize() const;
    [[nodiscard]] size_t getUsedCount() const;

private:
    std::vector<MegaData> dataPool;
    std::vector<bool> isDataUsed;
};
