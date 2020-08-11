#ifndef NEWTASK2_USER_H
#define NEWTASK2_USER_H

#include <string>
#include <utility>
#include "../services/Utils.h"
using namespace std;

enum class UserType {
    wholesale,
    retail
};

class User {
    unsigned int id;
    string name;
    UserType userType;

public:
    unsigned int getId() {return id;}
    static string userTypeToStr(UserType _userType);
    string toString();
    User(){}
    User(string _name, UserType _userType) : id(Utils::generateId()), name(std::move(_name)), userType(_userType) {}
    ~User(){}
};

#endif //NEWTASK2_USER_H
