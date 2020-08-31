//
// Created by stas_malikov on 20.08.2020.
//

#ifndef NEWTASK2_PRODUCTLIST_H
#define NEWTASK2_PRODUCTLIST_H

#include "../Product.h"

class ProductList {
    const double resizeMultiplier = 1.5;
    Product *products;
    unsigned int lastItemIndex;
    unsigned int count;

    void resize(int newSize);

public:
    unsigned int getCount(){return count;}

    unsigned int getLastItemIndex(){return lastItemIndex;}

    int remove(unsigned int productId);

    Product pop(int productId);

    void add(Product product);

    Product getProductById(int productId);

    //iterator
    Product& operator[](unsigned int index);

    //copy constructor
    ProductList(const ProductList& a) {
        products = new Product[count];
        for (int i = 0; i < count; ++i) {
            products[i] = a.products[i];
        }
    }

    ProductList(){
        count = 5;
        lastItemIndex = 0;
        products = new Product[count];
    }

    ~ProductList(){
        delete [] products;
    }
};


#endif //NEWTASK2_PRODUCTLIST_H
