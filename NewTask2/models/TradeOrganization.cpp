//
// Created by stas_malikov on 04.08.2020.
//

#include "TradeOrganization.h"

void TradeOrganization::startDeliveringProducts() {
    OrderList ordersToDeliver;
    for (int i = 0; i < orderList.getLastItemIndex(); ++i) {
        if(orderList[i].getOrderStatus() == OrderStatus::open){
            orderList[i].setOrderStatus(OrderStatus::in_delivery);
            ordersToDeliver.add(orderList.pop(orderList[i].getId()));
        }
    }

    deliveryOrganization.startDelivery(ordersToDeliver);
}

OrderList &TradeOrganization::getOrderList() {
    return orderList;
}
