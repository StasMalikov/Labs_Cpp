#include "pch.h"
#include "Seller.h"
#include "IdGenerator.h"

//ProductUnit Seller::sell(int prod_id, int count){
//	for (size_t i = 0; i < m_products.size(); ++i) {
//		if (m_products[i].getProduct()->getId() == prod_id) {
//			if (m_products[i].getCount() > count) {
//				m_products[i].setCount(m_products[i].getCount() - count);
//				return ProductUnit(m_products[i].getProduct(), count);
//			}
//			else {
//				ProductUnit t(m_products[i].getProduct(), count);
//				m_products.erase(m_products.begin() + i);
//				return t;
//			}
//		}
//	}
//}


void Seller::orderProduct(int prod_id, int count)
{
	m_products.push_back(m_suplier->getProduct(prod_id, count));
}

void Seller::setSizeLimit(int sizeLimit) { m_sizeLimit = sizeLimit; }

int Seller::getSizeLimit() { return m_sizeLimit; }

int Seller::getId() { return m_id; }

Seller::Seller(Supplier * suplier, int sizeLimit) : m_suplier(suplier), m_sizeLimit(sizeLimit), m_id(IdGenerator::getNextId()) {}

Seller::Seller() : m_id(IdGenerator::getNextId()) {}

Seller::~Seller(){}