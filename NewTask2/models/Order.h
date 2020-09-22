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

    void setProductList();

public:
    Order() : UniqueObj(0), productList(), buyer(0), seller(0) {}

    Order(UniqueObj _buyer, UniqueObj _seller) : UniqueObj(), productList(), buyer(_buyer.getId()),
        seller(_seller.getId()), orderStatus(OrderStatus::open) {}

    Order(const Order& o) : UniqueObj(0), productList(), buyer(0), seller(0){
        id = o.id;
        productList = o.productList;
        buyer = o.buyer;
        seller = o.seller;
        orderStatus = o.orderStatus;
    }

    const Order& operator=(const Order& o){
        id = o.id;
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

    void setBuyer(const UniqueObj &buyer) {
        Order::buyer = buyer;
    }

    void setSeller(const UniqueObj &seller) {
        Order::seller = seller;
    }

    void setOrderStatus(OrderStatus orderStatus) {
        Order::orderStatus = orderStatus;
    }

    void setOrderId(unsigned  int newId){
        id = newId;
    }

    void generateId(){
        id = Utils::generateId();
    }

    ProductList *getProductList() {
        return &productList;
    }

    ProductList &getProductListRef() {
        return productList;
    }

    const UniqueObj &getBuyer() const {
        return buyer;
    }

    const UniqueObj &getSeller() const {
        return seller;
    }

};


#endif //NEWTASK2_ORDER_H
