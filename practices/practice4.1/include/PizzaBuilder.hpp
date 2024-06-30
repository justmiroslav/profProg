#pragma once
#include "Pizza.hpp"
#include <memory>

class PizzaBuilder {
public:
    virtual ~PizzaBuilder() = default;
    virtual void addIngredient(const std::string& ingredient, int count) = 0;
    virtual void removeIngredient(const std::string& ingredient, int count) = 0;
    virtual std::unique_ptr<Pizza> getPizza() = 0;
};
