#include "pch.h"
#include "Order.h"
#include "IdGenerator.h"

int Order::getSummProductsSize()
{
	int summ = 0;
	for (size_t i = 0; i < m_productUnits.size(); ++i) {
		summ += m_productUnits[i].getCount() * m_productUnits[i].getProduct()->getSize();
	}
	return summ;
}

OrderStatus Order::getStatus() { return m_status; }

void Order::setStatus(OrderStatus status) { m_status = status; }

void Order::addProductUnit(ProductUnit productUnit) { m_productUnits.push_back(productUnit); }

std::vector<ProductUnit> Order::getProductUnits() { return m_productUnits; }

Order::Order(Customer * customer) : m_id(IdGenerator::getNextId()), m_customer(customer), m_status(OrderStatus::OPEN){}

Order::Order() : m_id(IdGenerator::getNextId()), m_status(OrderStatus::OPEN) {}

Order::~Order(){}