//
// Created by stas_malikov on 04.08.2020.
//

#ifndef NEWTASK2_TRADEORGANIZATION_H
#define NEWTASK2_TRADEORGANIZATION_H

#include "lists/UserList.h"
#include "lists/ShopList.h"
#include "Supplier.h"

class TradeOrganization {
    UserList userList;
    User currentUser;
    Supplier& supplier;
    ShopList& shopList;


public:
    UserList &getUserList(){
        return userList;
    }

    User &getCurrentUser(){
        return currentUser;
    }

    Supplier &getSupplier() const {
        return supplier;
    }

    ShopList &getShopList() {
        return shopList;
    }

    TradeOrganization(Supplier& _supplier, ShopList& _shopList) :
        userList(), currentUser(), supplier(_supplier), shopList(_shopList) {}

};

#endif //NEWTASK2_TRADEORGANIZATION_H
