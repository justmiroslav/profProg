public class Products {
    public record Milk(double coefficient, double basePrice) implements Priceable { }
    public record Cookies(double coefficient, double basePrice) implements Priceable { }
    public record Pineapple(double coefficient, double basePrice) implements Priceable { }
}
