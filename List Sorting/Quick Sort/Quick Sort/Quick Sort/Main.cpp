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

node* quickSort(node* head, node** tail) {
	if (head == nullptr || head->next == nullptr) {
		*tail = head;
		return head;
	}
	
	node* less = nullptr;
	node* equal = head;
	node* more = nullptr;
	
	node* tailEqual = head;
	node* tailMore = new(node);
	node* tailLess = new(node);

	head = head->next;
	equal->next = nullptr;
	
	while (head) {
		node *temp = head;
		if (head->value < equal->value) {
			head = head->next;
			temp->next = less;
			less = temp;
			continue;
		}
		if (head->value == equal->value) {
			head = head->next;
			temp->next = equal;
			equal = temp;
			continue;
		}
		head = head->next;
		temp->next = more;
		more = temp;
	}

	
	less = quickSort(less, &tailLess);
	more = quickSort(more, &tailMore);
	
	if (more != nullptr) {
		tailEqual->next = more;
		if (tail) {
			*tail = tailMore;
		}
	}

	else {
		if (tail) {
			*tail = tailEqual;
		}
	}
	if (less != nullptr) {
		tailLess->next = equal;
		equal = less;
	}
	return equal;
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
	head = quickSort(head,nullptr);
	printList(head);
	getchar();
}
