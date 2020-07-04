#pragma once

#include "TradeOrganization.h"
#include "Supplier.h"

class IOService
{
private:
	TradeOrganization *TO;
	Supplier *suplier;
public:
	void selectUser();
	void userOperations();
	IOService(TradeOrganization *to, Supplier *su);
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
