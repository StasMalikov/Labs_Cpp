//
// Created by stas_malikov on 19.08.2020.
//

#ifndef NEWTASK2_SELLER_H
#define NEWTASK2_SELLER_H

#include "../Order.h"
#include <string>

class Seller {
protected:
    //ProductList assortment;
    string name;

    void setName(const string &name) {
        Seller::name = name;
    }

public:
    Seller(){}
    //Seller(ProductList _assortment) : assortment(_assortment){}

    virtual ~Seller(){}

    virtual Order buy(Order order) = 0;

//    const ProductList &getAssortment() const {
//        return assortment;
//    }

    const string &getName() const {
        return name;
    }
};


#endif //NEWTASK2_SELLER_H
