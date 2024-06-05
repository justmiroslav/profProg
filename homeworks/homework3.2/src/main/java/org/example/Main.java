package org.example;

public class Main {
    public static void main(String[] args) {
        if (args.length < 3 || args.length > 4) {
            System.out.println("Usage: java -cp ./src/main/java org.example.Main <side_a> <side_b> <side_c> [side_for_height]");
            System.exit(1);
        }
        try {
            double a = Double.parseDouble(args[0]);
            double b = Double.parseDouble(args[1]);
            double c = Double.parseDouble(args[2]);
            Triangle triangle = new Triangle(a, b, c);

            if (args.length == 3) {
                double area = triangle.calculateArea();
                System.out.println("Area of the triangle: " + area);
                System.exit(0);
            } else {
                String side = args[3];
                double height = triangle.getHeight(side);
                if (height == 0) {
                    System.out.println("Invalid side for height calculation.");
                    System.exit(1);
                }
                System.out.println("Height corresponding to side " + side + ": " + height);
            }
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
            System.exit(1);
        }
    }
}
