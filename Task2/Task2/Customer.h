#pragma once

enum class CustomerType {

	USER,
	SHOP,
	WAREHOUSE

};

class Customer
{
private:
 	CustomerType m_type;

public:
	virtual int getId();
	CustomerType getType();

	Customer(CustomerType type);
	virtual ~Customer();
};