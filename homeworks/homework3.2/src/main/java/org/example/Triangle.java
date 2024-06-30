package org.example;

import java.util.Map;
import java.util.Optional;

public class Triangle {
    private final double a, b, c;
    private final Map<String, Double> sides;

    public Triangle(double a, double b, double c) {
        if (a <= 0 || b <= 0 || c <= 0) {
            throw new IllegalArgumentException("Sides of a triangle must be positive.");
        } else if (a + b <= c || a + c <= b || b + c <= a) {
            throw new IllegalArgumentException("Invalid sides for a triangle.");
        }
        this.a = a;
        this.b = b;
        this.c = c;
        this.sides = Map.of("a", a, "b", b, "c", c);
    }

    public double calculateArea() {
        double s = 0.5 * (a + b + c);
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }

    public Optional<Double> getHeight(String side) {
        double area = calculateArea();
        if (sides.containsKey(side.toLowerCase())) {
            return Optional.of(2 * area / sides.get(side.toLowerCase()));
        } else {
            return Optional.empty();
        }
    }
}
