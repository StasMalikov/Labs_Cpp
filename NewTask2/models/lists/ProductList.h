//
// Created by stas_malikov on 20.08.2020.
//

#ifndef NEWTASK2_PRODUCTLIST_H
#define NEWTASK2_PRODUCTLIST_H

#include "../Product.h"
#include "../abstract/List.h"

class ProductList : public List {
    Product *products;

    void resize(int newSize);

public:
    int remove(unsigned int itemId);

    Product pop(int productId);

    void add(Product product);

    Product getProductById(unsigned int productId);

    Product getProductByTitle(string title);

    //iterator
    Product& operator[](unsigned int index);

    //copy constructor
    ProductList(const ProductList& a) {
        products = new Product[count];
        for (unsigned int i = 0; i < count; ++i) {
            products[i] = a.products[i];
        }
    }

    const ProductList& operator=(const ProductList& o){
        products = o.products;
        lastItemIndex = o.lastItemIndex;
        count = o.count;
        return *this;
    }

    ProductList(){
        count = 5;
        lastItemIndex = 0;
        products = new Product[count];
    }

    virtual ~ProductList(){
        delete [] products;
    }
};


#endif //NEWTASK2_PRODUCTLIST_H
