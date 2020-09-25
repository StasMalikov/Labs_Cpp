//
// Created by stas_malikov on 03.09.2020.
//

#include "Shop.h"

string Shop::toString() {
    return to_string(id) + " " + name;
}

void Shop::addAssortment(ProductList &_productList) {
    for (unsigned int i = 0; i < _productList.getLastItemIndex(); ++i) {
        assortment.add(Product(_productList[i]));
    }
}

Product Shop::buy(Product product, unsigned int count) {
    if(assortment.getProductById(product.getId()).getQuantity() == count){
        return assortment.pop(product.getId());
    }

    if(assortment.getProductById(product.getId()).getQuantity() > count){
        for (unsigned int i = 0; i < assortment.getLastItemIndex(); ++i) {
            if(assortment[i].getId() == product.getId()){
                Product product1(assortment[i]);
                product1.setQuantity(count);
                assortment[i].setQuantity(assortment[i].getQuantity() - count);
                return product1;
            }
        }
    }

    return Product();
}
