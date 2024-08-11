#pragma once
#ifndef SAVINGLOADING_H_INCLUDED
#define SAVINGLOADING_H_INCLUDED
#include"program.h"
#include<fstream>
#include"interface.h"
#include"BSTree.h"
#include<queue>
class SavingLoading
{
private : 

	std::string RemoveSpaces(string g);

	std::string ReturnSpaces(string g);


public :
	void write_user(interface p);

	void write_seller(interface p);

	void read_user(interface& p);

	void read_seller(interface& p);

	void write_product( BSTree);

	void read_product(BSTree& b, Category& c,interface&a);



};
#endif // DS_H_INCLUDED
