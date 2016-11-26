
#include "biparental_heap.cpp"

using namespace std;

int main() {
	BiparentalHeap heap;
	heap.insert(1);
	heap.printHeap();

	cout << endl << "-----------" <<endl;
	heap.insert(5);
	heap.printHeap();

	cout << endl << "-----------" << endl;
	heap.insert(0);
	heap.insert(1);
	heap.insert(80);
	heap.insert(2);
	heap.insert(3);
	heap.insert(18);
	heap.insert(1);
	heap.insert(51);
	heap.insert(400);
	heap.insert(1);
	heap.insert(12);
	heap.printHeap();

	cout << endl << "-----------" << endl;
	
	heap.deleteMax();
	heap.deleteMax();
	heap.deleteMax();
	heap.printHeap();

	cout << endl << "-----------" << endl;

	if (heap.search(2)) {
		cout << "Found 2 in the heap !" << endl;
	} else {
		cout << "Couldnt find 2 in the heap !" << endl;
	}

	if (heap.search(400)) {
		cout << "Found 400 in the heap !" << endl;
	} else {
		cout << "Couldnt find 400 in the heap !" << endl;
	}


	system("pause");
}