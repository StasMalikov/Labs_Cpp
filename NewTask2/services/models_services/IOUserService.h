#ifndef NEWTASK2_IOUSERSERVICE_H
#define NEWTASK2_IOUSERSERVICE_H


#include "../../models/lists/UserList.h"


class IOUserService {
    UserList &userList;
    User &currentUser;
public:
    IOUserService(UserList &_userList, User &_currentUser) :
            userList(_userList), currentUser(_currentUser) {}

    void displayUsers();
    void deleteUser();
    void addUser();
    void displayCurrentUser();
    void selectUser();
    void startUserOperations();
};

#endif //NEWTASK2_IOUSERSERVICE_H
