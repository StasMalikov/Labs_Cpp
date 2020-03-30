#include "pch.h"
#include "User.h"
#include <iostream>
#include <sstream>
#include "IdGenerator.h"

//ProductUnit User::deleteUnit(int id)
//{
//	return ProductUnit();
//}


std::string User::toStr() {
	std::stringstream ss;

	ss << m_id;
	std::string id = ss.str();

	return id + " " + m_username + " " + getTypeToStr();
}

void User::print() {
	std::cout << toStr() << std::endl;
}


int User::getId()
{
	return m_id;
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

void User::clearBasket()
{
	m_basket.clear();
}

std::vector<ProductUnit> User::getBasket() {
	return m_basket;
}

void User::addToBasket(ProductUnit unit)
{
	m_basket.push_back(unit);
}

User::User(std::string name, UserType type) : m_id(IdGenerator::getNextId()), m_username(name), m_type(type) {}

User::User() : m_id(IdGenerator::getNextId()) {}

User::~User() {}
