#include "pch.h"
#include "IOService.h"
#include <iostream>

//	key->  1 - магазин, 2 - склад
void IOService::buyProduct(int key) {
	int select = 1;
	while (select) {
		std::cout << std::endl << "(ѕокупка товара) ¬ыберите действие:" << std::endl;
		std::cout << "0 - выход" << std::endl;
		std::cout << "¬ведите индекс товара: ";
		int index = 0;
		std::cin >> index;
		if (index) {
			std::cout << "¬ведите количество товара: ";
			int count = 0;
			std::cin >> count;
			if (count) {
				std::cout << "¬ы купили товар" << std::endl;
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
		std::cout << std::endl << "(ћагазин) ¬ыберите действие:" << std::endl;
		std::cout << "0 - выход" << std::endl;
		std::cout << "1 - посмотреть список товаров" << std::endl;
		std::cout << "2 - купить товар" << std::endl;
		std::cin >> select;

		switch (select) {
		case 1:
			//displayProducts(1);
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
		std::cout << std::endl << "(—клад) ¬ыберите действие:" << std::endl;
		std::cout << "0 - выход" << std::endl;
		std::cout << "1 - посмотреть список товаров" << std::endl;
		std::cout << "2 - купить товар" << std::endl;
		std::cin >> select;

		switch (select) {
		case 1:
			//displayProducts(2);
			break;
		case 2:
			buyProduct(2);
			break;
		}
	}
}

void IOService::selectUser() {
	std::cout << std::endl << "¬ведите id выбираемого пользовател€:" << std::endl;
	int select = 1;
	std::cin >> select;
	TO->setCurrentUserId(select);
}

void IOService::displayUsers() {
	std::cout << std::endl << "Id Username Type" << std::endl;
	std::cout << TO->usersToSrt();
}

void IOService::deleteUser() {
	std::cout << std::endl << "¬ведите id удал€емого пользовател€:" << std::endl;
	int select = 1;
	std::cin >> select;
	TO->deleteUser(select);
}

void IOService::addUser()
{
	int select = 1;
	std::cout << std::endl << "ƒобавление пользовател€" << std::endl;
	std::cout << "¬ведите username пользовател€: ";
	std::string username = "";
	std::cin >> username;

	std::cout << "1 - WHORESALE 2 -RETAIL"<< std::endl;
	std::cout << "¬ведите type пользовател€: ";
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
		std::cout << std::endl << "(ќперации с пользователем) ¬ыберите действие:" << std::endl;
		std::cout << "0 - выход" << std::endl;
		std::cout << "1 - список пользоветелей" << std::endl;
		std::cout << "2 - выбор пользовател€" << std::endl;
		std::cout << "3 - добавить пользовател€" << std::endl;
		std::cout << "4 - удалить пользовател€" << std::endl;
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

void IOService::shopOperations()
{
	int select = 1;
	while (select) {
		std::cout << std::endl << "(ќперации с магазином) ¬ыберите действие:" << std::endl;
		std::cout << "0 - выход" << std::endl;
		std::cout << "1 - список магазинов" << std::endl;
		std::cout << "2 - выбор магазина" << std::endl;
		std::cout << "3 - добавить магазин" << std::endl;
		std::cout << "4 - удалить магазин" << std::endl;
		std::cin >> select;

		switch (select) {
		case 1:
			break;
		case 2:
			break;

		case 3:
			break;

		case 4:
			break;
		}
	}
}

void IOService::warehouseOperations()
{
	int select = 1;
	while (select) {
		std::cout << std::endl << "(ќперации со складом) ¬ыберите действие:" << std::endl;
		std::cout << "0 - выход" << std::endl;
		std::cout << "1 - список складов" << std::endl;
		std::cout << "2 - выбор склада" << std::endl;
		std::cout << "3 - добавить склад" << std::endl;
		std::cout << "4 - удалить склад" << std::endl;
		std::cin >> select;

		switch (select) {
		case 1:
			break;
		case 2:
			break;

		case 3:
			break;

		case 4:
			break;
		}
	}
}

void IOService::start() {
	int select = 1;
	while (select) {
		std::cout << std::endl << "(√лавное меню) ¬ыберите действие:" << std::endl;
		std::cout << "0 - выход" << std::endl;
		std::cout << "1 - купить товары на складе (оптом)" << std::endl;
		std::cout << "2 - купить товары в магазине (в розницу)" << std::endl;
		std::cout << "3 - операции с пользовател€ми" << std::endl;
		std::cout << "4 - операции с магазинами" << std::endl;
		std::cout << "5 - операции со складами" << std::endl;
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

			case 4:
				shopOperations();
				break;

			case 5:
				warehouseOperations();
				break;
		}
	}
}

IOService::IOService(TradeOrganization *to) : TO(to) {}

IOService::~IOService() {}