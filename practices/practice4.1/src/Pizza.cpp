#include "Pizza.hpp"
#include <print>
#include <algorithm>

Pizza::Pizza(const std::map<std::string, std::pair<double, bool>>& ingredients) {
    std::ranges::for_each(ingredients, [this](const auto& pair) {
        if (pair.second.second) {
            this->ingredients[pair.first] = {pair.second.first, pair.second.second, 1};
        }
    });
}

void Pizza::addIngredient(const std::string& ingredient, double price, bool required, int count) {
    if (ingredients.find(ingredient) != ingredients.end()) {
        std::get<2>(ingredients[ingredient]) += count;
    } else {
        ingredients[ingredient] = {price, required, count};
    }
}

void Pizza::removeIngredient(const std::string &ingredient, int count) {
    std::get<2>(ingredients[ingredient]) -= count;
    if (std::get<2>(ingredients[ingredient]) <= 0) {
        ingredients.erase(ingredient);
    }
}

int Pizza::getIngredientCount(const std::string &ingredient) const {
    if (ingredients.find(ingredient) != ingredients.end()) {
        return std::get<2>(ingredients.at(ingredient));
    }
    return 0;
}

void Pizza::showPizza() const {
    std::println("Pizza ingredients:");
    std::ranges::for_each(ingredients, [](const auto& pair) {
        std::println("Ingredient: {}, price: ${}, count - {}", pair.first, std::get<0>(pair.second), std::get<2>(pair.second));
    });
    std::println("Total price: ${}", calculatePrice());
}

double Pizza::calculatePrice() const {
    double price = 0;
    std::ranges::for_each(ingredients, [&price](const auto& pair) {
        price += std::get<0>(pair.second) * std::get<2>(pair.second);
    });
    return price;
}
