#include "Pizza.hpp"
#include <print>
#include <algorithm>

Pizza::Pizza(const std::map<std::string, std::pair<double, bool>>& ingredients) {
    for (const auto& [ingredient, price_selected] : ingredients) {
        if (price_selected.second) {
            this->ingredients[ingredient] = {price_selected.first, price_selected.second, 1};
        }
    }
}

void Pizza::addIngredient(const std::string& ingredient, double price, bool required, int count) {
    if (ingredients.find(ingredient) != ingredients.end()) {
        std::get<COUNT_IDX>(ingredients[ingredient]) += count;
    } else {
        ingredients[ingredient] = {price, required, count};
    }
}

void Pizza::removeIngredient(const std::string &ingredient, int count) {
    std::get<COUNT_IDX>(ingredients[ingredient]) -= count;
    if (std::get<COUNT_IDX>(ingredients[ingredient]) <= 0) {
        ingredients.erase(ingredient);
    }
}

int Pizza::getIngredientCount(const std::string &ingredient) const {
    if (ingredients.find(ingredient) != ingredients.end()) {
        return std::get<COUNT_IDX>(ingredients.at(ingredient));
    }
    return 0;
}

void Pizza::showPizza() const {
    std::println("Pizza ingredients:");
    for (const auto& [ingredient, tuple] : ingredients) {
        std::println("Ingredient: {}, price: ${}, count - {}", ingredient, std::get<PRICE_IDX>(tuple), std::get<COUNT_IDX>(tuple));
    }
    std::println("Total price: ${}", calculatePrice());
}

double Pizza::calculatePrice() const {
    double price = 0;
    for (const auto& [ingredient, tuple] : ingredients) {
        price += std::get<PRICE_IDX>(tuple) * std::get<COUNT_IDX>(tuple);
    }
    return price;
}
