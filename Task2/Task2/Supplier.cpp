#include "pch.h"
#include "Supplier.h"


//void Supplier::printProducts()
//{
//	for (size_t i = 0; i < m_products.size(); ++i) {
//		m_products[i].print();
//	}
//}

ProductUnit Supplier::getProduct(int product_id, int count)
{
	for (size_t i = 0; i < m_products.size(); ++i) {
		if (m_products[i].getId() == product_id) {
			return ProductUnit(&m_products[i], count);
		}
	}
}

void Supplier::addProduct(Product product) { m_products.push_back(product); }

void Supplier::deleteProduct(int id)
{
	for (size_t i = 0; i < m_products.size(); ++i) {
		if (m_products[i].getId() == id) {
			m_products.erase(m_products.begin() + i);
			break;
		}
	}
}

Supplier::Supplier(){}


Supplier::~Supplier(){}
