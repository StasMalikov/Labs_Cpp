//
// Created by stasm on 23.09.2020.
//

#include "DeliveryOrganization.h"

void DeliveryOrganization::startDelivery(OrderList &orderList) {
    for (int i = 0; i < orderList.getLastItemIndex(); ++i) {
        ProductList &productList = orderList[i].getProductListRef();
        double sumVolumeOfProducts = 0;

        for (int j = 0; j < productList.getLastItemIndex(); ++j) {
            sumVolumeOfProducts += productList[i].getWeight()*productList[i].getQuantity();
        }
        int trucksToOrder = calculateTrucks(sumVolumeOfProducts);
        finishDelivery(orderList[i], trucksToOrder);
    }
}

int DeliveryOrganization::calculateTrucks(double value) {
    int trucksCount = 0;
    trucksCount += value/volumeInOneTruck;
    if(value - trucksCount*volumeInOneTruck > 0)
        trucksCount++;

    return trucksCount;
}

void DeliveryOrganization::finishDelivery(Order &order, int trucksCount) {
    Shop& shop = shopList.getShopByIdRef(order.getId());
    if(shop.getId() != 0){
        shop.addAssortment(order.getProductListRef());
    }

    order.setOrderStatus(OrderStatus::closed);
}
