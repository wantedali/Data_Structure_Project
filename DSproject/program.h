#pragma once
#include<iostream>
#include<unordered_map>
#include"DS.h"

using namespace std;
class program
{
public:
	unordered_map<string, Customer*> customers;
	unordered_map<string, Seller*> sellers;
};