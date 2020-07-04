#include "pch.h"
#include "Warehouse.h"


int Warehouse::getId() { return Seller::getId(); }

Warehouse::Warehouse() : Customer(CustomerType::WAREHOUSE){}

Warehouse::~Warehouse(){}