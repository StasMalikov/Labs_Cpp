//
// Created by stas_malikov on 11.08.2020.
//

#include "UserList.h"

void UserList::add(User user) {
    users[lastItemIndex] = user;
    if(lastItemIndex + 1 == count) {
        resize(count * resizeMultiplier);
    }
    lastItemIndex++;
}

User* UserList::getUserById(int userId) {
    for (int i = 0; i < lastItemIndex; ++i) {
        if(users[i].getId() == userId) {
            return &users[i];
        }
    }
    return nullptr;
}

// 1 = found and deleted; 0 = not found
int UserList::remove(unsigned int itemId) {
    for (int i = 0; i < lastItemIndex; ++i) {
        if(users[i].getId() == itemId) {
            for (int j = i; j < lastItemIndex - 1; ++j) {
                users[j] = users[j + 1];
            }
            lastItemIndex--;
            return 1;
        }
    }
    return 0;
}

void UserList::resize(int newSize) {
    User *new_users = new User[newSize];
    for (int i = 0; i < count; ++i){
        new_users[i] = users[i];
    }
    delete [] users;
    users = new_users;
}

User &UserList::operator[](unsigned int index) {
    return users[index];
}
