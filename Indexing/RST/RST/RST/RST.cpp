#include <iostream>

using namespace std;

struct node {
	int val;
	node* left;
	node* right;
};

class RST {
	node* root;
private :

	int bit(int val, int b) {
		return (val >> b) & 1;
	}


public:
	RST() {
		root = nullptr;
	}

	bool Search(int val) {
		if (!root) {
			return false;
		}
		node* head = root;
		int i = 0;
		while (head) {
			if (head->val == val) {
				return true;
			}
			bit(val, i) == 1 ? head = head->right : head = head->left;
			i++;
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

		node* head = root;
		int i = 0;
		while (head->val != val) {
			if (bit(val, i) == 1) {
				if (head->right == nullptr) {
					head->right = n;
					return;
				}
				head = head->right;
			}
			else {
				if (head->left == nullptr) {
					head->left = n;
					return;
				}
				head = head->left;
			}
			i++;
		}
	}

	node* extractLeaf(node* r) {
		node* leafParent = r;
		if (!root->left && !root->right) {
			return nullptr;
		}

		while (true) {
			node* check = leafParent;
			if (leafParent->left) {
				while (leafParent->left->left) {
					leafParent = leafParent->left;
				}
				while (leafParent->left->right) {
					leafParent = leafParent->left;
				}
			}
			 if (leafParent->right) {
				 while (leafParent->right->right) {
					 leafParent = leafParent->right;
				 }
				 while (leafParent->right->left) {
					 leafParent = leafParent->right;
				 }
			 }
			 if (check == leafParent) {
				 break;
			 }
		}

		node* leaf;
		if (leafParent->left) {
			leaf = leafParent->left;
			leafParent->left = nullptr;
		}
		else {
			leaf = leafParent->right;
			leafParent->right = nullptr;
		}

		return leaf;
	}

	void Delete(int val) {
		if (!root) {
			return;
		}

		node* leaf;
		if (root->val == val) {
			leaf = extractLeaf(root);
			if (leaf == nullptr) {
				root = nullptr;
				return;
			}
			leaf->right = root->right;
			leaf->left = root->left;
			root = leaf;
			return;
		}
		
		
		node* head = root;
		
		for(int i = 0;head;i++){
			if (bit(val, i) == 1) {
				if (head->right == nullptr) {
					break;
				}
				if (head->right->val == val) {
					leaf = extractLeaf(head->right);
					leaf->right = head->right->right;
					leaf->left = head->right->left;
					head->right = leaf;
					return;
				} 
				head = head->right;
			}
			else {
				if (head->left == nullptr) {
					break;
				}
				if (head->left->val == val) {
					leaf = extractLeaf(head->left);
					leaf->right = head->left->right;
					leaf->left = head->left->left;
					head->left = leaf;
					return;
				}
				head = head->left;
			}
		}
	}
};
