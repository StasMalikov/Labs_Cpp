//
// Created by stas_malikov on 11.08.2020.
//

#include "IOUserService.h"

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

        select = 0;
//        switch (select) {
//            case 1:
//                displayUsers();
//                break;
//            case 2:
//                selectUser();
//                break;
//
//            case 3:
//                addUser();
//                break;
//
//            case 4:
//                deleteUser();
//                break;
//        }
    }
}