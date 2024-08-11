#include<iostream>
#include"interface.h"
//#include"program.h"
#include<unordered_map>
#include<fstream>
#include "BSTree.h"
#include"DS.h"
#include "cart.h"
#include "category.h"
#include "SavingLoading.h"
using namespace std;
int main() {
    BSTree b;
    SavingLoading S;
    Category c;
    interface i(1, 1); 
    S.read_seller(i);
    S.read_user(i);
    S.read_product(b,c, i);
    program x;
    int choice, enter = 0;
    do {
        cout << "if you want register as seller press 1 " << endl;
        cout << "if you want register as customer press 2 " << endl;
        cout << "if you want to login as seller press 3 " << endl;
        cout << "if you want to login as customer press 4 " << endl;

        cin >> choice;
        switch (choice) {
        case 1:
        {
            i.Register(1);
            break;
        }
        case 2:
        {
            i.Register(0);
            break;
        }
        case 3:
        {
         
            Seller* s = i.loginseller();
            int cnt;
            Category c;
            do {
                cout << "if you want to add product press 1 and if you want to show your prod press 2 ";
                int ch;
                cin >> ch;
                if (ch == 1) {
                    (s)->addproduct(b, s->getEmail(), c , s->getID());
                    S.write_product(b);
                }
                else if (ch == 2) {
                    s->getproducts();
                }
                cout << "if you want to continue press 1 else press 0 ";
                cin >> cnt;
            } while (cnt == 1);
            break;
        }
        case 4:
        {
     
            Customer* c = i.logincustomer();
            int ci, re , zed ;
            do {
                cout << "if you want to search press 1 or if you want to check cart press 2";
                cin >> re;
                if (re == 1) {
                    cout << "enter your product name: ";
                    string na;
                    cin >> na;
                    product* o = b.search(na);
                    if (o == NULL) {
                        cout << "product not found ";
                    }
                    else {
                    cout << o->Quantity << endl;
                    c->cartt->addprod(o);


                    }  

                }
                else {
                   c->cartt->getproducts();
                }
                cout << "if you want to continue add prod press 1 else press 0 ";
                cin >> ci;
            } while (ci == 1);
            cout << "if you want to check out press 1 else press 0 ";
            int q;
            cin >> q;
            if (q == 1) {
                c->cartt->checkout(b);
            }

            break;
        }

        }

        cout << "if you want do another op press 1 else press 0 ";
        cin >> enter;
        if (enter == 0) {
            cout << "Thanks for using our online market :D ";
            break;
        }
    } while (true);


    S.write_user(i);
    S.write_seller(i);
  
    return 0;
}

