//
// Created by stas_malikov on 31.08.2020.
//

#ifndef NEWTASK2_SUPPLIER_H
#define NEWTASK2_SUPPLIER_H

#include "abstract/Seller.h"
#include "abstract/UniqueObj.h"
#include "Order.h"


class Supplier : public Seller, public UniqueObj {
public:
    Supplier() : Seller(), UniqueObj() {};
    //Supplier(ProductList _assortment) : Seller(_assortment), UniqueObj() {};
    virtual Order buy(Order order){return Order();}
    virtual ~Supplier(){}
};


#endif //NEWTASK2_SUPPLIER_H
