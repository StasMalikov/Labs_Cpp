#include "pch.h"
#include "TradeOrganization.h"
#include <iostream>

// схема заказа
// заказчик -> торговая организация -> поставщик/продавец -> заказ -> доставщик -> заказчик

void TradeOrganization::deleteUser(int id) {
	for (size_t i = 0; i < m_users.size(); ++i) {
		if (m_users[i].getId() == id) {
			m_users.erase(m_users.begin() + i);
			break;
		}
	}
}

int TradeOrganization::getCurrentUserId() {
	return m_currentUserId;
}

void TradeOrganization::setCurrentUserId(int id) {
	m_currentUserId = id;
}

std::string TradeOrganization::usersToSrt() {
	std::string str;
	for (size_t i = 0; i < m_users.size(); ++i) {
		str += m_users[i].toStr() + "\n";
	}
	return str;
}

//void TradeOrganization::printUsers() {
//	for (size_t i = 0; i < m_users.size(); ++i) {
//		m_users[i].print();
//	}
//}

void TradeOrganization::addUser(std::string name, UserType type) {

	m_users.push_back(User(name, type));
}

TradeOrganization::TradeOrganization() : m_currentUserId() {}

TradeOrganization::~TradeOrganization() {}