#pragma once

#include <string>
#include <vector>
#include "ProductUnit.h"

enum class UserType {

	//оптовый
	WHORESALE,

	//розничный
	RETAIL
};

class User {

private:
	int m_id;
	std::string m_username;
	std::vector<ProductUnit> m_basket;
	UserType m_type;

public:
	/*ProductUnit deleteUnit(int id);*/
	int getId();
	std::string getTypeToStr();
	std::string toStr();
	void clearBasket();
	std::vector<ProductUnit> getBasket();
	void addToBasket(ProductUnit unit);
	User(std::string name, UserType type);
	User();
	~User();
};

