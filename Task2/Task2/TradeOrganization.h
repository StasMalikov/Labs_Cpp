#pragma once

#include <vector>
#include "User.h"
#include "Seller.h"


class TradeOrganization
{
private:
	std::vector<User> m_users;
	int m_currentUserId;
	std::vector<Seller> salePoints;

public:
	std::string usersToSrt();
	int getCurrentUserId();
	void setCurrentUserId(int id);
	void deleteUser(int id);
	void addUser(std::string name, UserType type);
	TradeOrganization();
	~TradeOrganization();
};