#include "pch.h"
#include "Customer.h"

int Customer::getId() { return 0; }

CustomerType Customer::getType() { return m_type; }

Customer::Customer(CustomerType type) : m_type(type) {}

Customer::~Customer() {}