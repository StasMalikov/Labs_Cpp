#include "pch.h"
#include "IOService.h"
#include <iostream>

//	key->  1 - �������, 2 - �����
void IOService::DisplayProducts(int key) {
	if (key == 1) {
		std::cout << "������ ������� ��������" << std::endl;
	}
	else if (key == 2) {
		std::cout << "������ ������� ������" << std::endl;
	}
}

//	key->  1 - �������, 2 - �����
void IOService::BuyProduct(int key) {
	int select = 1;
	while (select) {
		std::cout << "(������� ������) �������� ��������:" << std::endl;
		std::cout << "0 - �����" << std::endl;
		std::cout << "������� ������ ������: ";
		int index = 0;
		std::cin >> index;
		if (index) {
			std::cout << "������� ���������� ������: ";
			int count = 0;
			std::cin >> count;
			if (count) {
				std::cout << "�� ������ �����" << std::endl;
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
		std::cout << "(�������) �������� ��������:" << std::endl;
		std::cout << "0 - �����" << std::endl;
		std::cout << "1 - ���������� ������ �������" << std::endl;
		std::cout << "2 - ������ �����" << std::endl;
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
		std::cout << "(�����) �������� ��������:" << std::endl;
		std::cout << "0 - �����" << std::endl;
		std::cout << "1 - ������ ������ �� ������ (�����)" << std::endl;
		std::cout << "2 - ������ ������ � �������� (� �������)" << std::endl;
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
		std::cout << "(������� ����) �������� ��������:" << std::endl;
		std::cout << "0 - �����" << std::endl;
		std::cout << "1 - ������ ������ �� ������ (�����)" << std::endl;
		std::cout << "2 - ������ ������ � �������� (� �������)" << std::endl;
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