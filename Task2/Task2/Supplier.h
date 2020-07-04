#pragma once

#include <vector>
#include "ProductUnit.h"
#include "DeliveryService.h"

//поставщик
class Supplier
{
private:
	std::vector<Product> m_products;
	DeliveryService *m_deliverySevice;

public:

	std::string getProductsToStr();
	ProductUnit getProduct(int product_id, int count);
	void addProduct(Product product);
	void deleteProduct(int id);
	
	Supplier(DeliveryService *deliveryService);
	~Supplier();
};

