//
// Created by stas_malikov on 04.09.2020.
//

#ifndef NEWTASK2_IOSUPPLIERSERVICE_H
#define NEWTASK2_IOSUPPLIERSERVICE_H

#include "../../models/Supplier.h"
#include "../../models/lists/ShopList.h"
#include <iostream>

using namespace std;

class IOSupplierService {
    Supplier& supplier;
    ShopList& shopList;
    UniqueObj currentCustomer;

public:
    IOSupplierService(Supplier& _supplier, ShopList& _shopList) : supplier(_supplier),
        shopList(_shopList), currentCustomer(0) {}

    void startSupplierOperations();

    void selectCustomer();

    void displayShopsAndStocks();

    void displayCurrentCustomer();

    void displayAssortment();
};


#endif //NEWTASK2_IOSUPPLIERSERVICE_H
