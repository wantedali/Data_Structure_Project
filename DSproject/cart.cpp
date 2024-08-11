#include "cart.h"
using namespace std;
cart::cart()
{

}

void cart::addprod(product* p) {
    int quantity;
    while (true) {
        cout << "how much you want: ";
        cin >> quantity;
        int co;
        if (quantity == 0) {
            cout << "unavailable quantity" << endl;
            break;
        }
        else if (p->Quantity < quantity) {
            cout << "not enough quantity if you want to add true quantity press 1 if you want to quit press 0 : " << endl;
            cin >> co;
            if (co == 0) {
                break;
            }

            cout << " please enter enough quantity " << endl;
        }
        else {
            if (productss.count(p->Name)) {
                if (productss[p->Name].second->Quantity - productss[p->Name].first >= quantity) {
                    productss[p->Name] = { quantity + productss[p->Name].first ,p };
                    cout << "added successfully" << endl;
                    price += (p->Price) * (quantity);
                    break;
                }
                else {
                    cout << "unavailable quantity" << endl;
                    cout << "you have only " << productss[p->Name].second->Quantity - productss[p->Name].first << " from this product " << endl;
                    cout << "if want to add more from this product press 1 if want to quit press 0 : " << endl;
                    cin >> co;
                    if (co == 0) {
                        break;
                    }
                    cout << " please enter enough quantity " << endl;

                }
            }
            else {
                productss[p->Name] = { quantity,p };
                cout << "added successfully" << endl;
                price += (p->Price) * (quantity);
                break;
            }



        }
    }
}

void cart::checkout(BSTree& b ) {
    map<string, pair<int, product*> > ::iterator it;

    for (auto it = productss.begin(); it != productss.end();) {
        int f = it->second.first;
        product* s = it->second.second;
        if (f > s->Quantity) {
            int choice;
            cout << s->Name << "  this quantity is not available \n the available quantity is  " << s->Quantity << endl;
            cout << "if you want add available quantity press 1 and 0 if you don't want ";
            cin >> choice;
            if (choice == 1) {
                addprod(s);
            }
            productss.erase(it++);
        }
        else {
            cout << "the quantity of the product " << f << "\n product information \n product name : " << s->Name << "\n price : " << s->Price << endl;
            ++it;
        }
    }
    cout << "total cost is : " << price << " \n if you want to confirm the transaction press 1 else press 0 ";
    int c;
    cin >> c;
    if (c == 1) {
        price = 0;
        for (auto it = productss.begin(); it != productss.end(); ) {
            int f = it->second.first;
            product* s = it->second.second;
            if (s->Quantity == f) {
                b.setCapacity(b.getCapacity() - 1);
            }
            s->Quantity -= f;
            productss.erase(it++);
        }
        cout << "done " << endl;
    }

}
void cart::getproducts() {
    map<string, pair<int, product*> > ::iterator it;
    for (it = productss.begin(); it != productss.end(); it++) {
        product* s = it->second.second;
        cout << "product name : " << s->Name << endl;
    }
}

vector<pair<int, product*>> cart::getcartt() {

    vector<pair<int, product*>> v;
    map<string, pair<int, product*> > ::iterator it;
    for (it = productss.begin(); it != productss.end(); it++) {
     
        v.push_back({ it->second.first ,it->second.second });
    }

    return v;

};

float cart::getprice() {
    return price;
}

void cart::setprice(float p) {
    price = p;
}

void cart::setmap(int x, product* p) {

    productss[p->Name] = { x , p };


}

int cart::getsize() {
    return productss.size();
}