#include <iostream>

#include "Hashing.cpp"

using namespace std;

void printRes(bool val) {
	if (val) {
		cout << "Exists";
	}
	else {
		cout << " Not exists";
	}
	cout << endl;
}



int main() {
	int m = 100;
	int p = 103;
	int a = 1;
	int b = 0;
	HashTable h = HashTable(a, b, m, p);
	h.Insert(10);

	printRes(h.Search(10));
	printRes(h.Search(2));
	h.Insert(2);

	printRes(h.Search(10));
	printRes(h.Search(2));

	for (int i = 0;i < 50;i++) {
		h.Insert(i);
	}
	h.Delete(10);

	printRes(h.Search(10));
	printRes(h.Search(20));

	getchar();
}