const int size = 1000;

struct node {
	int set;
	int val;
	node* up;
};

class Tree {
private :
	node** nodes;
	node** sets;

public :

	Tree() {
		nodes = new node*[size];
		sets = new node*[size];
		for (int i = 0;i < size;i++) {
			nodes[i] = nullptr;
			sets[i] = nullptr;
		}
	}

	int Find(int val) {
		node* n = nodes[val];
		if (!n) {
			return -1;
		}
		node* root = n;
		while (root->up) root = root->up;
		while (n->up) {
			node* temp = n;
			n = n->up;
			temp->up = root;
		}
		return root->set;
	}

	void Union(int s1, int s2, int s3) {
		node* root1 = sets[s1];
		node* root2 = sets[s2];
		root1->up = root2;
		sets[root1->set] = nullptr;
		sets[root2->set] = nullptr;
		sets[s3] = root2;
		root2->set = s3;
	}

	void Insert(int val,int set) {
		node* n = new node;
		n->val = val;
		n->up = nullptr;
		nodes[val] = n;
		if (sets[set] == nullptr) {
			n->set = set;
			sets[set] = n;
		}
		else {
			n->up = sets[set];
		}
	}
};