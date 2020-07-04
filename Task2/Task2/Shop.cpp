#include "pch.h"
#include "Shop.h"


int Shop::getId() { return Seller::getId(); }

Shop::Shop() : Customer(CustomerType::SHOP) {}

Shop::~Shop(){}