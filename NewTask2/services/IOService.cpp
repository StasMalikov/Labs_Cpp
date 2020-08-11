#include "IOService.h"
#include <iostream>
#include "Utils.h"

using namespace std;

void IOService::start() {
    int select = 1;
    while (select) {
        cout << "(Главное меню) Выберите действие:\n"
                "0 - выход из приложения\n"
                "1 - операции с розничной торговлей\n"
                "2 - операции с оптовой торговлей\n"
                "3 - операции с пользователями\n";

        select = Utils::getSelectIntCin(0 ,3);
        switch (select) {
            case 1:{
                break;
            }

            case 2: {
                break;
            }

            case 3: {
                ioUserService.startUserOperations();
                break;
            }
        }
    }
}