
#include "heap.cpp"

using namespace std;

int main() {
	Heap heap;
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
	heap.printHeap();


	cout << endl << "------------" << endl;
	int* tab;
	tab = new int[11]{ 1, 5, 0, 1, 80, 2, 3, 18, 1, 51, 400 };
	heap = Heap(tab,11);
	heap.printHeap();

	cout << endl << "------------" << endl;
	heap.deleteMax();
	heap.printHeap();



	system("pause");
}