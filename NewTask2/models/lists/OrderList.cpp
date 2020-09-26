//
// Created by stas_malikov on 31.08.2020.
//

#include "OrderList.h"

void OrderList::add(Order order) {
    orders[lastItemIndex] = order;
    if(lastItemIndex + 1 == count) {
        resize(count * resizeMultiplier);
    }
    lastItemIndex++;
}

//void OrderList::add(unsigned int orderId,
//        ProductList& productList,
//        unsigned int buyerId, unsigned int sellerId,){
//
//}

Order OrderList::getOrderById(unsigned int orderId) {
    for (unsigned int i = 0; i < lastItemIndex; ++i) {
        if(orders[i].getId() == orderId) {
            return orders[i];
        }
    }
    return Order();
}

Order OrderList::pop(int orderId) {
    Order order(getOrderById(orderId));
    remove(orderId);
    return order;
}

// 1 = found and deleted; 0 = not found
int OrderList::remove(unsigned int itemId) {
    for (unsigned int i = 0; i < lastItemIndex; ++i) {
        if(orders[i].getId() == itemId) {
            for (unsigned int j = i; j < lastItemIndex - 1; ++j) {
                orders[j] = orders[j + 1];
            }
            lastItemIndex--;
            return 1;
        }
    }
    return 0;
}

void OrderList::resize(int newSize) {
    Order *new_orders = new Order[newSize];
    for (unsigned int i = 0; i < count; ++i){
        new_orders[i] = orders[i];
    }
    delete [] orders;
    orders = new_orders;
}

Order &OrderList::operator[](unsigned int index) {
    return orders[index];
}