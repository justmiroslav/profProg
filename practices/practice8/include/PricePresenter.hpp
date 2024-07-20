#pragma once
#include <concepts>
#include <print>

template <typename T>
concept Priceable = requires(T t) {
    { t.getCoefficient() } -> std::convertible_to<double>;
    { t.getBasePrice() } -> std::convertible_to<double>;
};

template<size_t PRIORITY>
class PricePresenter {
public:
    template<Priceable T1, Priceable T2>
    static void printTotalPrice(const T1& obj1, const T2& obj2) {
        double totalPrice = PRIORITY * obj1.getCoefficient() * obj1.getBasePrice() + obj2.getCoefficient() * obj2.getBasePrice();
        std::println("Total price: {:.2f}", totalPrice);
    }
};
