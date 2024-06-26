#pragma once
#include "PizzaBuilder.hpp"

class ConcretePizzaBuilder : public PizzaBuilder {
public:
    explicit ConcretePizzaBuilder(const std::map<std::string, std::pair<double, bool>>& ingredients);
    void addIngredient(const std::string& ingredient, int count) override;
    void removeIngredient(const std::string& ingredient, int count) override;
    [[nodiscard]] std::unique_ptr<Pizza> getPizza() override;

private:
    std::unique_ptr<Pizza> pizza;
    std::map<std::string, std::pair<double, bool>> ingredients;
};
