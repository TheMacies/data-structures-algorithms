#include <iostream>
#include "Splay.cpp"

using namespace std;

int main() {
	Splay s =  Splay();

	cout << s.Search(212);
	s.Insert(2);
	cout << s.Search(2);
	s.Insert(4);
	s.Insert(1);
	cout << s.Search(4);
	cout << s.Search(1);
	s.Delete(1);
	cout << s.Search(1);
	getchar();
}