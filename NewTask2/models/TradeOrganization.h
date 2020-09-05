//
// Created by stas_malikov on 04.08.2020.
//

#ifndef NEWTASK2_TRADEORGANIZATION_H
#define NEWTASK2_TRADEORGANIZATION_H

#include "lists/UserList.h"
#include "Supplier.h"

class TradeOrganization {
    UserList userList;
    User currentUser;
    Supplier& supplier;

public:
    UserList &getUserList(){
        return userList;
    }

    User &getCurrentUser(){
        return currentUser;
    }

    TradeOrganization(Supplier& _supplier) : userList(), currentUser(), supplier(_supplier) {}
};

#endif //NEWTASK2_TRADEORGANIZATION_H
