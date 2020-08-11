//
// Created by stas_malikov on 04.08.2020.
//

#ifndef NEWTASK2_UTILS_H
#define NEWTASK2_UTILS_H

#include <iostream>

class Utils {
public:
    static unsigned int generateId(){
        static unsigned int id;
        return ++id;
    }

    static int getSelectIntCin(int minSelect, int maxSelect) {
        const int ignoreLimit = 32767;
        int select;
        while (true) {
            std::cout << "Ввод: ";
            std::cin >> select;

            if (std::cin.fail()) { // если предыдущее извлечение было неудачным,
                std::cin.clear(); // возвращаем cin в 'обычный' режим работы
            }

            std::cin.ignore(ignoreLimit, '\n');

            if(select >= minSelect && select <= maxSelect) {
                return select;
            } else {
                std::cout << "Вы ввели неверное значение (введите число от " << minSelect << " до " << maxSelect << ")\n";
            }
        }
    }
};

#endif //NEWTASK2_UTILS_H