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
                "2 - операции с поставками продуктов\n"
                "3 - операции с оптовой торговлей\n"
                "4 - операции с пользователями\n";

        select = Utils::getSelectIntCin(0 ,4);
        switch (select) {
            case 1: {
                break;
            }

            case 2: {
                ioSupplierService.startSupplierOperations();
                break;
            }

            case 3: {

                break;
            }

            case 4: {
                ioUserService.startUserOperations();
                break;
            }
        }
    }
}