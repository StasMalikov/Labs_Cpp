//
// Created by stas_malikov on 31.08.2020.
//

#ifndef NEWTASK2_ORDERLIST_H
#define NEWTASK2_ORDERLIST_H

#include "../Order.h"

class OrderList {
    const double resizeMultiplier = 1.5;
    Order *orders;
    unsigned int lastItemIndex;
    unsigned int count;

    void resize(int newSize);

public:
    unsigned int getCount(){return count;}

    unsigned int getLastItemIndex(){return lastItemIndex;}

    int remove(unsigned int orderId);

    Order pop(int orderId);

    void add(Order order);

    Order getOrderById(int orderId);

    //iterator
    Order& operator[](unsigned int index);

    //copy constructor
    OrderList(const OrderList& a) {
        orders = new Order[count];
        for (int i = 0; i < count; ++i) {
            orders[i] = a.orders[i];
        }
    }

    OrderList(){
        count = 5;
        lastItemIndex = 0;
        orders = new Order[count];
    }

    ~OrderList(){
        delete [] orders;
    }
};


#endif //NEWTASK2_ORDERLIST_H
