#ifndef CART_H
#define CART_H

#include"BSTree.h"
#include"product.h"
#include <vector>
#include<map>
using namespace std;

class cart
{
private:
    float price = 0;
    map<string, pair<int, product*> >productss;
public:
    cart();
    void addprod(product*);
    void checkout(BSTree & b);
    void getproducts();
    vector <pair<int, product*>> getcartt();
    float getprice();
    void setprice(float p);
    void setmap(int x, product* p);
    int getsize();
};

#endif // CART_H
