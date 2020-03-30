#include "pch.h"
#include "TradeOrganization.h"
#include <iostream>


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

void TradeOrganization::printUsers() {
	for (size_t i = 0; i < m_users.size(); ++i) {
		m_users[i].print();
	}
}

void TradeOrganization::addUser(std::string name, UserType type) {

	m_users.push_back(User(name, type));
}

TradeOrganization::TradeOrganization() : m_currentUserId() {}

TradeOrganization::~TradeOrganization() {}