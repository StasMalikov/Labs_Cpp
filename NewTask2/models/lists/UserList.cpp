//
// Created by stas_malikov on 11.08.2020.
//

#include "UserList.h"

void UserList::addUser(User user) {
    users[lastUsersIndex] = user;
    if(lastUsersIndex + 1 == usersSize) {
        resizeUsers(usersSize*resizeMultiplier);
    }
    lastUsersIndex++;
}

User* UserList::getUserById(int userId) {
    for (int i = 0; i < lastUsersIndex; ++i) {
        if(users[i].getId() == userId) {
            return &users[i];
        }
    }
    return nullptr;
}

// 1 = found and deleted; 0 = not found
int UserList::deleteUser(unsigned int userId) {
    for (int i = 0; i < lastUsersIndex; ++i) {
        if(users[i].getId() == userId) {
            for (int j = i; j < lastUsersIndex - 1; ++j) {
                users[j] = users[j + 1];
            }
            lastUsersIndex--;
            return 1;
        }
    }
    return 0;
}

void UserList::resizeUsers(int newSize) {
    User *new_users = new User[newSize];
    for (int i = 0; i < usersSize; ++i){
        new_users[i] = users[i];
    }
    delete [] users;
    users = new_users;
}

User &UserList::operator[](unsigned int index) {
    return users[index];
}
