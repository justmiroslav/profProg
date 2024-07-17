#pragma once

class Rectangle {
public:
    explicit Rectangle(double width = 0.0, double height = 0.0);
    [[nodiscard]] double getArea() const;
    [[nodiscard]] double getBiggerSide() const;
    [[nodiscard]] bool canBePlacedInside(const Rectangle& other) const;
    [[nodiscard]] double getWidth() const;
    [[nodiscard]] double getHeight() const;

private:
    double width;
    double height;
};
