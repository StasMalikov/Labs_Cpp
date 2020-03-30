#pragma once

#include <vector>
#include "User.h"


class TradeOrganization
{
private:
	std::vector<User> m_users;
	int m_currentUserId;

public:
	void printUsers();
	int getCurrentUserId();
	void setCurrentUserId(int id);
	void deleteUser(int id);
	void addUser(std::string name, UserType type);
	TradeOrganization();
	~TradeOrganization();
};

