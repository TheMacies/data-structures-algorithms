#include <iostream>
using namespace std;

const int OCCUPIED = 2;
const int DELETED = 1;
const int FREE = 0;


class node {
public:
	int val;
	int state;
};

class HashTable {
private:
	int a, b, m, p;
	node *table;


	int hash(int v) {
		return ((a*v + b) % p) % m;
	}
public:
	HashTable(int a, int b, int m, int p) {
		this->a = a;
		this->b = b;
		this->p = p;
		this->m = m;

		this->table = new(node[m]);
		for (int i = 0;i < m;i++) {
			table[i] = node();
			table[i].state = FREE;
		}
	}


	bool Search(int v) {
		int hashed = hash(v);
		for (int i = hashed;;i = (i + 1) % m) {
			if (table[i].state == FREE) {
				return false;
			}
			if (table[i].state == OCCUPIED && table[i].val == v) {
				return true;
			}
		}
	}

	void Insert(int v) {
		int hashed = hash(v);
		int delIndex = -1;
		for (int i = hashed;;i = (i + 1) % m) {
			switch (table[i].state) {
			case OCCUPIED:   
				if (table[i].val == v) {
					return;
				}
				continue;
			case FREE: 
				if (delIndex != -1) {
					table[delIndex].state = OCCUPIED;  table[delIndex].val = v;
				return;
				} else {
					table[i].state = OCCUPIED;
					table[i].val = v;
					return;
				}
			case DELETED: 
				if (delIndex == -1) 
					delIndex = i;
			}
		}
	}

	void Delete(int v) {
		int hashed = hash(v);
		for (int i = hashed;;i = (i + 1) % m) {
			switch (table[i].state) {
			case OCCUPIED:
				if (table[i].val == v) {
					table[i].state = DELETED;
					return;
				}
				continue;
			case FREE: return;
			default: continue;
			}
		}
	}

};