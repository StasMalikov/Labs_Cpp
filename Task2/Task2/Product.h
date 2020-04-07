#pragma once

#include <string>
#include "IdGenerator.h"

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

		int m_id;

		std::string m_name;

		//размер, занимаемый в машине при транспортировке или на складе/магазине
		int m_size;

		ProductType m_type;


	public:
		std::string toStr();
		Product();
		Product(std::string name, int size, ProductType type);
		~Product();
		int getId();
		std::string getName();
		//
		void setName(std::string name);
		int getSize();

		//
		void setSize(int size);
		ProductType getType();
		//
		void setType(ProductType type);
		std::string getTypeToStr();

};

