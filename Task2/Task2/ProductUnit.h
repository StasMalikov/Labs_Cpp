#pragma once

#include "Product.h"

class ProductUnit
{
private:
	Product *m_product;
	int m_count;

public:
	std::string toStr();
	Product* getProduct();
	int getCount();
	void setCount(int count);
	ProductUnit(Product *product, int count);
	~ProductUnit();
};

