import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void printResults(BaseMegaCalculator calculator) {
        System.out.println("Current price: " + calculator.getPrice());
        System.out.println("Current minimal value: " + calculator.getMinimalValue());
        System.out.println("Current report: " + calculator.getReport());
    }

    public static void main(String[] args) {
        List<BaseMegaCalculator> calculators = new ArrayList<>();

        calculators.add(new MyCoolCalculator(6.0, 12.1, 3.2));
        calculators.add(new ConstantCalculator());
        calculators.add(new MegaAdapter(new LegacyCalculator(1.34, 5.4)));

        for (BaseMegaCalculator calculator : calculators) {
            printResults(calculator);
        }
    }
}
