//
// Created by stas_malikov on 11.08.2020.
//

#ifndef NEWTASK2_USERLIST_H
#define NEWTASK2_USERLIST_H

#include "../User.h"
#include "../abstract/List.h"

class UserList : public List {
    User *users;

    void resize(int newSize);

public:
    int remove(unsigned int itemId);

    void add(User user);

    User* getUserById(int userId);

    //iterator
    User& operator[](unsigned int index);

    //copy constructor
    UserList(const UserList& a) {
        users = new User[count];
        for (unsigned int i = 0; i < count; ++i) {
            users[i] = a.users[i];
        }
    }

    UserList(){
        count = 5;
        lastItemIndex = 0;
        users = new User[count];
    }

    virtual ~UserList(){
        delete [] users;
    }
};


#endif //NEWTASK2_USERLIST_H
