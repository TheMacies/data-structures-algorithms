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

/* Driver program to test above functions */
int main()
{
//	int arr[] = { 12, 11, 13, 5, 6, 7 };
	//int n = sizeof(arr) / sizeof(arr[0]);


	srand(time(NULL));

	int length = 35;
	int* arr = new int[length];
	for (int i = 0;i < length;i++) {
		arr[i] = rand() % 20;
		cout << arr[i] << " ";
	}

	printf("Given array is \n");
	printArray(arr, length);

	MergeSort(arr, length);

	printf("\nSorted array is \n");
	printArray(arr, length);
	getchar();
	return 0;
}