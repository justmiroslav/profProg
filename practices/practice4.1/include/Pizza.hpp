#pragma once
#include <string>
#include <map>

class Pizza {
public:
    explicit Pizza(const std::map<std::string, std::pair<double, bool>>& ingredients);
    void addIngredient(const std::string& ingredient, double price, bool required, int count);
    void removeIngredient(const std::string& ingredient, int count);
    [[nodiscard]] int getIngredientCount(const std::string& ingredient) const;
    void showPizza() const;
    [[nodiscard]] double calculatePrice() const;

private:
    std::map<std::string, std::tuple<double, bool, int>> ingredients;
};
