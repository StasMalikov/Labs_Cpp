#pragma once

#include "Seller.h"
#include "Customer.h"

class Shop : public Seller, public Customer
{
public:
	virtual int getId();
	Shop();
	virtual ~Shop();
};

