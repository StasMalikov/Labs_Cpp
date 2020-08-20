#include "User.h"

string User::toString() {
    return to_string(id) + " " + name + " " +
        userTypeToStr(userType);
}

string User::userTypeToStr(UserType _userType) {
    switch (_userType) {
        case UserType::retail: {
            return "retail";
        }

        case UserType::wholesale: {
            return "wholesale";
        }
    }

    return string();
}
