#include "../include/Helpers.hpp"
#include <algorithm>

double dummyFunc(double x) {
    return x > 0 ? x : 0;
}

std::string repeatStrFunc(const std::vector<int>& values, const std::string& str) {
    if (values.empty()) {
        return "Empty vector";
    }

    std::string result;
    int max = *std::max_element(values.begin(), values.end());

    if (max < 0) {
        return "Negative value";
    }

    if (max == 0) {
        return "";
    }

    for (int i = 0; i < max; i++) {
        result += str;
    }

    return result;
}
