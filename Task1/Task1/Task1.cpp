#include "pch.h"
#include <iostream>
#include <string.h>
#include <locale.h>
#pragma warning(disable : 4996)

// Маликов С.А.

//http://all-ht.ru/inf/prog/c/func/memccpy.html
//Аргументы:
//
//		 destination – указатель на массив в который будут скопированы данные.
//			 source – указатель на массив источник копируемых данных.
//			 c – код символа, при встрече которого копирование завершается.
//			 n – количество байт для копирования.
//
//			 Возвращаемое значение :
//
//		 Функция возвращает указатель на массив, в который скопированы данные,
//					если скопировано n байт.
//			 NULL если в первых n байтах массива источника встречен символ, 
//						код которого соответствует указанному в аргументе c.
//
//			 Описание :
//
//			 Функция memccpy копирует данные из массива(области памяти), на который 
//				указывает аргумент source, в массив(область памяти), на который указывает аргумент 
//				destination пока не встретится символ, код которого соответствует указанному в аргументе c
//				или пока не будет скопировано n байт данных.


char* my_memccpy(char* destination, const char* source, int c, size_t n) {
	for (int i = 0; i < n; i++)
	{
		destination[i] = *(source + i);
		if (*(source + i) == c) {
			return NULL;
		}
	}
	return destination;
}

int main(void) {
	setlocale(LC_ALL, "Russian");

	char source[60] = "text_f_text";
	printf("Массив из которого копируем: %s\n\n", source);

	//1
	printf("Пример 1\n");
	char destination1_1[60] = "";
	char destination1_2[60] = "";
	memccpy(destination1_1, source, 'f', 30);
	printf("Результат встроенной функции: %s\n", destination1_1);
	my_memccpy(destination1_2, source, 'f', 30);
	printf("Результат самописной функции: %s\n\n", destination1_2);

	// 2 
	printf("Пример 2\n");
	char destination2_1[60] = "12345678";
	char destination2_2[60] = "12345678";
	memccpy(destination2_1, source, 'f', 30);
	printf("Результат встроенной функции: %s\n", destination2_1);
	my_memccpy(destination2_2, source, 'f', 30);
	printf("Результат самописной функции: %s\n\n", destination2_2);

	//3
	printf("Пример 3\n");
	char destination3_1[60] = "12345678";
	char destination3_2[60] = "12345678";
	memccpy(destination3_1, source, 'q', 30);
	printf("Результат встроенной функции: %s\n", destination3_1);
	my_memccpy(destination3_2, source, 'q', 30);
	printf("Результат самописной функции: %s\n\n", destination3_2);

	//1
	//printf("Пример 4\n");
	//memccpy(destination1_1, source, 'f', 30);
	//printf("Результат встроенной функции: %s\n", destination1_1);
	//my_memccpy(NULL, source, 'f', 30);
	//printf("Результат самописной функции: %s\n\n", destination1_2);
}