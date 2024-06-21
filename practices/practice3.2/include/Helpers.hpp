#pragma once
#include <cmath>

struct RGB {
    double r;
    double g;
    double b;

    RGB(double r, double g, double b);
    [[nodiscard]] RGB generateMagicColor() const;
};

class Triangle {
public:
    Triangle(double a, double b, double c);
    [[nodiscard]] double calculateArea() const;

private:
    double a, b, c;
};
