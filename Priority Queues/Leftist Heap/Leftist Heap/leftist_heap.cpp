#include <iostream>

using namespace std;

class HeapNode {
public:
	HeapNode* left;
	HeapNode* right;
	int npl;
	int value;

	HeapNode() {
	}

	HeapNode(int val, int nl = 0) {
		value = val;
		npl = nl;
		left = nullptr;
		right = nullptr;
	}

	HeapNode* insert(int v) {
		HeapNode* node = new HeapNode(v, 0);
		return Union(this, node);
	}

	HeapNode* getMax(int& out) {
		out = value;
		return Union(right, left);
	}

	HeapNode* Union(HeapNode* h1, HeapNode* h2) {
		HeapNode* root = h1;
		if (!h1) {
			return h2;
		} 
		if (!h2) {
			return h1;
		}

		if (h1->value < h2->value) {
			root = h2;
			root->right = Union(root->right, h1);
		}
		else {
			root->right = Union(root->right, h2);
		}

		if (!root->left || root->left->npl < root->right->npl) {
			HeapNode* temp = root->right;
			root->right = root->left;
			root->left = temp;
		}

		if (root->right) {
			root->npl = root->right->npl + 1;
		}
		else {
			root->npl = 0;
		}
		return root;
	}

	void PreOrderPrint() {
		cout << value << "  ";
		if (left) {
			left->PreOrderPrint();
		}

		if (right) {
			right->PreOrderPrint();
		}
	}
};

