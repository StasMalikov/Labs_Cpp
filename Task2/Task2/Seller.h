#pragma once

#include "ProductUnit.h"
#include <vector>
#include "Supplier.h"


class Seller
{
private:
	int m_id;
	std::vector<ProductUnit> m_products;
	int m_sizeLimit;
	Supplier* m_suplier;

public:
	void orderProduct(int prod_id, int count);
	int getSizeLimit();
	void setSizeLimit(int sizeLimit);
	//virtual ProductUnit sell(int prod_id, int count);
	int getId();
	Seller(Supplier* suplier, int sizeLimit);
	Seller();
	virtual ~Seller();
};

