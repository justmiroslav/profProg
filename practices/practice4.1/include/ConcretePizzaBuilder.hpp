#pragma once
#include "PizzaBuilder.hpp"

class ConcretePizzaBuilder : public PizzaBuilder {
public:
    explicit ConcretePizzaBuilder(const std::map<std::string, std::pair<double, bool>>& ingredients);
    ~ConcretePizzaBuilder() override;
    void addIngredient(const std::string& ingredient, int count) override;
    void removeIngredient(const std::string& ingredient, int count) override;
    Pizza* getPizza() override;

private:
    Pizza* pizza;
    std::map<std::string, std::pair<double, bool>> ingredients;
};
