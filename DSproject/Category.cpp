#include "Category.h"
using namespace std;
void Category::addtocat(product* p) {

    categories[p->Category].push_back(p);


}
void Category::displaycat(string cat) {

    if (categories[cat].empty()) {
        cout << "categorise is Empty ";
        return;
    }

    for (int i = 0; i < categories[cat].size(); i++) {
        cout << categories[cat][i] << " ";
    }

}
