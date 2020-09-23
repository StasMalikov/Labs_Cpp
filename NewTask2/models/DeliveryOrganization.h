//
// Created by stasm on 23.09.2020.
//

#ifndef NEWTASK2_DELIVERYORGANIZATION_H
#define NEWTASK2_DELIVERYORGANIZATION_H

#include "lists/OrderList.h"
#include "lists/ShopList.h"

class DeliveryOrganization {
    ShopList& shopList;
    const int volumeInOneTruck = 10;

    int calculateTrucks(double value);
public:
    DeliveryOrganization(ShopList& _shopList): shopList(_shopList) {}

    void startDelivery(OrderList& orderList);

    void finishDelivery(Order& order, int trucksCount);
};


#endif //NEWTASK2_DELIVERYORGANIZATION_H
