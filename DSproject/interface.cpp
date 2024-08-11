#include"interface.h"
#include<assert.h>
#include<regex>
using namespace std;

interface::interface(int cust_cnt = 1, int seller_cnt = 1) {
    id_cust = cust_cnt;
    id_seller = seller_cnt;

}

//cnt : 0 for register & 1 for login
//t : 0 for customer & 1 for seller



string interface::getNamee(string Email) {

    return customers[Email]->getName();
}
bool isEmailValid(const std::string& email) {
    // Regular expression pattern for email validation
    std::regex pattern("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");

    // Check if the email matches the pattern
    return std::regex_match(email, pattern);
}

void interface::takeInput(bool cnt, bool t) {

    if (cnt) {
        cout << "\t \t Enter Your Email & Your Pass" << endl;
        cout << "Enter Email : ";
        cin.ignore(256, '\n');
        getline(cin, email);

        cout << "Enter Pass : ";
        cin >> pass;

        return;
    }
    if (!t) {
        cout << "\t \t \t Enter Your details" << endl;

        cout << "Enter Name : ";
        cin.ignore(256, '\n');
        getline(cin, name);

        bool wrongemail = false;
        cout << "Enter Email : ";
        getline(cin, email);
        if (isEmailValid(email)) {
            wrongemail = true;
        }
        while (wrongemail == false) {
            if (isEmailValid(email)) {
                wrongemail = true;
                break;
            }
            else {
                cout << "Email is not valid." << endl;
                cout << "Enter valid email : ";
                getline(cin, email);
            }
        }

        while (true) {
            cout << "Enter Pass : ";
            getline(cin, pass);
            if (pass.size() < 8) {
                cout << "please enter at least 8 characters "<<endl;
            }
            else {
                break;
            }
        }
        cout << "Enter Address : ";
        // cin.ignore(256, '\n');
        getline(cin, address);
        cout << "Enter Phone Number : ";
        cin >> phoneNum;

    }
    else {
        cout << "\t \t \t Enter Your details" << endl;

        
            cout << "Enter Name : ";
            cin.ignore(256, '\n');
            getline(cin, name);
            bool wrongemail = false;
            cout << "Enter Email : ";
                getline(cin, email);
                if (isEmailValid(email)) {
                    wrongemail = true;   
                }
            while (wrongemail==false) {
                if (isEmailValid(email)) {
                    wrongemail = true;
                    break;
                }
                else {
                cout << "Email is not valid." << endl;
                cout << "Enter valid email : ";
                getline(cin, email);
                }
            }
            while (true) {
                cout << "Enter Pass : ";
                cin >> pass;
                if (pass.size() < 8) {
                    cout << "please enter at least 8 characters"<<endl;
                }
                else {
                    break;
                }
            }
    }
}

void interface::Register(bool t) {
    //if customer
    takeInput(0, t);

    if (!t) {

        newcust = new Customer(id_cust++, pass, name, email, address, phoneNum);
        customers[email] = newcust;

        Cust_count++;


    }
    //if seller
    else {
        newseller = new Seller(id_seller++, pass, name, email);
        sellers[email] = newseller;

        Seller_count++;
    }

}

Customer* interface::logincustomer() {
    //if customer

    takeInput(1, 0);
    if (customers.count(email) && customers[email]->getPass() == pass) {
        cout << "Logged In Successfully" << endl;
        true_email = true;
        return customers[email];
    }
    else {
        cout << "\t Wrong Email or Pass \n" << endl;
        logincustomer();
    }

}

Seller* interface::loginseller() {
    true_email = false;

    takeInput(1, 1);
    if (sellers.count(email) && sellers[email]->getPass() == pass) {
        cout << "Logged In Successfully" << endl;
        true_email = true;
        return sellers[email];
    }
    else {
        cout << "\t Wrong Email or Pass \n" << endl;
        loginseller();
    }

}

void interface::addcustomer(Customer* C) {

    
    customers[C->getEmail()] = C; 

};

void interface::addseller(Seller* S) {


    sellers[S->getEmail()] = S;



};
Seller* interface::getSeller(string email) {
    return sellers[email];
}