#pragma once

class IOService
{
public:
	IOService();
	~IOService();
	void Start();
	void BuyInShop();
	void BuyInWarehouse();
	void DisplayProducts(int key);
	void BuyProduct(int key);
};

