#include <time.h>
#include <iostream>
#include "Merge.h"


using namespace std;


void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	srand(time(NULL));

	int length = 33;
	int* arr = new int[length];
	for (int i = 0;i < length;i++) {
		arr[i] = rand() % 20;
	}

	printf("Given array is \n");
	printArray(arr, length);

	MergeSort(arr, length);

	printf("\nSorted array is \n");
	printArray(arr, length);
	getchar();
	return 0;
}