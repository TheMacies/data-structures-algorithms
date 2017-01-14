#include <iostream>
#include "PATRICIA.cpp"

using namespace std;


int main() {
	PATRICIA r = PATRICIA();
	cout << (r.Search(10)->key == 10) << " should be 0" << endl;
	r.Insert(5);
	cout << (r.Search(5)->key == 5) << " should be 1" << endl;
	for (int i = 128;i >= 18;i--) {
		r.Insert(i);
	}
	cout << (r.Search(5)->key == 5) << " should be 1" << endl;
	cout << (r.Search(124)->key == 124) << " should be 1" << endl;
	/*
	TODO : DELETE
	r.Delete(30);
	cout << (r.Search(47)->key == 47) << "should be 1" << endl;
	cout << (r.Search(30)->key == 30) << "should be 0" << endl;
	r.Delete(121);
	cout << (r.Search(121)->key == 121) << "should be 0" << endl;
	cout << (r.Search(122)->key == 122) << "should be 1" << endl;*/
	getchar();
}