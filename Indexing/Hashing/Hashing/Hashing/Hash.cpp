#include <iostream>
using namespace std;

class node {
public :
	int val;
	node* next;
};

class HashTable {
private :
	int a, b, m, p;
	node **table;


	int hash(int v) {
		return ((a*v + b) % p) % m;
	}
public :
	HashTable(int a, int b, int m, int p) {
		this->a = a;
		this->b = b;
		this->p = p;
		this->m = m;

		this->table = new(node*[m]);
		for (int i = 0;i < m;i++) {
			table[i] = nullptr;
		}
	}


	bool Search(int v) {
		node* n = table[hash(v)];
		if (n == nullptr) {
			return false;
		}
		while (n) {
			if (n->val == v) {
				return true;
			}
			n = n->next;
	  }
	    if (n->val == v) {
			return true;
	     }
		return false;
	}

	void Insert(int v) {
		node* n = new node;
		n->val = v;
		n->next = nullptr;
		int hashed =  hash(v);

		if (!table[hashed]) {
			table[hashed] = n;
			return;
		}
		node* head = table[hashed];
		if (head->val == v) {
			return;
		}
		while (head->next) {
			head = head->next;
			if (head->val == v) {
				return;
			}
		}
		head->next = n;
	}

	void Delete(int v) {
		int hashed = hash(v);
		if (table[hashed] == nullptr) {
			return;
		}
		node* head = table[hashed];
		if (head->val == v) {
			if (head->next) {
				table[hashed] = head->next;
			}
			else {
				table[hashed] = nullptr;
			}
			return;
		}
		while (head->next && head->next->val != v) {
			head = head->next;
		}
		if (head->next == nullptr) {
			return;
		}
		node* temp = head->next->next;
		delete head->next;
		head->next = temp;
	}
		 
};