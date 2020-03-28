#pragma once

#include <string>

enum class ProductType {

	MEAT,

	// ������������ ���
	HORTICULTURAL,

	//��������
	GUSTATORY,

	//��������
	DAIRY,

	//������������
	CONFECTIONERY
};

class Product {

	private:

		int id;

		std::string name;

		//������, ���������� � ������ ��� ���������������
		int size;

		ProductType type;


	public:
		Product();
		~Product();
		int GetId();
		int SetId();
		std::string GetName();
		std::string Setname();
		int GetSize();
		int SetSize();
		ProductType GetType();
		ProductType SetType();

};

