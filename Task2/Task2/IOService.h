#pragma once

#include "TradeOrganization.h"

class IOService
{
private:
	TradeOrganization *TO;
public:
	void selectUser();
	void userOperations();
	IOService(TradeOrganization *to);
	~IOService();
	void start();
	void buyInShop();
	void buyInWarehouse();
	//void displayProducts(int key);
	void buyProduct(int key);
	void displayUsers();
	void deleteUser();
	void addUser();
	void shopOperations();
	void warehouseOperations();
};
