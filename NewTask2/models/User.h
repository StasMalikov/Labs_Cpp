#ifndef NEWTASK2_USER_H
#define NEWTASK2_USER_H

#include <string>
#include "abstract/UniqueObj.h"

using namespace std;

enum class UserType {
    wholesale,
    retail
};

class User : public UniqueObj {
    string name;
    UserType userType;

public:
    static string userTypeToStr(UserType _userType);
    string toString();
    User(): UniqueObj(0){}
    User(string _name, UserType _userType) : UniqueObj(), name(_name), userType(_userType) {}
};

#endif //NEWTASK2_USER_H
