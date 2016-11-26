
#include "leftist_heap.cpp"

using namespace std;

int main() {
	HeapNode* root = new HeapNode(2);
	root = root->insert(5);
	root = root->insert(4);
	root = root->insert(23);
	root = root->insert(1);
	root = root->insert(1);
	root = root->insert(10);
	root->PreOrderPrint();

	int max;
	root = root->getMax(max);
	cout << endl << "MAX " << max << endl;
	root->PreOrderPrint();
	system("pause");
}