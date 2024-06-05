package org.example;

import java.util.List;

public class MathOperations {
    public Object calculate(List<Double> arguments) {
        if (arguments.size() != 3) {
            return "Exactly 3 elements are required";
        }
        return makeCalculations(arguments.get(0), arguments.get(1), arguments.get(2));
    }

    public double makeCalculations(double x, double y, double z) {
        double product = x * y * z;
        double sum = x + y + z;

        if (product != 0) {
            return 1 / product;
        } else if (sum != 0) {
            return 1 / sum;
        } else {
            return x + (y + 1) * (z - 1);
        }
    }
}
