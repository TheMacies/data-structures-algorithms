#include <iostream>

using namespace std;

class Heap {
	int tabLength;
	int heapSize;
	int* heap;

	public: 
		Heap() {
		tabLength = 10;
		heap = new int[10];
		heapSize = 1;
	}

		Heap(int* tab,int size) {
			heapSize = size+1;
			tabLength = 2 * heapSize;
			heap = new int[tabLength];
			for (int i = 0;i < size;i++) {
				heap[i+1]= tab[i];
			}
			for (int i = heapSize / 2;i >= 1; i--) {
				heapDown(i);
			}
		}

	void insert(int value) {
		if (heapSize == tabLength) {
			tabLength *= 2;
			int* newTab = new int[tabLength];

			for (int i = 1;i < tabLength / 2;i++) {
				newTab[i] = heap[i];
			}
			delete heap;
			heap = newTab;
		}
		heap[heapSize] = value;
		heapUp(heapSize++);
	}

	int deleteMax() {
		if (heapSize == 1) {
			return 0;
		}
		int returnValue = heap[1];
		
		heap[1] = heap[heapSize - 1];
		heapSize--;

		heapDown(1);

		return returnValue;
	}

	void printHeap() {
		int currentLog = 2;
		for (int i = 1;i < heapSize;i++) {
			if (i == currentLog) {
				cout << endl;
				currentLog *= 2;
			}
			cout << heap[i] << "  ";

		}
	}

	private:

	void heapUp(int i) {
		while (i != 1) {
			if (heap[i] > heap[i / 2]) {
				int a = heap[i];
				heap[i] = heap[i / 2];
				heap[i / 2] = a;
				i = i / 2;
			}
			else {
				break;
			}
		}
	}

	void heapDown(int i) {
		int currentElem = i;
		while (true) {
			if (currentElem * 2 >= heapSize) {
				return;
			}
			if (currentElem * 2 + 1 >= heapSize) {
				if (heap[currentElem] < heap[currentElem * 2]) {
					int temp = heap[currentElem];
					heap[currentElem] = heap[currentElem * 2];
					heap[currentElem * 2] = temp;
					return;
				}
			}
			int biggerIndex = currentElem * 2;
			if (heap[biggerIndex] < heap[biggerIndex + 1]) {
				biggerIndex++;
			}
			if (heap[biggerIndex] > heap[currentElem]) {
				int temp = heap[currentElem];
				heap[currentElem] = heap[biggerIndex];
				heap[biggerIndex] = temp;
				currentElem = biggerIndex;
			}
			else {
				return;
			}
		}
	}

	

};