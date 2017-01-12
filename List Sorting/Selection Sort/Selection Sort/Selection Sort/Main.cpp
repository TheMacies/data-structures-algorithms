#include <iostream>
#include <time.h>

using namespace std;

struct node {
	int value;
	node* next;
};

void printList(node* list) {
	while (list != nullptr) {
		cout << list->value << "  ";
		list = list->next;
	}
	cout << endl;
}

node* selectionSort(node* head) {
	node* newHead = nullptr;
	while (head) {
		node* prev = nullptr;
		node* max = head;
		for (node* current = head;current->next;current = current->next) {
			if (current->next->value > max->value) {
				prev = current;
				max = current->next;
			}
		}
		if (prev) {
			prev->next = max->next;
			max->next = newHead;
			newHead = max;
		}
		else {
			head = head->next;
			max->next = newHead;
			newHead = max;
		}
	}
	return newHead;
}


void main() {
	srand(time(NULL));
	node* head = new(node);
	head->value = 1;
	head->next = nullptr;

	for (int i = 0;i < 20;i++) {
		node * n = new(node);
		n->value = rand() % 100;
		n->next = head;
		head = n;
	}
	printList(head);
	head = selectionSort(head);
	printList(head);
	getchar();
}