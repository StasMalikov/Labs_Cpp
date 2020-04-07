#pragma once

#include "Seller.h"


class Warehouse : public Seller
{
private:
	int minProdCount;

public:
	Warehouse();
	virtual ~Warehouse();
};

