#include "../include/Helpers.hpp"
#include <algorithm>
#include <ranges>

double dummyFunc(double x) {
    return x > 0 ? x : 0;
}

std::string repeatStrFunc(const std::vector<int>& values, const std::string& str) {
    auto repeatCount = values.empty() ? 0 : *std::max_element(values.begin(), values.end());
    return repeatCount > 0 ? std::views::repeat(str, repeatCount) | std::views::join | std::ranges::to<std::string>() : "";
}
