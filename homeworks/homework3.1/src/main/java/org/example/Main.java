package org.example;

import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main( String[] args ) {
        if (args.length != 3) {
            System.out.println("Usage: java -cp src Main <x> <y> <z>");
            System.exit(1);
        }
        try {
            List<Double> values = Arrays.asList(Double.parseDouble(args[0]), Double.parseDouble(args[1]), Double.parseDouble(args[2]));
            MathOperations operations = new MathOperations();
            Object result = operations.calculate(values);
            System.out.println("Result: " + result);
        } catch (NumberFormatException e) {
            System.out.println("Please enter valid numbers.");
            System.exit(1);
        }
    }
}
