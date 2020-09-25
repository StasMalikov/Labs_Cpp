//
// Created by stas_malikov on 04.09.2020.
//

#include "IOSupplierService.h"

void IOSupplierService::startSupplierOperations() {
    int select = 1;
    while (select) {
        cout << "(Операции с поставками продуктов) Выберите действие:\n"
                "0 - вернуться в главное меню\n"
                "1 - посмотреть список магазинов и складов\n"
                "2 - выбрать клиента поставщика\n"
                "3 - посмотреть текущего клиента\n"
                "4 - посмотреть ассортимент поставщика\n"
                "5 - добавить товар в заказ\n"
                "6 - отменить товар в заказе\n"
                "7 - завершить оформление заказа\n"
                "8 - отмениить заказ\n"
                "9 - посмотреть заказ\n"
                ;

        select = Utils::getSelectIntCin(0 ,9);
        switch (select) {
            case 1:
                displayShopsAndStocks();
                break;

            case 2:
                selectCustomer();
                break;

            case 3:
                displayCurrentCustomer();
                break;

            case 4:
                displayAssortment();
                break;

            case 5:
                addProductToOrder();
                break;

            case 6:
                cancelProdInOrder();
                break;

            case 7:
                finishOrder();
                break;

            case 8:
                cancelOrder();
                break;

            case 9:
                showOrder();
                break;
        }
    }
}

void IOSupplierService::displayShopsAndStocks() {
    cout << "\n";

    cout << "Список магазинов:\n";
    for (unsigned int i = 0; i < shopList.getLastItemIndex(); ++i) {
        cout << shopList[i].toString() << "\n";
    }

    cout << "\n";
}

void IOSupplierService::displayCurrentCustomer() {
    cout << "\n";

    if(currentCustomer.getId() != 0) {
        Shop* shop = shopList.getShopById(currentCustomer.getId());
        cout << "Текущий клиент, магазин: " << shop->toString();
    } else {
        cout << "Текущий клиент не выбран";
    }

    cout << "\n";
}

void IOSupplierService::displayAssortment() {
    cout << "\nассортимент поставщика\n"
            "название_продукта тип_продукта вес_продукта(кг)\n";

    ProductList* productList = supplier.getAssortment();

    for (unsigned int i = 0; i < productList->getLastItemIndex(); ++i) {
        cout << (*productList)[i].smallToString() << "\n";
    }

    cout << "\n";
}

void IOSupplierService::selectCustomer() {
    cout << "\n";

    cout << "Чтобы выбрать клиента - введите его id\n";
    unsigned int id = Utils::getIdCin();

    Shop* shop = shopList.getShopById(id);

    if(shop != nullptr) {
        currentCustomer = UniqueObj(shop->getId());
        cout << "Клиент выбран\n";
    } else{
        cout << "Клиент с введённыи id не найден\n";
    }

    cout << "\n";
}

void IOSupplierService::addProductToOrder() {
    cout << "\n";
    if(order.getId() == 0) {
        order.generateId();
    }

    cout << "Для добавления товара в заказ введите параметры товара\n";
    cout << "Введите название товара\n";

    string productTitle;
    productTitle = Utils::getSelectStringCin();

    Product product =  supplier.getAssortment()->getProductByTitle(productTitle);
    if(product.getId() == 0){
        cout << "Товар с указанным названием не найден\n";
    } else {
        cout << "Введите количество товара\n";
        unsigned int productCount = Utils::getSelectIntCin(1, 999999);
        order.addProduct(Product(product.getTitle(), productCount,
                product.getProductType(), product.getWeight()));

        cout << "Продукт успешно добавлен в заказ\n";
    }

    cout << "\n";

}

void IOSupplierService::cancelProdInOrder() {
    cout << "\n";

    if(order.getId() == 0) {
        cout << "Заказ пока не создан\n";
    } else {
        cout << "Введите id товара, который нужно удалить из заказа";

        unsigned int prodId = Utils::getIdCin();
        Product product =  order.getProductList()->getProductById(prodId);
        if(product.getId() == 0){
            cout << "Товара с указанным id нет в заказе\n";
        } else {
            order.cancelProduct(prodId);
            cout << "Товар с id = " << prodId << " был удалён из заказа\n";
        }
    }
}

void IOSupplierService::finishOrder() {
    order.setBuyer(UniqueObj(currentCustomer.getId()));
    order.setSeller(supplier.getId());
    order.setOrderStatus(OrderStatus::open);
    orderList.add(Order(order));

    int ooo = 0;
    Order emptyOrder;
    order = emptyOrder;

    cout << "Заказ успешно оформлен\n\n";
}

void IOSupplierService::cancelOrder() {
    if(order.getId() == 0) {
        cout << "Заказ пока не создан\n\n";
    } else {
        Order emptyOrder;
        order = emptyOrder;

        cout << "Заказ отменён\n\n";
    }
}

void IOSupplierService::showOrder() {
    if(order.getId() == 0) {
        cout << "Заказ пока не создан\n\n";
    } else{
        ProductList& list = order.getProductListRef();
        if(list.getLastItemIndex() > 0){
            cout << "Список товаров в заказе\n"
                << "1)id 2)title 3)quantity 4)productType 5)weight\n\n";

            for (unsigned int i = 0; i < list.getLastItemIndex(); ++i) {
                cout << list[i].toString() << "\n";
            }

            cout << "\n";
        } else {
            cout << "Пока в заказе нет товаров\n\n";
        }
    }
}
