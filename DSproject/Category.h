#ifndef CATEGORY_H_INCLUDED
#define CATEGORY_H_INCLUDED
#pragma once
#include "product.h"
#include <vector>
#include <map>
class Category
{
public:
    map <string, vector<product*>> categories;
    void addtocat(product*);
    void displaycat(string);



};
#endif