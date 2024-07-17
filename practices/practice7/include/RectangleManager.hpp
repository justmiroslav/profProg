#pragma once
#include "Rectangle.hpp"
#include <vector>

class RectangleManager {
public:
    void addRectangle(const Rectangle& rect);
    void printFittingInfo() const;
    void printStatistics() const;
    [[nodiscard]] std::vector<Rectangle> getRectangles() const;

private:
    std::vector<Rectangle> rectangles;
    static constexpr int MAX_RECTANGLES = 5;
};
