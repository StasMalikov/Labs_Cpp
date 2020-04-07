#include "pch.h"
#include "Product.h"
#include <iostream>
#include <sstream>


std::string Product::toStr()
{
	std::stringstream ss;

	ss << m_id;
	std::string id = ss.str();

	ss << m_size;
	std::string size = ss.str();

	return id + " " + m_name + " " + size + " " +  getTypeToStr();
}

Product::Product() : m_id(IdGenerator::getNextId()) {}

Product::Product(std::string name, int size, ProductType type) 
	: m_id(IdGenerator::getNextId()), m_name(name), m_size(size), m_type(type) {}


//void Product::print()
//{ 
//	std::cout << toStr() << std::endl;
//}

std::string Product::getTypeToStr()
{
	if (m_type == ProductType::MEAT) {
		return "MEAT";
	} else if (m_type == ProductType::HORTICULTURAL) {
		return "HORTICULTURAL";
	}
	else if (m_type == ProductType::GUSTATORY) {
		return "GUSTATORY";
	}
	else if (m_type == ProductType::DAIRY) {
		return "DAIRY";
	}
	else if (m_type == ProductType::CONFECTIONERY) {
		return "CONFECTIONERY";
	}

	return std::string();
}


int Product::getId() { return m_id; }

std::string Product::getName() { return m_name; }

void Product::setName(std::string name) { m_name = name; }

int Product::getSize() { return m_size; }

void Product::setSize(int size) { m_size = size; }

ProductType Product::getType() { return m_type; }

void Product::setType(ProductType type) { m_type = type; }

Product::~Product(){}
