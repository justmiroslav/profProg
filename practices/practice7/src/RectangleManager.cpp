#include "RectangleManager.hpp"
#include <algorithm>
#include <ranges>
#include <print>

void RectangleManager::addRectangle(const Rectangle& rect) {
    if (rectangles.size() < MAX_RECTANGLES) {
        rectangles.push_back(rect);
    }
}

void RectangleManager::printFittingInfo() const {
    for (const auto& [i, rect1] : std::views::enumerate(rectangles)) {
        for (const auto& [j, rect2] : std::views::enumerate(rectangles)) {
            if (i != j && rect1.canBePlacedInside(rect2)) {
                std::println("Rectangle {} can be placed inside Rectangle {}", i + 1, j + 1);
            }
        }
    }
}

void RectangleManager::printStatistics() const {
    auto areas = rectangles | std::views::transform([](const Rectangle& r) { return r.getArea(); });
    auto [minArea, maxArea] = std::ranges::minmax_element(areas);

    double totalArea = std::ranges::fold_left(areas, 0.0, std::plus<>{});

    std::println("The biggest area: {}", *maxArea);
    std::println("The smallest area: {}", *minArea);
    std::println("Number of rectangles: {}", rectangles.size());
    std::println("Total area of rectangles: {}", totalArea);

    for (const auto& [i, rect] : std::views::enumerate(rectangles)) {
        std::println("The biggest side of rectangle {}: {}", i + 1, rect.getBiggerSide());
    }
}

std::vector<Rectangle> RectangleManager::getRectangles() const {
    return rectangles;
}
