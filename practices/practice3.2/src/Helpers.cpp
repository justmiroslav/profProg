#include "../include/Helpers.hpp"
#include <algorithm>

RGB::RGB(double r, double g, double b) : r(r), g(g), b(b) {}

RGB RGB::generateMagicColor() const {
    if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255) {
        return {-1, -1, -1};
    }

    double new_r = std::clamp(r / 2.0 - 1.0, 0.0, 255.0);
    double new_g = std::clamp(g * 2.0 - 2.0, 0.0, 255.0);

    return {new_r, new_g, b};
}

Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

double Triangle::calculateArea() const {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 0;
    }

    if (a + b <= c || a + c <= b || b + c <= a) {
        return -1;
    }

    double s = 0.5 * (a + b + c);
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
