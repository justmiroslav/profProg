#include "MegaData.hpp"
#include <algorithm>

MegaData::MegaData() {
    reset();
}

void MegaData::reset() {
    std::ranges::fill(smallArray, 42.0f);
    std::ranges::fill(bigArray, 42.0);
}

double* MegaData::getBigArray() {
    return bigArray;
}

float* MegaData::getSmallArray() {
    return smallArray;
}
