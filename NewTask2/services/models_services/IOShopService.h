//
// Created by stasm on 23.09.2020.
//

#ifndef NEWTASK2_IOSHOPSERVICE_H
#define NEWTASK2_IOSHOPSERVICE_H

#include "../../models/lists/ShopList.h"
#include "../../models/lists/OrderList.h"

class IOShopService {
    UniqueObj& customer;

    ShopList& shopList;
    OrderList& orderList;

    Order order;
public:
    IOShopService(UniqueObj& _customer, ShopList& _shopList, OrderList& _orderList) :
        customer(_customer), shopList(_shopList), orderList(_orderList) {}

    void startShopOperations();
};

#endif //NEWTASK2_IOSHOPSERVICE_H
