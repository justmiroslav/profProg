#include "MegaData.hpp"
#include <algorithm>

MegaData::MegaData() {
    reset();
}

void MegaData::reset() {
    std::ranges::fill(smallArray, DEFAULT_VALUE);
    std::ranges::fill(bigArray, DEFAULT_VALUE);
}

double* MegaData::getBigArray() {
    return bigArray;
}

float* MegaData::getSmallArray() {
    return smallArray;
}
