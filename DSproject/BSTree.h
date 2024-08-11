#pragma once
#include"Node.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
class BSTree
{
private:
    Node* root;

    long long capacity;
    long long computeVal(string name);
    int checkSimilarity(string name1, string nam2);
    int checkSimilarity2(string name1, string nam2);

    string small(string name);
    bool displayed;
    vector<product> v;

public:
    BSTree();
    void display();
    void insert(product p);
    product* search(string name);
    void suggested(string name);
    Node* getroot();
    long long getCapacity();
    void setCapacity(long long p);


};
