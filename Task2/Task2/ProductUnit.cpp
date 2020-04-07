#include "pch.h"
#include "ProductUnit.h"
#include <iostream>
#include <sstream>


std::string ProductUnit::toStr() {
	std::stringstream ss;

	ss << m_count;
	std::string count = ss.str();

	return m_product->toStr() + " " + count;
}

//void ProductUnit::print() {
//	std::cout << toStr() << std::endl;
//}


//ProductUnit* ProductUnit::getProductToBasket(int count) {
//	ProductUnit *pu;
//
//	if (count <= m_count) {
//		pu = new ProductUnit(m_product, count);
//		m_count -= count;
//	}
//	else {
//		pu = new ProductUnit(m_product, m_count);
//		m_count = 0;
//	}
//	
//	return pu;
//}

Product* ProductUnit::getProduct() { return m_product; }

int ProductUnit::getCount() { return m_count; }

void ProductUnit::setCount(int count) { m_count = count; }

ProductUnit::ProductUnit(Product *product, int count) : m_product(product), m_count(count) {}

ProductUnit::~ProductUnit() {}
