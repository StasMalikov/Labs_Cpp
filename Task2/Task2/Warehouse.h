#pragma once

#include "Seller.h"
#include "Customer.h"

class Warehouse : public Seller, public Customer
{
private:
	int minProdCount;

public:
	virtual int getId();
	Warehouse();
	virtual ~Warehouse();
};