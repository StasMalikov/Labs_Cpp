//
// Created by stas_malikov on 20.08.2020.
//

#include "ProductList.h"

void ProductList::add(Product product) {
    products[lastItemIndex] = product;
    if(lastItemIndex + 1 == count) {
        resize(count * resizeMultiplier);
    }
    lastItemIndex++;
}

Product* ProductList::getProductById(int productId) {
    for (int i = 0; i < lastItemIndex; ++i) {
        if(products[i].getId() == productId) {
            return &products[i];
        }
    }
    return nullptr;
}

// 1 = found and deleted; 0 = not found
int ProductList::remove(unsigned int productId) {
    for (int i = 0; i < lastItemIndex; ++i) {
        if(products[i].getId() == productId) {
            for (int j = i; j < lastItemIndex - 1; ++j) {
                products[j] = products[j + 1];
            }
            lastItemIndex--;
            return 1;
        }
    }
    return 0;
}

void ProductList::resize(int newSize) {
    Product *new_products = new Product[newSize];
    for (int i = 0; i < count; ++i){
        new_products[i] = products[i];
    }
    delete [] products;
    products = new_products;
}

Product &ProductList::operator[](unsigned int index) {
    return products[index];
}