#pragma once

class Milk {
public:
    Milk(double coefficient, double basePrice) : coefficient(coefficient), basePrice(basePrice) {}
    [[nodiscard]] double getCoefficient() const { return coefficient; }
    [[nodiscard]] double getBasePrice() const { return basePrice; }

private:
    double coefficient;
    double basePrice;
};

class Cookies {
public:
    Cookies(double coefficient, double basePrice) : coefficient(coefficient), basePrice(basePrice) {}
    [[nodiscard]] double getCoefficient() const { return coefficient; }
    [[nodiscard]] double getBasePrice() const { return basePrice; }

private:
    double coefficient;
    double basePrice;
};

class Pineapple {
public:
    Pineapple(double coefficient, double basePrice) : coefficient(coefficient), basePrice(basePrice) {}
    [[nodiscard]] double getCoefficient() const { return coefficient; }
    [[nodiscard]] double getBasePrice() const { return basePrice; }

private:
    double coefficient;
    double basePrice;
};
