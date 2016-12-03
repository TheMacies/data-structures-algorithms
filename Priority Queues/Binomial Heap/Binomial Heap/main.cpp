#include "binomial_heap.cpp"

using namespace std;

int main() {
	HeapNode* root = new HeapNode(2);
	root = root->insert(5);
	root = root->insert(4);
	root = root->insert(23);
	root = root->insert(1);
	root = root->insert(18);
	root = root->insert(10);
	root = root->insert(24);
	root = root->insert(9);
	root = root->insert(9);
	cout << endl;
	root->PrintQueue();

	system("pause");
}