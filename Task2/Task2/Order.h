#pragma once

#include "Customer.h"
#include <vector>
#include "ProductUnit.h"

enum class OrderStatus {

	OPEN,
	CLOSED,
	IN_DELIVERY

};

class Order
{
private:
	int m_id;
	Customer* m_customer;
	std::vector<ProductUnit> m_productUnits;
	OrderStatus m_status;

public:
	void addProductUnit(ProductUnit productUnit);
	std::vector<ProductUnit> getProductUnits();
	int getSummProductsSize();
	OrderStatus getStatus();
	void setStatus(OrderStatus status);

	Order(Customer* customer);
	Order();
	~Order();
};

