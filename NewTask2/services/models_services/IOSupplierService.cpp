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
                "6 - отмениить товар в заказе\n"
                "7 - завершить оформление заказа\n"
                "8 - отмениить заказ\n"
                ;

        select = Utils::getSelectIntCin(0 ,7);
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

//            case 5:
//
//                break;
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
    cout << "ассортимент поставщика\n"
            "название_продукта тип_продукта вес_продукта\n";

    ProductList productList = supplier.getAssortment();

    for (int i = 0; i < productList.getLastItemIndex(); ++i) {
        cout << productList[i].smallToString() << "\n";
    }
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
