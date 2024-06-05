package org.example;

import java.util.Map;

public class Triangle {
    private final double a, b, c;
    private final Map<String, Double> sides;

    public Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.sides = Map.of("a", a, "b", b, "c", c);
    }

    public double calculateArea() {
        if (a <= 0 || b <= 0 || c <= 0) {
            return 0;
        }
        double s = (a + b + c) / 2.0;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }

    public double getHeight(String side) {
        double area = calculateArea();
        if (sides.containsKey(side.toLowerCase())) {
            return 2 * area / sides.get(side.toLowerCase());
        } else {
            return 0;
        }
    }
}
