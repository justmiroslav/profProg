#include "Products.hpp"
#include "PricePresenter.hpp"

int main() {
    Milk milk(2.28, 7.77);
    Cookies cookies(3.14, 13.37);
    Pineapple pineapple(4.20, 14.88);

    PricePresenter<3>::printTotalPrice(milk, cookies);
    PricePresenter<2>::printTotalPrice(cookies, pineapple);
    PricePresenter<1>::printTotalPrice(milk, pineapple);
    return 0;
}
