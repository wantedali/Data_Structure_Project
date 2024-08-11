#include "DS.h"

//tp3y
void Seller::modprod(product* p) {
	//Gui input 

}
void Seller::modname(product* p)
{
	cin >> p->Name;
}

void Seller::modprice(product* p)
{
	cin >> p->Price;
}

void Seller::modQuant(product* p)
{
	cin >> p->Quantity;
}

void Seller::modcatog(product* p, Category c)
{
	for (int i = 0; i < c.categories[p->Category].size(); i++) {
		if (c.categories[p->Category][i] == p) {
			c.categories[p->Category].erase(c.categories[p->Category].begin() + i);
		}
	}
	cin >> p->Category;
	c.addtocat(p);
}
void Seller::insertProduct(product* p, BSTree& b, Category& c) {
	b.insert(*p);
	c.addtocat(p);
	products.push_back(p);
}
//tp3y

Seller::Seller(int id, std::string pass, std::string name, std::string email) {
	ID = id;
	Name = name;
	Email = email;
	Pass = pass;
}

Seller::Seller() {
	ID = 0;
	Name = "";
	Email = "";
	Pass = "";
}

void Seller::setName(std::string name)
{
	Name = name;
}

void Seller::setEmail(std::string email) {
	Email = email;
}

void Seller::setID(int id) {
	ID = id;
}
void Seller::setPass(std::string pass) {
	Pass = pass;
}

int Seller::getID() {
	return ID;
}

std::string Seller::getName() {
	return Name;
}

std::string Seller::getEmail() {
	return Email;
}

std::string Seller::getPass() {
	return Pass;
}


void Seller::addproduct(BSTree& b, string em, Category& c , int id) {
	
	product* p = new product;
	cout << "enter the product ID : "; cin >> p->ID;
	cin.ignore(265, '\n');
	cout << "enter the product Name :  "; getline(cin, p->Name);//cin >> p->Name;
	cout << "enter the product Price : "; cin >> p->Price;
	cin.ignore();
	cout << "enter the product Category : "; getline(cin, p->Category);//cin >> p->Category;
	cout << "enter the product Quantity : "; cin >> p->Quantity;
	//cout << "enter the pic path : "; getline(cin, p->pic);
	cout << "Product added successfully " << endl;
	p->seller_email = em;
	p->SellerID = id;
	products.push_back(p);
	b.insert(*p);
	c.addtocat(p); //tp3y

}
void Seller::getproducts() {
	for (int i = 0; i < products.size(); i++) {
		cout << products[i]->Name << " ";
	}
	cout << endl;
}


Customer::Customer() {
	ID = 0;
	Name = "";
	Pass = "";
	Email = "";
	Address = "";
	PhoneNumber = "";

}
Customer::Customer(int id, std::string pass, std::string name, std::string email, std::string adress, std::string phone) {
	ID = id;
	Name = name;
	Email = email;
	Address = adress;
	PhoneNumber = phone;
	Pass = pass;
}
void Customer::Browsecat(string w, Category c) {
	c.displaycat(w);


}


void Customer::setID(int id) {
	ID = id;
}

void Customer::setName(std::string name) {
	Name = name;
}

void Customer::setEmail(std::string email) {
	Email = email;
}

void Customer::setAddress(std::string address) {
	Address = address;
}

void Customer::setPhoneNumber(std::string phone) {
	PhoneNumber = phone;
}

void Customer::setPass(std::string pass) {
	Pass = pass;
}

int Customer::getID() {
	return ID;
}

std::string Customer::getName() {
	return Name;
}

std::string Customer::getEmail() {
	return Email;
}

std::string Customer::getAddress() {
	return Address;
}

std::string Customer::getPhoneNumber() {
	return PhoneNumber;
}

std::string Customer::getPass() {
	return Pass;
}