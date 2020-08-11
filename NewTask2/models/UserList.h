//
// Created by stas_malikov on 11.08.2020.
//

#ifndef NEWTASK2_USERLIST_H
#define NEWTASK2_USERLIST_H

#include "User.h"

class UserList {
    const double resizeMultiplier = 1.5;
    User *users;
    unsigned int usersSize;
    unsigned int lastUsersIndex;
    void resizeUsers(int newSize);
public:
    int deleteUser(int userId);
    void addUser(User user);
    User getUserById(int userId);
    User *getUsers() {return users;}

    UserList(){
        usersSize = 5;
        lastUsersIndex = 0;
        users = new User[usersSize];
    }

    ~UserList(){
        delete [] users;
    }
};


#endif //NEWTASK2_USERLIST_H
