//
// Created by stas_malikov on 19.08.2020.
//

#ifndef NEWTASK2_SELLER_H
#define NEWTASK2_SELLER_H

#include "../Order.h"
#include <string>

class Seller {
protected:
    ProductList assortment;
    string name;

    void setName(const string &name) {
        Seller::name = name;
    }

public:
    Seller(ProductList& _assortment) : assortment() {
        for (unsigned int i = 0; i < _assortment.getLastItemIndex(); ++i) {
            assortment.add(_assortment[i]);
        }
    }

    Seller() : assortment() {}

    Seller(string _name) : assortment(), name(_name) {}

    virtual ~Seller(){}

    virtual Product buy(Product product, unsigned int count) = 0;

    ProductList *getAssortment() {
        return &assortment;
    }

    const string &getName() const {
        return name;
    }
};


#endif //NEWTASK2_SELLER_H
