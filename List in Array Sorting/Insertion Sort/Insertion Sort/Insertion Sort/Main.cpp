#include <iostream>
#include <time.h>
#include "Insertion.cpp"

using namespace std;

int main() {
	ListInTable l = ListInTable();
	srand(time(NULL));
	for (int i = 1;i < 20;i++) {
		l.Insert(rand()%20);
	}
	l.Print();
	l.Sort();
	l.Print();
	getchar();
}