//
// Created by stas_malikov on 11.08.2020.
//

#ifndef NEWTASK2_USERLIST_H
#define NEWTASK2_USERLIST_H

#include "../User.h"

class UserList {
    const double resizeMultiplier = 1.5;
    User *users;
    unsigned int lastItemIndex;
    unsigned int count;

    void resize(int newSize);

public:
    unsigned int getCount(){return count;}

    unsigned int getLastItemIndex(){return lastItemIndex;}

    int remove(unsigned int userId);

    void add(User user);

    User* getUserById(int userId);

    //iterator
    User& operator[](unsigned int index);

    //copy constructor
    UserList(const UserList& a) {
        users = new User[count];
        for (int i = 0; i < count; ++i) {
            users[i] = a.users[i];
        }
    }

    UserList(){
        count = 5;
        lastItemIndex = 0;
        users = new User[count];
    }

    ~UserList(){
        delete [] users;
    }
};


#endif //NEWTASK2_USERLIST_H
