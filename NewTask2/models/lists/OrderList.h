//
// Created by stas_malikov on 31.08.2020.
//

#ifndef NEWTASK2_ORDERLIST_H
#define NEWTASK2_ORDERLIST_H

#include "../Order.h"
#include "../abstract/List.h"

class OrderList : public List {
    Order *orders;

    void resize(int newSize);
public:
    int remove(unsigned int itemId);

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

    virtual ~OrderList(){
        delete [] orders;
    }
};


#endif //NEWTASK2_ORDERLIST_H
