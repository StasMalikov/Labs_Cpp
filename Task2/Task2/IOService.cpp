#include "pch.h"
#include "IOService.h"
#include <iostream>

//	key->  1 - магазин, 2 - склад
void IOService::DisplayProducts(int key) {
	if (key == 1) {
		std::cout << "Список товаров магазина" << std::endl;
	}
	else if (key == 2) {
		std::cout << "Список товаров склада" << std::endl;
	}
}

//	key->  1 - магазин, 2 - склад
void IOService::BuyProduct(int key) {
	int select = 1;
	while (select) {
		std::cout << "(Покупка товара) Выберите действие:" << std::endl;
		std::cout << "0 - выход" << std::endl;
		std::cout << "Введите индекс товара: ";
		int index = 0;
		std::cin >> index;
		if (index) {
			std::cout << "Введите количество товара: ";
			int count = 0;
			std::cin >> count;
			if (count) {
				std::cout << "Вы купили товар" << std::endl;
			}
			else {
				select = 0;
			}
		}
		else {
			select = 0;
		}
	}
}

void IOService::BuyInShop() {
	int select = 1;
	while (select) {
		std::cout << "(Магазин) Выберите действие:" << std::endl;
		std::cout << "0 - выход" << std::endl;
		std::cout << "1 - посмотреть список товаров" << std::endl;
		std::cout << "2 - купить товар" << std::endl;
		std::cin >> select;

		switch (select) {
		case 1:
			DisplayProducts(1);
			break;
		case 2:
			BuyProduct(1);
			break;
		}
	}
}


void IOService::BuyInWarehouse (){
	int select = 1;
	while (select) {
		std::cout << "(Склад) Выберите действие:" << std::endl;
		std::cout << "0 - выход" << std::endl;
		std::cout << "1 - купить товары на складе (оптом)" << std::endl;
		std::cout << "2 - купить товары в магазине (в розницу)" << std::endl;
		std::cin >> select;

		switch (select) {
		case 1:
			BuyInWarehouse();
			break;
		case 2:
			BuyInShop();
			break;
		}
	}
}


void IOService::Start() {
	int select = 1;
	while (select) {
		std::cout << "(Главное меню) Выберите действие:" << std::endl;
		std::cout << "0 - выход" << std::endl;
		std::cout << "1 - купить товары на складе (оптом)" << std::endl;
		std::cout << "2 - купить товары в магазине (в розницу)" << std::endl;
		std::cin >> select;

		switch (select) {
			case 1:
				BuyInWarehouse();
				break;
			case 2:
				BuyInShop();
				break;
		}
	}
}


IOService::IOService()
{
}

IOService::~IOService()
{
}