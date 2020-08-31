//
// Created by stas_malikov on 31.08.2020.
//

#ifndef NEWTASK2_ORDER_H
#define NEWTASK2_ORDER_H

#include "lists/ProductList.h"
#include "abstract/Buyer.h"
#include "abstract/Seller.h"

enum class OrderStatus {
    open,
    in_delivery,
    closed
};

class Order {

    ProductList productList;

    Buyer &buyer;

    Seller &seller;

    OrderStatus orderStatus;

public:
    Order(Buyer &_buyer, Seller &_seller) : buyer(_buyer),
        seller(_seller), productList(), orderStatus(OrderStatus::open) {}

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
