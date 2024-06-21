package com.pizza;

import java.io.*;
import java.nio.file.*;
import java.util.*;

public class Program {
    private final Map<String, Ingredient> ingredients = new HashMap<>();
    private final Map<String, Integer> addedCounts = new HashMap<>();
    private static final String INGREDIENTS_FILE = "data/ing.txt";

    public void run() {
        loadIngredients();

        Scanner scanner = new Scanner(System.in);
        System.out.println("Do you want a default pizza or create your own? (default/custom)");
        String choice = scanner.nextLine().trim().toLowerCase();
        Pizza pizza;
        String pizzaName = null;

        if (choice.equals("default")) {
            pizzaName = chooseDefaultPizza(scanner);
            if (pizzaName == null) return;
            pizza = loadDefaultPizza(pizzaName);
        } else if (choice.equals("custom")) {
            pizza = createCustomPizza(scanner);
        } else {
            System.out.println("Invalid choice");
            return;
        }

        if (pizza != null) {
            if (pizzaName != null) {
                System.out.println("You have chosen the pizza: " + pizzaName);
            }
            pizza.showPizza();
        }
    }

    private void loadIngredients() {
        try (BufferedReader reader = Files.newBufferedReader(Paths.get(INGREDIENTS_FILE))) {
            reader.lines().forEach(line -> {
                String[] parts = line.split(",");
                String name = parts[0];
                double price = Double.parseDouble(parts[1]);
                boolean required = Boolean.parseBoolean(parts[2]);
                ingredients.put(name, new Ingredient(price, required, 1));
                addedCounts.put(name, 0);
            });
        } catch (IOException e) {
            System.err.println("Failed to load ingredients: " + e.getMessage());
        }
    }

    private String chooseDefaultPizza(Scanner scanner) {
        Map<String, List<String>> defaultPizzas = setupDefaultPizzas();

        System.out.println("Available default pizzas:");
        defaultPizzas.forEach((name, ingredients) -> System.out.printf("Pizza: %s, ingredients: %s\n", name, String.join(", ", ingredients)));
        System.out.println("Enter the name of the pizza: ");

        String input = scanner.nextLine().trim();
        if (!defaultPizzas.containsKey(input)) {
            System.out.println("Invalid pizza name");
            return null;
        }

        return input;
    }

    private Map<String, List<String>> setupDefaultPizzas() {
        Map<String, List<String>> defaultPizzas = new HashMap<>();
        defaultPizzas.put("Margherita", Arrays.asList("Pizza Base", "Tomato Sauce", "Mozzarella Cheese", "Basil"));
        defaultPizzas.put("Pepperoni", Arrays.asList("Pizza Base", "Tomato Sauce", "Mozzarella Cheese", "Pepperoni", "Tomatoes"));
        return defaultPizzas;
    }

    private Pizza loadDefaultPizza(String pizzaName) {
        List<String> ingredientNames = setupDefaultPizzas().get(pizzaName);

        PizzaBuilder builder = new ConcretePizzaBuilder(ingredients);
        PizzaDirector director = new PizzaDirector(builder);

        for (String name : ingredientNames) {
            if (ingredients.containsKey(name) && !ingredients.get(name).isRequired()) {
                builder.addIngredient(name, 1);
            }
        }

        return director.makePizza();
    }

    private Pizza createCustomPizza(Scanner scanner) {
        PizzaBuilder builder = new ConcretePizzaBuilder(ingredients);
        PizzaDirector director = new PizzaDirector(builder);

        while (true) {
            System.out.println("Enter the command: (1-add, 2-remove, 3-done)");
            int command = Integer.parseInt(scanner.nextLine().trim());

            if (command == 3) break;
            else if (command == 1) handleAddCommand(scanner, builder);
            else if (command == 2) handleRemoveCommand(scanner, builder);
            else System.out.println("Invalid command");
        }

        return director.makePizza();
    }

    private void handleAddCommand(Scanner scanner, PizzaBuilder builder) {
        System.out.println("Available ingredients to add:");
        ingredients.forEach((name, ingredient) -> {
            if (!ingredient.isRequired() && addedCounts.get(name) < 3) {
                System.out.printf("Ingredient: %s, price: $%.2f\n", name, ingredient.getPrice());
            }
        });

        System.out.print("Enter the ingredient: ");
        String input = scanner.nextLine().trim();
        if (!ingredients.containsKey(input) || ingredients.get(input).isRequired() || addedCounts.get(input) >= 3) {
            System.out.println("You can't add this ingredient");
            return;
        }

        System.out.print("Enter the count: ");
        int count = Integer.parseInt(scanner.nextLine().trim());
        if (count <= 0 || count > 3 - builder.getPizza().getIngredientCount(input)) {
            System.out.println("Invalid count");
            return;
        }

        builder.addIngredient(input, count);
        addedCounts.put(input, addedCounts.get(input) + count);
    }

    private void handleRemoveCommand(Scanner scanner, PizzaBuilder builder) {
        System.out.println("Available ingredients to remove:");
        ingredients.forEach((name, ingredient) -> {
            if (!ingredient.isRequired() && addedCounts.get(name) > 0) {
                System.out.printf("Ingredient: %s, count: %d\n", name, addedCounts.get(name));
            }
        });

        System.out.print("Enter the ingredient: ");
        String input = scanner.nextLine().trim();
        if (!ingredients.containsKey(input) || ingredients.get(input).isRequired() || addedCounts.get(input) <= 0) {
            System.out.println("You can't remove this ingredient");
            return;
        }

        System.out.print("Enter the count: ");
        int count = Integer.parseInt(scanner.nextLine().trim());
        if (count <= 0 || count > addedCounts.get(input)) {
            System.out.println("Invalid count");
            return;
        }

        builder.removeIngredient(input, count);
        addedCounts.put(input, addedCounts.get(input) - count);
    }
}
