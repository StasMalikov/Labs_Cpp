#include <iostream>


// compare
// 0 - equal
// 1 first arg more
// 2 second arg more

template<class T, int compare(T,T)>
void qsortRecursive(T *mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    T mid = mas[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(compare(mas[i], mid) == 2) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(compare(mas[j], mid) == 1) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            T tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        qsortRecursive<T, compare>(mas, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
        qsortRecursive<T, compare>(&mas[i], size - i);
    }
}

int intCompare(int first, int second){
    if(first > second){
        return 1;
    } else if (first < second){
        return 2;
    } else {
        return 0;
    }
}

int strCompare(std::string first, std::string second){
    if(first > second){
        return 1;
    } else if (first < second){
        return 2;
    } else {
        return 0;
    }
}


int main() {
    int *arr;
    arr = new int[10];
    arr[0] = 10;
    arr[1] = 9;
    arr[2] = 50;
    arr[3] = 8;
    arr[4] = 7;
    arr[5] = 6;
    arr[6] = 5;
    arr[7] = 4;
    arr[8] = 3;
    arr[9] = 2;

    qsortRecursive<int, &intCompare>(arr, 10);

    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << "\n";
    }

    delete [] arr;

    std::cout << "\n str example \n";

    std::string *arrStr;
    arrStr = new std::string[10];
    arrStr[0] = "1111111111";
    arrStr[1] = "111111111";
    arrStr[2] = "11111111";
    arrStr[3] = "1111111";
    arrStr[4] = "111111";
    arrStr[5] = "11111";
    arrStr[6] = "1111";
    arrStr[7] = "111";
    arrStr[8] = "11";
    arrStr[9] = "1";

    qsortRecursive<std::string, &strCompare>(arrStr, 10);

    for (int i = 0; i < 10; ++i) {
        std::cout << arrStr[i] << "\n";
    }

    delete [] arrStr;
    return 0;
}

//void qsortRecursive1(int *mas, int size) {
//    //Указатели в начало и в конец массива
//    int i = 0;
//    int j = size - 1;
//
//    //Центральный элемент массива
//    int mid = mas[size / 2];
//
//    //Делим массив
//    do {
//        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
//        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
//        while(mas[i] < mid) {
//            i++;
//        }
//        //В правой части пропускаем элементы, которые больше центрального
//        while(mas[j] > mid) {
//            j--;
//        }
//
//        //Меняем элементы местами
//        if (i <= j) {
//            int tmp = mas[i];
//            mas[i] = mas[j];
//            mas[j] = tmp;
//
//            i++;
//            j--;
//        }
//    } while (i <= j);
//
//
//    //Рекурсивные вызовы, если осталось, что сортировать
//    if(j > 0) {
//        //"Левый кусок"
//        qsortRecursive1(mas, j + 1);
//    }
//    if (i < size) {
//        //"Првый кусок"
//        qsortRecursive1(&mas[i], size - i);
//    }
//}