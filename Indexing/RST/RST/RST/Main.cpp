#include <iostream>
#include "RST.cpp"

using namespace std;


int main() {
	RST r = RST();
	cout << r.Search(10) << "should be 0" << endl;
	r.Insert(5);
	cout << r.Search(10) << "should be 0" << endl;
	cout << r.Search(5) << "should be 1" << endl;
	for (int i = 1;i < 10;i++) {
		r.Insert(i);
	}
	cout << r.Search(5) << "should be 1" << endl;
	cout << r.Search(3) << "should be 1" << endl;
	r.Delete(5);
	cout << r.Search(5) << "should be 0" << endl;
	cout << r.Search(3) << "should be 1" << endl;
	r.Delete(3);
	cout << r.Search(5) << "should be 0" << endl;
	cout << r.Search(3) << "should be 0" << endl;
	getchar();
}