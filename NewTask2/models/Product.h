//
// Created by stas_malikov on 20.08.2020.
//

#ifndef NEWTASK2_PRODUCT_H
#define NEWTASK2_PRODUCT_H

#include "abstract/UniqueObj.h"
#include <string>

using namespace std;

enum class ProductType {
    meat,
    dairy,
    bakery
};

class Product : public UniqueObj {
    string title;
    unsigned int quantity;
    ProductType productType;
public:
    Product(): UniqueObj(0){}

    Product(string _title, unsigned int _quantity, ProductType _productType):
        UniqueObj(), title(_title),quantity(_quantity),
        productType(_productType){}

    string toString();

    static string productTypeToStr(ProductType _productType);

    string getTitle() const {
        return title;
    }

    unsigned int getQuantity() const {
        return quantity;
    }

    ProductType getProductType() const {
        return productType;
    }
};


#endif //NEWTASK2_PRODUCT_H
