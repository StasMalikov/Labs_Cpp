#pragma once

#include <vector>
#include "ProductUnit.h"

//���������
class Supplier
{
private:
	std::vector<Product> m_products;

public:
	ProductUnit getProduct(int product_id, int count);
	void addProduct(Product product);
	void deleteProduct(int id);
	Supplier();
	~Supplier();
};

