#include "BSTree.h"
#include<queue>

BSTree::BSTree() {
	capacity = 0;
	root = NULL;
	displayed = false;

}

string BSTree::small(string name) {
	for (int i = 0; i < name.size(); i++) {
		if (name[i] == ' ') {
			name.erase(name.begin() + i);
			i--;
		}
		if (name[i] <= 90) {
			name[i] += 32;
		}
	}

	return name;
}

long long BSTree::computeVal(string name) {
	string Small = small(name);
	long long tmp = 0;
	int power = 11;
	for (int i = 0; i < name.size(); i++) {
		if (name[i] == ' ') {
			i--;
			continue;
		}
		tmp += pow(26, power--) * (name[i] - 97);
		if (i == 12) {
			break;
		}
	}
	return tmp;
}

int BSTree::checkSimilarity(string name1, string name2) {

	for (int i = 0; i < name1.size() || i < name2.size(); i++) {
		if (i >= name2.size()) {

			return i - 1;


		}
		if (i >= name1.size()) {

			return -(i - 1);

		}
		if (name1[i] != name2[i]) {
			return i;

		}
	}
	return name1.size() - 1;
}

int BSTree::checkSimilarity2(string name1, string name2) {
	for (int i = 0; i < name1.size(); i++) {
		if (i >= name2.size()) {

			return -(i - 1);

		}

		if (name1[i] != name2[i]) {

			return -i;

		}
	}
	return name1.size() - 1;
}

void BSTree::insert(product p) {
	Node* tmp = new Node(p);
	int sim1, sim2;
	string name1, name2;
	if (capacity == 0) {

		root = tmp;

	}
	else {
		Node* tmp2 = root;
		name1 = small(tmp->p.Name);

		sim1 = checkSimilarity(name1, small(root->p.Name));
		while (true) {

			name2 = small(tmp2->p.Name);

			if (name1 == name2) {
				//7otto fel bottom
				if (tmp2->bottom == NULL) {
					tmp2->bottom = tmp;
				}
				else {
					tmp->bottom = tmp2->bottom;
					tmp2->bottom = tmp;
				}
				break;
			}

			if (sim1 < 0 || name1[sim1] < name2[sim1]) {
				if (tmp2->left == NULL) {
					tmp2->left = tmp;
					break;
				}
				else {

					sim2 = checkSimilarity(name1, small(tmp2->left->p.Name));

					if (sim2 < 0 || name1[sim2] < tmp2->left->p.Name[sim2]) {
						sim1 = sim2;
						tmp2 = tmp2->left;
						continue;
					}
					else {
						if (sim2 >= abs(sim1)) {
							sim1 = sim2;
							tmp2 = tmp2->left;
							continue;
						}
						else {
							tmp->left = tmp2->left;
							tmp2->left = tmp;
							break;
						}
					}
				}
			}
			else {
				if (tmp2->right == NULL) {
					tmp2->right = tmp;
					break;
				}
				else {
					sim2 = checkSimilarity(name1, small(tmp2->right->p.Name));

					if (sim2 >= 0 && name1[sim2] > tmp2->right->p.Name[sim2]) {
						tmp2 = tmp2->right;
						sim1 = sim2;
						continue;
					}
					else {
						if (sim1 <= abs(sim2)) {
							tmp2 = tmp2->right;
							sim1 = sim2;
							continue;
						}
						else {

							tmp->right = tmp2->right;
							tmp2->right = tmp;
							break;
						}

					}
				}
			}
		}
	}
	capacity++;
}

void BSTree::display() {
	if (v.size() > 0) {
		for (int i = 0; i < v.size(); i++) {

			cout << v[i].Name << " ";

		}
		cout << '\n';
		v.clear();
	}
	/*queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* n = q.front();

		q.pop();
		if (n->right != NULL) {
			q.push(n->right);
			cout << n->p.Name << " : " << n->right->p.Name << " right\n";
		}
		if (n->left != NULL) {
			q.push(n->left);
			cout << n->p.Name << " : " << n->left->p.Name << " left \n";
		}
	}*/
}

product* BSTree::search(string name) {

	if (capacity == 0) {
		return NULL;

	 }
	int sim1, sim2;
	string name1;

	Node* tmp2 = root;
	name = small(name);

	sim1 = checkSimilarity(name, small(root->p.Name));
	while (true) {

		name1 = small(tmp2->p.Name);

		if (name == name1) {
			//7otto fel bottom
			return &(tmp2->p);
		}

		if (sim1 < 0 || name[sim1] < name1[sim1]) {
			if (tmp2->left == NULL) {
				return NULL;
			}
			else {

				sim2 = checkSimilarity(name, small(tmp2->left->p.Name));
				if (name == small(tmp2->left->p.Name)) {
					//7otto fel bottom
					return &(tmp2->left->p);
				}
				if (sim2 < 0 || name[sim2] < tmp2->left->p.Name[sim2]) {
					sim1 = sim2;
					tmp2 = tmp2->left;
					continue;
				}
				else {
					if (sim2 >= abs(sim1)) {
						sim1 = sim2;
						tmp2 = tmp2->left;
						continue;
					}

				}
			}
		}
		else {
			if (tmp2->right == NULL) {
				return NULL;
			}
			else {
				sim2 = checkSimilarity(name, small(tmp2->right->p.Name));
				if (name == small(tmp2->right->p.Name)) {
					return &(tmp2->right->p);
				}
				if (sim2 >= 0 && name[sim2] > tmp2->right->p.Name[sim2]) {
					tmp2 = tmp2->right;
					sim1 = sim2;
					continue;
				}
				else {
					if (sim1 <= abs(sim2)) {
						tmp2 = tmp2->right;
						sim1 = sim2;
						continue;
					}


				}
			}
		}
	}

}

void BSTree::suggested(string name) {
	string name1;
	int sim1;
	name = small(name);
	Node* tmp = root;

	while (true) {
		name1 = small(tmp->p.Name);
		sim1 = checkSimilarity2(name, name1);
		if (sim1 > 0 || (sim1 == 0 && name[sim1] == name1[sim1])) {
			v.push_back(tmp->p);
			queue<Node>q;
			q.push(*tmp);
			while (v.size() <= 5 && !q.empty()) {
				if (q.front().left != NULL) {
					if (checkSimilarity2(name, q.front().left->p.Name) == sim1 && name[0] == q.front().left->p.Name[0]) {
						q.push(*(q.front().left));
						v.push_back(q.front().left->p);
					}
				}
				if (q.front().right != NULL) {
					if (checkSimilarity2(name, q.front().right->p.Name) == sim1 && name[0] == q.front().right->p.Name[0]) {
						//cout << q.front().right->p.Name << " eaf " << checkSimilarity2(name, q.front().right->p.Name) << " ";
						q.push(*(q.front().right));
						v.push_back(q.front().right->p);
					}
				}
				q.pop();
			}

			return;
		}
		else {
			if (name[-sim1] < name1[-sim1]) {
				if (tmp->left == NULL) {

					return;

				}
				//cout << " " << name1[-sim1];
				tmp = tmp->left;

			}

			else {
				if (tmp->right == NULL) {

					return;

				}

				tmp = tmp->right;

			}
		}
	}
}

Node* BSTree::getroot() {


	return root;


}

long long BSTree::getCapacity() {
	return capacity;
}


void BSTree::setCapacity(long long x) {

	capacity = x;


}

