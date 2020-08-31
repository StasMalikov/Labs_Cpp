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
    double weight;
public:
    Product(): UniqueObj(0){}

    Product(string _title, unsigned int _quantity, ProductType _productType, double _weight):
        UniqueObj(), title(_title), quantity(_quantity),
        productType(_productType), weight(_weight){}


    Product(Product& p) : UniqueObj(p.getId()), title(p.getTitle()),
        quantity(p.getQuantity()), productType(p.getProductType()), weight(p.getWeight()) {}

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

    double getWeight() const {
        return weight;
    }
};


#endif //NEWTASK2_PRODUCT_H
