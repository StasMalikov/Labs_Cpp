//
// Created by stas_malikov on 11.08.2020.
//

#ifndef NEWTASK2_USERLIST_H
#define NEWTASK2_USERLIST_H

#include "../User.h"

// добавить конструктор копирования

class UserList {
    const double resizeMultiplier = 1.5;
    User *users;
    unsigned int lastUsersIndex;
    void resizeUsers(int newSize);
    unsigned int usersSize;
public:
    unsigned int userSize(){return usersSize;}
    unsigned int getLastUsersIndex(){return lastUsersIndex;}

    int deleteUser(unsigned int userId);
    void addUser(User user);
    User* getUserById(int userId);
    User& operator[](unsigned int index);

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
