#include <iostream>

using namespace std;

int const MAX = 10000;

struct elem {
	int key;
	int next;
};

class ListInArray {
	int first;
	elem* A[MAX];

public:
	ListInArray() {
		for (int i = 0;i < MAX;i++) {
			A[i] = nullptr;
		}
		first = -1;
	}


	void Insert(int val) {
		elem* n = new elem;
		n->next = -1;
		n->key = val;

		for (int i = 0;i < MAX;i++) {
			if (A[i] == nullptr) {
				A[i] = n;
				n->next = first;
				first = i;
				return;
			}
		}
	}

	void Sort() {
		if (first == -1) {
			return;
		}

		int newFirst = -1;

		while (first != -1) {
			int maxVal = A[first]->key;
			int maxNodePrevIndex = -1;
			int current = first;
			
			while (A[current]->next != -1) {
				int next = A[current]->next;
				if(A[next]->key > maxVal) {
					maxVal = A[next]->key;
					maxNodePrevIndex = current;
				}
				current = A[current]->next;
			}

			if (maxNodePrevIndex == -1) {
				int temp = newFirst;
				newFirst = first;
				first = A[first]->next;
				A[newFirst]->next = temp;
			}
			else {
				int temp = newFirst;
				newFirst = A[maxNodePrevIndex]->next;
				A[maxNodePrevIndex]->next = A[newFirst]->next;
				A[newFirst]->next = temp;
			}
		}

		first = newFirst;
	}

	void Print() {
		int next = first;
		while (next != -1) {
			elem* n = A[next];
			cout << " " << n->key << " ";
			next = n->next;
		}
		cout << endl;
	}


};