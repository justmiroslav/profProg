import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a list of words separated by spaces:");
        String input = scanner.nextLine();
        scanner.close();

        String[] numbersStr = input.split(" ");

        List<Integer> nums = new ArrayList<>();
        for (String number : numbersStr) {
            try {
                int num = Integer.parseInt(number);
                nums.add(num);
            } catch (NumberFormatException e) {
                System.out.println("Invalid input. Please enter a list of numbers separated by spaces.");
                return;
            }
        }

        Integer maxNegative = null;

        for (int number : nums) {
            if (number < 0 && (maxNegative == null || number > maxNegative)) {
                maxNegative = number;
            }
        }

        if (maxNegative != null) {
            System.out.println("Biggest negative number: " + maxNegative);
        } else {
            System.out.println("No negative numbers found.");
        }
    }
}