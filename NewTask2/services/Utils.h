//
// Created by stas_malikov on 04.08.2020.
//

#ifndef NEWTASK2_UTILS_H
#define NEWTASK2_UTILS_H

#include <iostream>



class Utils {
    static const int ignoreLimit = 32767;
public:
    static unsigned int generateId(){
        static unsigned int id;
        return ++id;
    }

    static int getSelectIntCin(long minSelect, long maxSelect) {
        int select;
        while (true) {
            std::cout << "Ввод: ";
            std::cin >> select;

            if (std::cin.fail()) { // если предыдущее извлечение было неудачным,
                std::cin.clear(); // возвращаем cin в 'обычный' режим работы
                std::cin.ignore(ignoreLimit, '\n');
                std::cout << "Вы ввели неверное значение, повторите ввод\n";
                continue;
            }

            std::cin.ignore(ignoreLimit, '\n');

            if(select >= minSelect && select <= maxSelect) {
                return select;
            } else {
                std::cout << "Вы ввели неверное значение (введите число от " << minSelect << " до " << maxSelect << ")\n";
            }
        }
    }

    static int getIdCin() {
        unsigned int max_id_size = 999999;
        return getSelectIntCin(1, max_id_size);
    }

    static std::string getSelectStringCin() {
        std::string input;

        std::cout << "Ввод: ";
        std::getline(std::cin, input);

        if (std::cin.fail()) { // если предыдущее извлечение было неудачным,
            std::cin.clear(); // возвращаем cin в 'обычный' режим работы
        }

        return input;
    }
};

#endif //NEWTASK2_UTILS_H