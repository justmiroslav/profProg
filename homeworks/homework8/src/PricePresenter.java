public class PricePresenter<PRIORITY extends Number> {
    private final PRIORITY priority;

    public PricePresenter(PRIORITY priority) {
        this.priority = priority;
    }

    public <T1 extends Priceable, T2 extends Priceable> void printTotalPrice(T1 obj1, T2 obj2) {
        double totalPrice = priority.doubleValue() * obj1.coefficient() * obj1.basePrice() + obj2.coefficient() * obj2.basePrice();
        System.out.printf("Total price: %.2f%n", totalPrice);
    }
}
