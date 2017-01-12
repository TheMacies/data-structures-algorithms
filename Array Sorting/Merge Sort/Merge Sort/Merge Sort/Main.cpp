#include <iostream>
#include <time.h>

using namespace std;

void printArray(int* arr,int length) {
	for(int i =0;i<length;i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

int* merge(int* arr, int startingIndex, int lLeft, int lRight) {
	int* temp = new int[lLeft + lRight];
	int leftTaken = 0;
	int rightTaken = 0;
	for (int i = 0;i < lLeft + lRight;i++) {
		if (leftTaken != lLeft) {
			if (rightTaken != lRight) {
				if (arr[startingIndex + leftTaken] < arr[startingIndex + lLeft + rightTaken]) {
					temp[i] = arr[startingIndex + leftTaken];
					leftTaken++;
				}
				else {
					temp[i] = arr[startingIndex + lLeft + rightTaken];
					rightTaken++;
				}
			}
			else {
				temp[i] = arr[startingIndex + leftTaken];
			    leftTaken++;
			}
		}
		else {
			temp[i] = arr[startingIndex + lLeft + rightTaken];
			rightTaken++;
		}
	}
	for (int i = 0;i < lLeft + lRight;i++) {
		arr[startingIndex + i] = temp[i];
	}
		return arr;
}

int* mergeSort(int* arr, int startingIndex, int length) {
	if (length == 1) {
		return arr;
	}
	int lLeft = length / 2;
	int lRight = length - lLeft;

	int *sortedLeft = mergeSort(arr, startingIndex, lLeft);
	int *sortedRight = mergeSort(arr, startingIndex + lLeft, lRight);

    return 	merge(arr, startingIndex, lLeft, lRight);
}





void main() {
	srand(time(NULL));
	int length = 20;
	int* arr = new int[length];
	for (int i = 0;i < length;i++) {
		arr[i] = rand() % 100;
	}
	printArray(arr, length);
    mergeSort(arr,0, length);
	printArray(arr, length);
	getchar();
}