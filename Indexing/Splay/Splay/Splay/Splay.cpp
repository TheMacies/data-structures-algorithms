#include <iostream>

using namespace std;

struct node {
	int val;
	node* right;
	node* left;
};

class Splay {
private:
	node* root;
	void splay(node* &n,int v) {
		if (n->val == v) {
			return;
		}
		if (n->val > v) {
			if (n->left) {
				if (n->left->val > v) {
					if (n->left->left) {
						splay(n->left->left, v);
						LZigZig(n);
					}
					else {
						LZig(n);
					}
				}
				else {
					if (n->left->val  < v) {
						if (n->left->right) {
							splay(n->left->right,v);
							LZigZag(n);
						}
						else {
							LZig(n);
						}
					}
					else {
						LZig(n);
					}
				}
			}
		}
		else {
			if (n->right) {
				if (n->right->val < v) {
					if (n->right->right) {
						splay(n->right->right,v);
						RZigZig(n);
					}
					else {
						RZig(n);
					}
				}
				else {
					if (n->right->val > v) {
						if (n->right->left) {
							splay(n->right->left, v);
							RZigZag(n);
						}
						else {
							RZig(n);
						}
					}
					else {
						RZig(n);
					}
				}
			}
		}

	}

	void LZig(node *&n) {
		node* temp = n->left;
		n->left = n->left->right;
		temp->right = n;
		n = temp;
	}

	void LZigZig(node *&n) {
		LZig(n);
		LZig(n);
	}

	void LZigZag(node *&n) {
		RZig(n->left);
		LZig(n);
	}

	void RZig(node *&n) {
		node* temp = n->right;
		n->right = temp->left;
		temp->left = n;
		n = temp;
	}

	void RZigZig(node *&n) {
		RZig(n);
		RZig(n);
	}

	void RZigZag(node *&n) {
		LZig(n->right);
		RZig(n);
	}




public:
	Splay() {
		root = nullptr;
	}
	bool Search(int val) {
		if (!root) {
			return false;
		}
		splay(root,val);
		if (root->val == val) {
			return true;
		}
		return false;
	}

	void Insert(int val) {
		node* n = new(node);
		n->val = val;
		n->left = nullptr;
		n->right = nullptr;

		if (!root) {
			root = n;
			return;
		}
		splay(root,val);
		if (root->val == val) {
			return;
		}
		if (root->val > val) {
			n->right = root;
			n->left = root->left;
			root->left = nullptr;
		}
		else {
			n->left = root;
			n->right = root->right;
			root->right = nullptr;
		}
		root = n;
	}

	void Delete(int val) {
		if (!root) {
			return;
		}
		splay(root,val);
		if (root->val != val) {
			return;
		}
		if (!root -> left) {
			root = root->right;
			return;
		}
		node* p = root;
		splay(root->left, val);
		root->left->right = root->right;
		root = root->left;
	}

};