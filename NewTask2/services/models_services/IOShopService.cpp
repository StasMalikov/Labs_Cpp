//
// Created by stasm on 23.09.2020.
//

#include "IOShopService.h"

void IOShopService::startShopOperations() {
    int select = 1;
    while (select) {
        cout << "(Операции с розничной торговлей) Выберите действие:\n"
                "0 - вернуться в главное меню\n"
                "1 - посмотреть список магазинов\n"
                "2 - выбрать магазин\n"
                "3 - посмотреть ассортимент магазина\n"
                "4 - добавить товар в заказ\n"
                "5 - завершить покупку\n"
                ;

        select = Utils::getSelectIntCin(0 ,5);
        switch (select) {
            case 1:
                displayShops();
                break;

            case 2:
                selectShop();
                break;

            case 3:
                showAssortment();
                break;

            case 4:
                addProduct();
                break;

            case 5:
                confirmOrder();
                break;
        }
    }
}

void IOShopService::displayShops() {
    cout << "\n";

    cout << "Список магазинов:\n";
    for (unsigned int i = 0; i < shopList.getLastItemIndex(); ++i) {
        cout << shopList[i].toString() << "\n";
    }

    cout << "\n";
}

void IOShopService::selectShop() {
    cout << "\n";

    cout << "Чтобы выбрать магазин - введите его id\n";
    unsigned int id = Utils::getIdCin();

    Shop* shop = shopList.getShopById(id);

    if(shop != nullptr) {
        currentShop = UniqueObj(shop->getId());
        cout << "магазин выбран\n";
    } else{
        cout << "магазин с введённыи id не найден\n";
    }

    cout << "\n";
}

void IOShopService::addProduct() {
    cout << "\n";
    if(order.getId() == 0) {
        order.generateId();
    }

    cout << "Для добавления товара в заказ введите параметры товара\n";
    cout << "Введите название товара\n";

    string productTitle;
    productTitle = Utils::getSelectStringCin();

    Product product =  shopList.getShopById(currentShop.getId())->getAssortment()->getProductByTitle(productTitle);
    if(product.getId() == 0){
        cout << "Товар с указанным названием не найден\n";
    } else {
        cout << "Введите количество товара\n";
        unsigned int productCount = Utils::getSelectIntCin(1, product.getQuantity());

        order.addProduct(shopList.getShopById(currentShop.getId())->buy(product,productCount));

        cout << "Продукт успешно добавлен в заказ\n";
    }

    cout << "\n";
}

void IOShopService::confirmOrder() {
    order.setBuyer(UniqueObj(customer.getId()));
    order.setSeller(currentShop);

    orderList.add(order);

    Order emptyOrder;
    order = emptyOrder;

    cout << "Заказ успешно оформлен\n\n";
}

void IOShopService::showAssortment() {
    Shop* shop = shopList.getShopById(currentShop.getId());
    if(shop != nullptr){
        ProductList& assortment = shop->getAssortmentRef();
        cout << "Ассортимент магазина " << shop->getName() << "\n\n";

        if(assortment.getLastItemIndex() == 0){
            cout << "Ассортимент магазина пуст\n";
        } else {
            for (unsigned int i = 0; i < assortment.getLastItemIndex(); ++i) {
                cout << assortment[i].toString() << "\n";
            }
        }
    } else {
        cout << "магазин не выбран\n";
    }

}