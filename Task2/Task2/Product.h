#pragma once

#include <string>

enum class ProductType {

	MEAT,

	// ПЛОДООВОЩНОЙ ТИП
	HORTICULTURAL,

	//вкусовой
	GUSTATORY,

	//МОЛОЧНЫЙ
	DAIRY,

	//КОНДИТЕРСКИЙ
	CONFECTIONERY
};

class Product {

	private:

		int id;

		std::string name;

		//размер, занимаемый в машине при транспортировке
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

