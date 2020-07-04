#include "pch.h"
#include "User.h"
#include <iostream>
#include <sstream>
#include "IdGenerator.h"


std::string User::toStr() {
	std::stringstream ss;

	ss << m_id;
	std::string id = ss.str();

	return id + " " + m_username + " " + getTypeToStr();
}

std::string User::getTypeToStr()
{
	if (m_type == UserType::RETAIL) {
		return "RETAIL";
	}
	else if (m_type == UserType::WHORESALE) {
		return "WHORESALE";
	}

	return std::string();
}

void User::addProducts(std::vector<ProductUnit> products)
{
	for (size_t i = 0; i < products.size(); ++i) {
		m_products.push_back(products[i]);
	}
}

int User::getId() { return m_id; }

User::User(std::string name, UserType type) : m_id(IdGenerator::getNextId()), m_username(name), m_type(type), Customer(CustomerType::USER) {}

User::User() : m_id(IdGenerator::getNextId()), Customer(CustomerType::USER) {}

User::~User() {}
