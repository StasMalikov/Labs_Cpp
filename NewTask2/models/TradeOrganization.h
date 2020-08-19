//
// Created by stas_malikov on 04.08.2020.
//

#ifndef NEWTASK2_TRADEORGANIZATION_H
#define NEWTASK2_TRADEORGANIZATION_H

#include "lists/UserList.h"

class TradeOrganization {
    UserList userList;
    User currentUser;
public:
    UserList &getUserList(){
        return userList;
    }

    User &getCurrentUser(){
        return currentUser;
    }

    TradeOrganization() : userList(), currentUser() {}
    ~TradeOrganization(){}
};

#endif //NEWTASK2_TRADEORGANIZATION_H
