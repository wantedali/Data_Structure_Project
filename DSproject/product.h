#ifndef PRODUCT_H
#define PRODUCT_H
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
using namespace std;

class product {
public:
	int ID;
	std::string Name;
	float Price;
	std::string Category;
	int Quantity;
	int SellerID;
	float Rate = 0;
	string seller_email;
	void ShowInfo();

};

#endif // PRODUCT_H
