#pragma once

#include "Product.h"

class ProductUnit
{
private:
	Product *m_product;
	int m_count;

public:
	std::string toStr();
	void print();
	Product* getProduct();
	int getCount();
	ProductUnit* getProductToBasket(int count);
	ProductUnit(Product *product, int count);
	~ProductUnit();
};

