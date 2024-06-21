#pragma once
#include "Pizza.hpp"

class PizzaBuilder {
public:
    virtual ~PizzaBuilder() = default;
    virtual void addIngredient(const std::string& ingredient, int count) = 0;
    virtual void removeIngredient(const std::string& ingredient, int count) = 0;
    virtual Pizza* getPizza() = 0;
};
