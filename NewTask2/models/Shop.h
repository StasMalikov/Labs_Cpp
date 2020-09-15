//
// Created by stas_malikov on 03.09.2020.
//

#ifndef NEWTASK2_SHOP_H
#define NEWTASK2_SHOP_H

#include "abstract/Seller.h"
#include "abstract/UniqueObj.h"
#include <string>

using namespace std;

class Shop : public Seller, public UniqueObj {

public:
    Shop() : Seller(), UniqueObj() {}

    Shop(ProductList& _assortment, string shopName) : Seller(_assortment), UniqueObj() {
        setName(shopName);
    };

    Shop(string shopName) : Seller(shopName), UniqueObj() {};

    Shop(unsigned int _id) : Seller(), UniqueObj(_id) {};

    string toString();

    virtual Order buy(Order order) {}

    const Shop& operator=(const Shop& o){
        assortment = o.assortment;
        name = o.name;
        return *this;
    }
};


#endif //NEWTASK2_SHOP_H
