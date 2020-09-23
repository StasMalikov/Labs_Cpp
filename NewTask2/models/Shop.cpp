//
// Created by stas_malikov on 03.09.2020.
//

#include "Shop.h"

string Shop::toString() {
    return to_string(id) + " " + name;
}

void Shop::addAssortment(ProductList &_productList) {
    for (int i = 0; i < _productList.getLastItemIndex(); ++i) {
        assortment.add(_productList[i]);
    }
}
