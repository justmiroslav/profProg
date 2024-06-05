#include "../include/Helpers.hpp"

Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

double Triangle::calculateArea() const {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 0;
    }
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

RGB generateMagicColor(double r, double g, double b) {
    if (r < 0 || g < 0 || b < 0) {
        return {0, 0, 0};
    }
    if (r > 255 || g > 255 || b > 255) {
        return {-1, -1, -1};
    }

    double new_r, new_g, new_b;

    if (r / 2.0 - 1.0 < 0) {
        new_r = 0;
    } else {
        new_r = r / 2.0 - 1.0;
    }

    if (g * 2.0 - 2.0 < 0) {
        new_g = 0;
    } else {
        new_g = g * 2.0 - 2.0;
    }

    new_b = b;

    return {new_r, new_g, new_b};
}
