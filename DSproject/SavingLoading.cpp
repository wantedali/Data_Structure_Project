#include "SavingLoading.h"

using namespace std;

string SavingLoading::RemoveSpaces(string g) {
    string s;
    for (int i = 0; i < g.size(); i++) {
        if (g[i] == ' ') {
            s.push_back('+');
        }
        else
        {
            s.push_back(g[i]);
        }
    }
    return s;

}

string SavingLoading::ReturnSpaces(string g) {
    string s;
    for (int i = 0; i < g.size(); i++) {
        if (g[i] == '+') {
            s.push_back(' ');
        }
        else
        {
            s.push_back(g[i]);
        }
    }
    return s;



}

void SavingLoading::write_user(interface p) {
    fstream out("User_data.txt", ios::out);
    if (!out) {
        cout << "file not found"<<endl;
        return;
    }
    unordered_map<string, Customer*> ::iterator it;
    out << p.Cust_count << " ";
    for (it = p.customers.begin(); it != p.customers.end(); it++) {

        out << it->second->getEmail() << " ";
        out << it->second->getID() << " ";
        out << RemoveSpaces(it->second->getName()) << " ";
        out << it->second->getPass() << " ";
        out << RemoveSpaces(it->second->getAddress()) << " ";
        out << it->second->getPhoneNumber() << " " << endl;
        vector<pair<int, product*>> v;
        v = it->second->cartt->getcartt();

        out << it->second->cartt->getsize() << " ";
        out << it->second->cartt->getprice() << " ";
        for (int i = 0; i < v.size(); i++) {
        
            out << v[i].first << " ";
            out << v[i].second->ID << " ";
            out << RemoveSpaces(v[i].second->Name) << " ";
            out << v[i].second->Price << " ";
            out << RemoveSpaces(v[i].second->Category) << " ";
            out << v[i].second->Quantity << " ";
            out << v[i].second->Rate << " ";
            out << v[i].second->SellerID << " ";
            out << v[i].second->seller_email << " " << endl;
        }

    }
    out.close();

};

void SavingLoading::read_user(interface& p) {
    fstream in("User_data.txt", ios::in);
    if (!in) {
        cout << "file not found"<<endl;
        return;
    }
    in >> p.Cust_count;
    int x;
    string y;
    float z;
    for (int i = 1; i <= p.Cust_count; i++) {
        Customer *C = new Customer;
        in >> y;
        C->setEmail(y);
        in >> x;
        C->setID(x);
        in >> y;
        C->setName(ReturnSpaces(y));
        in >> y;
        C->setPass(y);
        in >> y;
        C->setAddress(ReturnSpaces(y));
        in >> y;
        C->setPhoneNumber(y);
        p.addcustomer(C);
        in >> x;
        in >> z;
        C->cartt->setprice(z);
        int pc = x;
        for (int i = 0; i < pc; i++) {
            product* p = new product;
            in >> x;
            int c = x ;
            in >> x;
            p->ID = x;
            in >> y;
            p->Name = y;
            in >> z;
            p->Price = z;
            in >> y;
            p->Category = z;
            in >> x;
            p->Quantity = x;
            in >> z;
            p->Rate = z;
            in >> x;
            p->SellerID = x;
            in >> y;
            p->seller_email = y;
       
            C->cartt->setmap(c, p);
        }



    }
};


void SavingLoading::write_seller(interface p) {
    fstream out("Seller_data.txt", ios::out);
    if (!out) {
        cout << "file not found"<<endl;
        return;
    }
    unordered_map<string, Seller*> :: iterator it;
    out << p.Seller_count<<" ";
    for (it = p.sellers.begin(); it != p.sellers.end(); it++) {
        out << it->second->getEmail() << " ";
        out << it->second->getID() << " ";
        out << RemoveSpaces(it->second->getName()) << " ";
        out << it->second->getPass() << " " << endl;
    }
    out.close();

}


void SavingLoading::read_seller(interface& p) {
    fstream in("Seller_data.txt", ios::in);
    if (!in) {
        cout << "file not found"<<endl;
        return;
    }
    in >> p.Seller_count;
    int x;
    string y;
    for (int i = 1; i <= p.Seller_count; i++) {
        Seller* S = new Seller;
        in >> y;
        S->setEmail(y);
        in >> x;
        S->setID(x);
        in >> y;
        S->setName(ReturnSpaces(y));
        in >> y;
        S->setPass(y);
        p.addseller(S);
    }

};


void SavingLoading::write_product(BSTree b) {
    fstream out("product_data.txt", ios::out);
    if (!out) {
        cout << "file not found"<<endl;
        return;
    };
    out << b.getCapacity() << " ";
    cout << endl;
    Node* temp= b.getroot();
    queue<Node*> q;
    q.push(temp);
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->bottom != NULL) {
            q.push(temp->bottom);
        }
        if (temp->left != NULL) {
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }
        if (temp->p.Quantity > 0) {
            out << temp->p.ID << " ";
            out << RemoveSpaces(temp->p.Name) << " ";
            out << temp->p.Price << " ";
            out << RemoveSpaces(temp->p.Category) << " ";
            out << temp->p.Quantity << " ";
            out << temp->p.SellerID << " ";
            out << temp->p.Rate << " ";
            out << temp->p.seller_email << " ";
            cout << endl;
        }
    }
}



void SavingLoading::read_product(BSTree&  b , Category& c,interface&a ) {
    fstream in("product_data.txt", ios::in);
    if (!in) {
       cout << "file not found"<<endl;
      return;
    }
    long long g;
    in >> g; 
    int x;
    string y;
    float z;
    for (int i = 0; i < g; i++) {
       product* p = new product;
       in >> x;
       p->ID = x;
       in >> y;
       p->Name = ReturnSpaces(y);
       in >> z;
       p->Price = z;
       in >> y;
       p->Category = ReturnSpaces(y);
       in >> x;
       p->Quantity = x;
       in >> x;
       p->SellerID = x;
       in >> z;
       p->Rate = z;
       in >> y;
       p->seller_email = ReturnSpaces(y);
       (a.getSeller(p->seller_email))->insertProduct(p, b, c);
    }

    };
