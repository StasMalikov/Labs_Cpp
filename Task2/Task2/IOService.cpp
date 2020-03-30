#include "pch.h"
#include "IOService.h"
#include <iostream>

//	key->  1 - магазин, 2 - склад
void IOService::displayProducts(int key) {
	if (key == 1) {
		std::cout << "Список товаров магазина" << std::endl;
	}
	else if (key == 2) {
		std::cout << "Список товаров склада" << std::endl;
	}
}

//	key->  1 - магазин, 2 - склад
void IOService::buyProduct(int key) {
	int select = 1;
	while (select) {
		std::cout << std::endl << "(Покупка товара) Выберите действие:" << std::endl;
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

void IOService::buyInShop() {
	int select = 1;
	while (select) {
		std::cout << std::endl << "(Магазин) Выберите действие:" << std::endl;
		std::cout << "0 - выход" << std::endl;
		std::cout << "1 - посмотреть список товаров" << std::endl;
		std::cout << "2 - купить товар" << std::endl;
		std::cin >> select;

		switch (select) {
		case 1:
			displayProducts(1);
			break;
		case 2:
			buyProduct(1);
			break;
		}
	}
}


void IOService::buyInWarehouse (){
	int select = 1;
	while (select) {
		std::cout << std::endl << "(Склад) Выберите действие:" << std::endl;
		std::cout << "0 - выход" << std::endl;
		std::cout << "1 - посмотреть список товаров" << std::endl;
		std::cout << "2 - купить товар" << std::endl;
		std::cin >> select;

		switch (select) {
		case 1:
			displayProducts(2);
			break;
		case 2:
			buyProduct(2);
			break;
		}
	}
}

void IOService::selectUser() {
	std::cout << std::endl << "Введите id пользователя:" << std::endl;
	int select = 1;
	std::cin >> select;
	TO->setCurrentUserId(select);
}

void IOService::displayUsers() {
	std::cout << std::endl << "Id Username Type" << std::endl;
	TO->printUsers();
}

void IOService::deleteUser() {
	std::cout << std::endl << "Введите id удаляемого пользователя:" << std::endl;
	int select = 1;
	std::cin >> select;
	TO->deleteUser(select);
}

void IOService::addUser()
{
	int select = 1;
	std::cout << std::endl << "Добавление пользователя" << std::endl;
	std::cout << "Введите username пользователя: ";
	std::string username = "";
	std::cin >> username;

	std::cout << "1 - WHORESALE 2 -RETAIL"<< std::endl;
	std::cout << "Введите type пользователя: ";
	int type = 0;
	std::cin >> type;

	switch (type)
	{
	case 1:
		TO->addUser(username, UserType::WHORESALE);
		break;

	case 2:
		TO->addUser(username, UserType::RETAIL);
		break;
	}
	
}

void IOService::userOperations() {
	int select = 1;
	while (select) {
		std::cout << std::endl << "(Операции с пользователем) Выберите действие:" << std::endl;
		std::cout << "0 - выход" << std::endl;
		std::cout << "1 - список пользоветелей" << std::endl;
		std::cout << "2 - выбор пользователя" << std::endl;
		std::cout << "3 - добавить пользователя" << std::endl;
		std::cout << "4 - удалить пользователя" << std::endl;
		std::cin >> select;

		switch (select) {
		case 1:
			displayUsers();
			break;
		case 2:
			selectUser();
			break;

		case 3:
			addUser();
			break;

		case 4:
			deleteUser();
			break;
		}
	}
}

void IOService::start() {
	int select = 1;
	while (select) {
		std::cout << std::endl << "(Главное меню) Выберите действие:" << std::endl;
		std::cout << "0 - выход" << std::endl;
		std::cout << "1 - купить товары на складе (оптом)" << std::endl;
		std::cout << "2 - купить товары в магазине (в розницу)" << std::endl;
		std::cout << "3 - операции с пользователями" << std::endl;
		std::cin >> select;

		switch (select) {
			case 1:
				buyInWarehouse();
				break;
			case 2:
				buyInShop();
				break;

			case 3:
				userOperations();
				break;
		}
	}
}

IOService::IOService(TradeOrganization *to) : TO(to) {}

IOService::~IOService() {}