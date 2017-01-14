#include <iostream>

using namespace std;

struct node {
	int bit;
	short key;
	node* next[2];
};

const int maxBit = 7;

class PATRICIA {
private :
	node* root;
	int bit(short val, int b) {
		return (val >> b) & 1;
	}
	
public:
	PATRICIA() {
		root = new node;
		root->key = 0;
		root->bit = maxBit;
		root->next[0] = root;
		root->next[1] = root;
	}

	node* Search(short v) {
		node* current = root;
		node* prev = nullptr;
		do {
			prev = current;
			current = current->next[bit(v,current->bit)];
		} while (prev->bit > current->bit);
	  return current;
	}

	void Insert(short v) {
		node *q = Search(v);
		if (q->key == v) {
			return;
		}
		node* current = root;
		node* prev = nullptr;

		do {
			prev = current;
			current = current->next[bit(v,current->bit)];
		} while (prev->bit > current->bit );

		int b = prev->bit - 1;
		q = new node;
		q->bit = b;
		q->key = v;
		q->next[bit(v, b)] = q;
		q->next[1 - bit(v, b)] = current;
		prev->next[bit(v, prev->bit)] = q;
	}

	void Delete(short v) {
		throw new exception("Not implemented");
		node* current = root;
		node* prev = nullptr;

		do {
			prev = current;
			current = current->next[bit(v, current->bit)];
		} while (prev->bit > current->bit);
		
		if (current->key != v) {
			return;
		}


	}
};