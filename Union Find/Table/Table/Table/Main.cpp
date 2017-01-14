#include <iostream>
#include "Table.cpp"

using namespace std;

int main() {
	Table t = Table();
	for (int i = 10;i < 16;i++) {
		t.Insert(i, 1);
	}
	cout << t.Find(15) << " should be " << 1 << endl;
	cout << t.Find(17) << " should be " << -1 << endl;

	for (int i = 20;i < 46;i++) {
		t.Insert(i, 2);
	}

	cout << t.Find(25) << " should be " << 2 << endl;
	cout << t.Find(19) << " should be " << -1 << endl;
	t.Union(1, 2, 3);

	cout << t.Find(25) << " should be " << 3 << endl;
	cout << t.Find(15) << " should be " << 3 << endl;
	getchar();

}