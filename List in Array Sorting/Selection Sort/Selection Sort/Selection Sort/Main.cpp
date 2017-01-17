#include <iostream>
#include <time.h>
#include "Selection.cpp"

using namespace std;




int main() {
	ListInArray l = ListInArray();
	srand(time(NULL));

	for (int i = 0;i < 20;i++) {
		l.Insert(rand()%30);
	}
	l.Print();
	l.Sort();
	l.Print();
	getchar();
}