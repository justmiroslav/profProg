public class Main {
    public static void main(String[] args) {
        Products.Milk milk = new Products.Milk(2.28, 7.77);
        Products.Cookies cookies = new Products.Cookies(3.14, 13.37);
        Products.Pineapple pineapple = new Products.Pineapple(4.20, 14.88);

        new PricePresenter<>(3).printTotalPrice(milk, cookies);
        new PricePresenter<>(2).printTotalPrice(cookies, pineapple);
        new PricePresenter<>(1).printTotalPrice(milk, pineapple);
    }
}
