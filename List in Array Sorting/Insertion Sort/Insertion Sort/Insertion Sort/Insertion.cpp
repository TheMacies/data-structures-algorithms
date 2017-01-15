#include <iostream>

using namespace std;

int const MAX = 10000;

struct elem {
	int key;
	int next;
};

class ListInTable {
	int first;
	elem* A[MAX];

public:
	ListInTable() {
			for (int i = 0;i < MAX;i++) {
				A[i] = nullptr;
			}
			first = -1;
	}
		void Insert(int val) {
			elem* n = new elem;
			n->next = - 1;
			n->key = val;

			if (first == -1) {
				first = 0;
				A[0] = n;
				return;
			}

			for (int i = 0;i < MAX;i++) {
				if (A[i] == nullptr) {
					A[i] = n;
					n->next = first;
					first = i;
					return;
				}
			}
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

		void Sort() {
			if (first == -1) {
				return;
			}

			int firstSorted = first;
			first = A[first]->next;
			A[firstSorted]->next = -1;
			
			while (first != -1) {
				int elemToInsert = first;
				first = A[first]->next;

				int prev = -1;
				int current = firstSorted;

				while (current != -1 && A[current]->key >= A[elemToInsert]->key) {
					prev = current;
					current = A[current]->next;
				}

				if (prev == -1) {
					A[elemToInsert]->next = firstSorted;
					firstSorted = elemToInsert;
					continue;
				}

				int temp = A[prev]->next;
				A[prev]->next = elemToInsert;
				A[elemToInsert]->next = temp;
			}

			first = firstSorted;
		}

};