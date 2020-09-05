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

//            case 2:
//
//                break;

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

    cout << shop.toString() << "\n";
}

void IOSupplierService::displayCurrentCustomer() {
    cout << "\n";

    if(currentCustomer.getId() == shop.getId()){
        cout << "Текущий покупатель, магазин: " << shop.toString();
    } else {
        cout << "Текущий покупатель не выбран";
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
