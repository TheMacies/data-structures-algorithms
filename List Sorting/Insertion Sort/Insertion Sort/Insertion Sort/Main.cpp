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

node* insertionSort(node* head) {
	if (!head) {
		return nullptr;
	}
	node* newHead = head;
	head = head->next;
	newHead->next = nullptr;

	while (head) {
		node* toInsert = head;
		head = head->next;
		if (toInsert->value < newHead->value) {
			toInsert->next = newHead;
			newHead = toInsert;
			continue;
		}
		if (!newHead->next) {
			newHead->next = toInsert;
			toInsert->next = nullptr;
			continue;
		}
		
		node* prev = newHead;
		for (node* current = newHead->next;current;current = current->next) {
			if (current->value > toInsert->value) {
				prev->next = toInsert;
				toInsert->next = current;
				break;
			}
			prev = current;
		}
		if (!prev->next) {
			prev->next = toInsert;
			toInsert->next = nullptr;
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
	head = insertionSort(head);
	printList(head);
	getchar();
}