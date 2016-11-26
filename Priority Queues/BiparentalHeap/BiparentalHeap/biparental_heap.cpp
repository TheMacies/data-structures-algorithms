#include <iostream>

using namespace std;


struct ElemPosition {
public :
	int i;
	int j;
	int k;

	ElemPosition() {

	}

	ElemPosition(int kPos) {
		k = kPos;
		i = int(ceil(0.5*(-1 + sqrt(1.0 + 8 * k))));
		j = int(k - 0.5*i*(i - 1));
	}

	ElemPosition(int iPos, int jPos) {
		i = iPos;
		j = jPos;
		k = i*(i - 1) / 2 + j;
	}

};

class BiparentalHeap {
	int tabLength;
	int heapSize;
	int* heap;



	public: 
		BiparentalHeap() {
		tabLength = 10;
		heap = new int[10];
		heapSize = 1;
	}

		BiparentalHeap(int* tab) {
			heapSize = sizeof(tab);
			heap = tab;
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

	bool search(int val) {
		if (heapSize == 1) {
			return false;
		}
		ElemPosition currentPos = ElemPosition(heapSize - 1);
		while (true) {
			if (heap[currentPos.k] == val) {
				return true;
			}
			if (currentPos.j == 1) {
				break;
			}
			if (val > heap[currentPos.k]) {
				currentPos = ElemPosition(currentPos.i - 1, currentPos.j - 1);
			}
			else {
				currentPos = ElemPosition(currentPos.i + 1, currentPos.j);
				if (currentPos.k >= heapSize) {
					currentPos = ElemPosition(currentPos.i-1, currentPos.j - 1);
				}
			}
		}
		return false;
	}

	void printHeap() {
		int currentRow = 1;
		int count = 1;
		for (int i = 1;i < heapSize;i++) {
			cout << heap[i] << "  ";
			count--;
			if (0 == count) {
				cout << endl;
				currentRow++;
				count = currentRow;
			}
		}
	}

	private:

	void heapUp(int i) {
		while (i != 1) {
			int temp = heap[i];
			ElemPosition upperElem;
			ElemPosition currentPos = ElemPosition(i);
			// If elem is not first to the left in a row
			if (currentPos.j != 1) {
				upperElem = ElemPosition(currentPos.i - 1, currentPos.j - 1);
				//If elem is not first to the right in a row
				if (ElemPosition(i + 1).j != 1) {
					//Elem on right side is bigger
					if (heap[upperElem.k] < heap[upperElem.k + 1]) {
						upperElem = ElemPosition(upperElem.k + 1);
					}
				}
			} 
			else {
				upperElem = ElemPosition(currentPos.i - 1, currentPos.j);
			}

			if (heap[i] > heap[upperElem.k]) {
				heap[i] = heap[upperElem.k];
				heap[upperElem.k] = temp;
				i = upperElem.k;
			}
			else {
				return;
			}
		}
	}

	void heapDown(int i) {
		while(true) {
			ElemPosition currentPos = ElemPosition(i);
			ElemPosition biggerElem = ElemPosition(currentPos.i + 1, currentPos.j);
			if (biggerElem.k >= heapSize) {
				return;
			}
			if (biggerElem.k + 1 < heapSize) {
				if (heap[biggerElem.k] < heap[biggerElem.k + 1]) {
					biggerElem = ElemPosition(biggerElem.k + 1);
				}
			}

			if (heap[currentPos.k] < heap[biggerElem.k]) {
				int temp = heap[currentPos.k];
				heap[currentPos.k] = heap[biggerElem.k];
				heap[biggerElem.k] = temp;
				i = biggerElem.k;
			}
			else {
				return;
			}
		}
	}
};