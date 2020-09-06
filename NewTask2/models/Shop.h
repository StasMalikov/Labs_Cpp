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
        Shop(string shopName) : Seller(), UniqueObj() {
        setName(shopName);
    };

//    Shop(ProductList _assortment, string shopName) : Seller(_assortment), UniqueObj() {
//        setName(shopName);
//    };

    string toString();
};


#endif //NEWTASK2_SHOP_H
