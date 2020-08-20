#include "IOUserService.h"
#include <iostream>
#include <string>


using namespace std;

void IOUserService::startUserOperations() {
    int select = 1;
    while (select) {
        cout << "(Операции с пользователями) Выберите действие:\n"
                "0 - вернуться в главное меню\n"
                "1 - посмотреть список пользователей\n"
                "2 - выбрать текущего пользователя\n"
                "3 - информация о текущем пользователе\n"
                "4 - добавить нового пользователя\n"
                "5 - удалить пользователя\n";

        select = Utils::getSelectIntCin(0 ,5);
        switch (select) {
            case 1:
                displayUsers();
                break;

            case 2:
                selectUser();
                break;

            case 3:
                displayCurrentUser();
                break;

            case 4:
                addUser();
                break;

            case 5:
                deleteUser();
                break;
        }
    }
}

void IOUserService::displayUsers() {
    cout << "\n";

    if(userList.getLastItemIndex() == 0){
        cout << "Список пользователей пуст\n";
    } else {
        cout << "id name user_type\n";

        for (int i = 0; i < userList.getLastItemIndex(); ++i) {
            cout << userList[i].toString() << "\n";
        }
    }
    cout << "\n";
}

void IOUserService::addUser() {
    cout << "\n";

    cout << "Введите имя пользователя:";
    string name;
    cin >> name;

    cout << "Введите номер типа пользователя\n"
         << "0 - wholesale; 1 - retail;\n";

    int user_type = Utils::getSelectIntCin(0 ,1);

    switch (user_type) {
        case 0:
            userList.add(User(name, UserType::wholesale));
            break;
        case 1:
            userList.add(User(name, UserType::retail));
            break;
    }

    cout << "\n";
}

int IOUserService::deleteUser() {
    cout << "\n";

    cout << "Введите id удаляемого пользователя\n";
    unsigned int id = Utils::getIdCin();

    if(id == currentUser.getId()) {
        cout << "Вы не можете удалить текущего выбранного пользователя\n";
    } else{
        if(userList.remove(id)){
            cout << "Пользователь удалён\n";
        } else{
            cout << "Пользователь с указанным id не найден\n";
        }
    }
    cout << "\n";
}

void IOUserService::displayCurrentUser() {
    cout << "\n";

    if(currentUser.getId() == 0) {
        cout << "Текущий пользователь не выбран\n";
    } else {
        cout << "\nТекущий пользователь: " << currentUser.toString() << "\n";
    }

    cout << "\n";
}

void IOUserService::selectUser() {
    cout << "\n";

    cout << "Чтобы выбрать текущего пользователя - введите id пользователя\n";
    unsigned int id = Utils::getIdCin();
    User* user = userList.getUserById(id);
    if(user != nullptr){
        currentUser = *user;
        cout << "Пользователь выбран\n";
    } else {
        cout << "Пользователь с введённыи id не найден\n";
    }

    cout << "\n";
}