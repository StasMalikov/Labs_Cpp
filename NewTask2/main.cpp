#include "services/IOService.h"

ProductList& initAssortment(ProductList& productList);
ShopList& initShopList(ShopList& shopList);

int main() {
    system("chcp 65001");

    ProductList productList;
    ShopList shopList;

    Supplier supplier(initAssortment(productList));
    initShopList(shopList);

    TradeOrganization tradeOrganization(supplier, shopList);

    IOService ioService(tradeOrganization);

    ioService.start();
    return 0;
}

ProductList& initAssortment(ProductList& productList) {
    productList.add(Product("Хлеб", 10, ProductType::bakery, 0.5));
    productList.add(Product("Мясо", 5, ProductType::meat, 1));
    productList.add(Product("Молоко", 15, ProductType::dairy, 0.9));
    return  productList;
}

ShopList& initShopList(ShopList& shopList) {
    shopList.add(Shop("Пятёрочка"));
    shopList.add(Shop("Вкусвилл"));
    shopList.add(Shop("Лента"));
    shopList.add(Shop("Магнит"));

    return shopList;
}

//Для каждой задачи необходимо реализовать объектную модель.
//В реализации задач должны присутствовать наследование, агрегация и др.взаимодействия классов.
//Общение с пользователем осуществляется через консоль путем вызова наиболее значимых методов классов,
//позволяющих увидеть основную функциональность задачи.Для моделирования  динамики процессов
//можно использовать повторяющиеся вызовы пользователем.

//10.	Торговая организация.
//Организации принадлежат склады с товарами и магазины.
//Существует два вида клиентов - оптовые и розничные,
// соответственно, оптовые приобретают товар на складе,
//розничные в магазине.Количество товара на складах и
// в магазинах ограничено, товары бывают различных типов,
//торговая организация получает товары от поставщика,
// партии товаров разной величины.
//Учесть распределение товаров по грузовикам для доставки клиентам магазинам.