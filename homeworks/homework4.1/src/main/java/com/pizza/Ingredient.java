package com.pizza;

public class Ingredient {
    private final double price;
    private final boolean required;
    private int count;

    public Ingredient(double price, boolean required, int count) {
        this.price = price;
        this.required = required;
        this.count = count;
    }

    public double getPrice() {
        return price;
    }

    public boolean isRequired() {
        return required;
    }

    public int getCount() {
        return count;
    }

    public void addCount(int count) {
        this.count += count;
    }

    public void removeCount(int count) {
        this.count -= count;
    }
}
