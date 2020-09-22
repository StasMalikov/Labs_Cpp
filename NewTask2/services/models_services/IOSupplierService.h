//
// Created by stas_malikov on 04.09.2020.
//

#ifndef NEWTASK2_IOSUPPLIERSERVICE_H
#define NEWTASK2_IOSUPPLIERSERVICE_H

#include "../../models/Supplier.h"
#include "../../models/lists/ShopList.h"
#include "../../models/lists/OrderList.h"
#include <iostream>

using namespace std;

class IOSupplierService {
    Supplier& supplier;
    ShopList& shopList;
    UniqueObj currentCustomer;
    OrderList& orderList;

    Order order;

public:
    IOSupplierService(Supplier& _supplier, ShopList& _shopList, OrderList& _orderList) : supplier(_supplier),
        shopList(_shopList), currentCustomer(0), orderList(_orderList), order() {}

    void startSupplierOperations();

    void selectCustomer();

    void displayShopsAndStocks();

    void displayCurrentCustomer();

    void displayAssortment();

    void addProductToOrder();

    void cancelProdInOrder();

    void finishOrder();

    void cancelOrder();
};


#endif //NEWTASK2_IOSUPPLIERSERVICE_H
