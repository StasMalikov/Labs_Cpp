#pragma once

#include <string>
#include <vector>
#include "ProductUnit.h"
#include "Customer.h"

enum class UserType {

	//оптовый
	WHORESALE,

	//розничный
	RETAIL
};

class User : public Customer {

private:
	int m_id;
	std::string m_username;
	UserType m_type;
	std::vector<ProductUnit> m_products;


public:
	void addProducts(std::vector<ProductUnit> products);
	virtual int getId();
	std::string getTypeToStr();
	std::string toStr();
	//void buy(int prod_id, );
	User(std::string name, UserType type);
	User();
	~User();
};

