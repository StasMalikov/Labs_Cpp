//
// Created by stas_malikov on 13.09.2020.
//

#ifndef NEWTASK2_SHOPLIST_H
#define NEWTASK2_SHOPLIST_H

#include "../Shop.h"
#include "../abstract/List.h"

class ShopList : public List {
    Shop *shops;

    void resize(int newSize);

public:
    int remove(unsigned int shopId);

    //Shop pop(int shopId);

    void add(Shop shop);

    Shop* getShopById(unsigned int shopId);

    Shop& getShopByIdRef(unsigned int shopId);

    //iterator
    Shop& operator[](unsigned int index);

    //copy constructor
    ShopList(const ShopList& a) {
        shops = new Shop[count];
        for (unsigned int i = 0; i < count; ++i) {
            shops[i] = a.shops[i];
        }
    }

    const ShopList& operator=(const ShopList& o){
        shops = o.shops;
        lastItemIndex = o.lastItemIndex;
        count = o.count;
        return *this;
    }

    ShopList(){
        count = 5;
        lastItemIndex = 0;
        shops = new Shop[count];
    }

    virtual ~ShopList(){
        delete [] shops;
    }
};


#endif //NEWTASK2_SHOPLIST_H
