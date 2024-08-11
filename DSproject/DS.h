#pragma once
#ifndef DS_H_INCLUDED
#define DS_H_INCLUDED
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <vector>
#include"BSTree.h"
#include"cart.h"
#include "Category.h"
using namespace std;


class Seller {
private:
    int ID;
    std::string Name;
    std::string Email;
    std::string Pass;

    vector<product*>products;
    void modprod(product* p);
    //tb3
    void modname(product*);
    void modprice(product*);
    void modQuant(product*);
    void modcatog(product*, Category c);


public:


    Seller(int id, std::string pass, std::string name, std::string email);
    
    Seller();

    void addproduct(BSTree& b, string email, Category& c , int id);
    void insertProduct(product* p, BSTree& b, Category& c);
    void setName(std::string name);

    void setEmail(std::string email);

    void setID(int id);

    void setPass(std::string pass);

    int getID();

    void modprod(product);

    void getproducts();

    std::string getName();

    std::string getEmail();

    std::string getPass();

};

class Customer {
private:
    int ID;
    std::string Pass;
    std::string Name;
    std::string Email;
    std::string Address;
    std::string PhoneNumber;

public:

    void Browsecat(string, Category);

    Customer();

    Customer(int id, std::string pass, std::string name, std::string email, std::string adress, std::string phone);

    cart* cartt = new cart;

    void setID(int id);

    void setName(std::string name);

    void setEmail(std::string email);

    void setAddress(std::string address);

    void setPhoneNumber(std::string phone);

    void setPass(std::string pass);

    int getID();

    std::string getName();

    std::string getEmail();

    std::string getAddress();

    std::string getPhoneNumber();

    std::string getPass();

};
#endif // DS_H_INCLUDED