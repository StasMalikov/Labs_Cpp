//
// Created by stas_malikov on 31.08.2020.
//

#ifndef NEWTASK2_ORDER_H
#define NEWTASK2_ORDER_H

#include "lists/ProductList.h"
#include "abstract/UniqueObj.h"

enum class OrderStatus {
    open,
    in_delivery,
    closed
};

class Order : public UniqueObj {

    ProductList productList;

    UniqueObj buyer;

    UniqueObj seller;

    OrderStatus orderStatus;

public:
    Order() : UniqueObj(0), buyer(0), seller(0) {}

    Order(UniqueObj _buyer, UniqueObj _seller) : UniqueObj(), buyer(_buyer.getId()),
        seller(_seller.getId()), productList(), orderStatus(OrderStatus::open) {}

    const Order& operator=(const Order& o){
        productList = o.productList;
        buyer = o.buyer;
        seller = o.seller;
        orderStatus = o.orderStatus;
        return *this;
    }

    void addProduct(Product product){
        productList.add(product);
    }

    Product cancelProduct(unsigned int productId) {
        return productList.pop(productId);
    }

    ProductList cancelOrder() {
        return productList;
    }

    OrderStatus getOrderStatus() const {
        return orderStatus;
    }
};


#endif //NEWTASK2_ORDER_H
