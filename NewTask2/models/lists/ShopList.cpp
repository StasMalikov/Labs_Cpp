//
// Created by stas_malikov on 13.09.2020.
//

#include "ShopList.h"


void ShopList::add(Shop shop) {
    shops[lastItemIndex] = shop;
    if(lastItemIndex + 1 == count) {
        resize(count * resizeMultiplier);
    }
    lastItemIndex++;
}

Shop* ShopList::getShopById(int shopId) {
    for (unsigned int i = 0; i < lastItemIndex; ++i) {
        if(shops[i].getId() == shopId) {
            return &shops[i];
        }
    }
    return nullptr;
}

//Shop ShopList::pop(int shopId) {
//    Shop shop(getShopById(shopId));
//    remove(shopId);
//    return shop;
//}

// 1 = found and deleted; 0 = not found
int ShopList::remove(unsigned int shopId) {
    for (int i = 0; i < lastItemIndex; ++i) {
        if(shops[i].getId() == shopId) {
            for (unsigned int j = i; j < lastItemIndex - 1; ++j) {
                shops[j] = shops[j + 1];
            }
            lastItemIndex--;
            return 1;
        }
    }
    return 0;
}

void ShopList::resize(int newSize) {
    Shop *new_shops = new Shop[newSize];
    for (unsigned int i = 0; i < count; ++i){
        new_shops[i] = shops[i];
    }
    delete [] shops;
    shops = new_shops;
}

Shop &ShopList::operator[](unsigned int index) {
    return shops[index];
}