#pragma once
#include<iostream>
#include"program.h"
#include<unordered_map>
using namespace std;

class interface : public program {

private:

    string name, email, pass, address;
    string phoneNum;
    int id_cust, id_seller;
    Seller* newseller;
    Customer* newcust;
    bool true_email = false;
    void takeInput(bool cnt, bool t);


public:

    long long Cust_count = 0, Seller_count = 0;

    interface(int, int);

    void Register(bool t);
    Customer* logincustomer();

    Seller* loginseller();
    Seller* getSeller(string);
    string getNamee(string Email);
 
   void addcustomer(Customer* C);

   void addseller(Seller* S);

};
