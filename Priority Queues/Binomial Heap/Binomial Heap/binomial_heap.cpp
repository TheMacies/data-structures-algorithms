#include <iostream>

using namespace std;

class HeapNode {
public:
	HeapNode* child;
	HeapNode* prev;
	HeapNode* next;
	int rank;
	int value;

	HeapNode() {
	}

	HeapNode(int val) {
		value = val;
		rank = 0;
		prev = this;
		next = nullptr;
		child = nullptr;
	}

	HeapNode* ExtractFirst(HeapNode* &root) {
		if (next) {
			next->prev = prev;
		}
		root = next;
		return this;
	}

	void InsertLast(HeapNode* node) {
		prev->next = node;
		prev = node;
		node->next = nullptr;
	}


	HeapNode* MergeQueues(HeapNode* q1, HeapNode* q2) {
		HeapNode* newQueue = nullptr;
		HeapNode* carry = nullptr;
		while (q1 && q2) {
			if (q1->rank > q2->rank) {
				HeapNode* temp = q1;
				q1 = q2;
				q2 = temp;
			}
			if (carry) {
				if (carry->rank == q1->rank) {
					carry = MergeTrees(carry, q1->ExtractFirst(q1));
					if (carry->rank > q2->rank) {
						if (!newQueue) {
							newQueue = q2->ExtractFirst(q2);
						}
						else {
							newQueue->InsertLast(q2->ExtractFirst(q2));
						}
					}
				}
				else {
					if (!newQueue) {
						newQueue = carry;
						carry = nullptr;
					}
					else {
						newQueue->InsertLast(carry);
						carry = nullptr;
					}
				}
			}
			else {
				if (q1->rank == q2->rank) {
					carry = MergeTrees(q1->ExtractFirst(q1), q2->ExtractFirst(q2));
				}
				else {
					if (!newQueue) {
							newQueue = q1->ExtractFirst(q1);
						}
						else {
							newQueue->InsertLast(q1->ExtractFirst(q1));
						}
				}
			}
		}
		if (q2) {
			q1 = q2;
		}
		while (q1) {
			if (carry) {
				if (carry->rank == q1->rank) {
					carry = MergeTrees(q1->ExtractFirst(q1), carry);
				}
				else {
					if (!newQueue) {
						newQueue = carry;
					}
					else {
						newQueue->InsertLast(carry);
						carry = nullptr;
					}
				}
			}
			else {
				newQueue->InsertLast(q1->ExtractFirst(q1));
			}
		}
		if (carry) {
			if(!newQueue) {
				newQueue = carry;
			}
			else {
				newQueue->InsertLast(carry);
			}
		}
		return newQueue;
	}

	HeapNode* MergeTrees(HeapNode* t1, HeapNode* t2) {
		if (t1->value > t2->value) {
			HeapNode* temp = t1;
			t1 = t2;
			t2 = temp;
		}
		if (t2->child) {
			t2->child->prev->next = t1;
			t2->child->prev = t1;
			t2->child->prev->next = nullptr;
		}
		else {
			t2->child = t1;
			t2->child->next = nullptr;
			t2->child->prev = t1;
		}
		t2->rank++;
		return t2;
	}

	HeapNode* insert(int v) {
		HeapNode* node = new HeapNode(v);
		return MergeQueues(this, node);
	}

	HeapNode* getMax(int& out) {
		HeapNode* max = this;
		HeapNode* iterator = this->next;
		while (iterator != this) {
			if (iterator->value > max->value) {
				max = iterator;
			}
		}
		out = max->value;
		if (max == this) {
			if (max->next == nullptr) {
				return child;
			}
			next->prev = prev;
			return MergeQueues(next, child);
		}
		max->prev->next = max->next;
		prev = max->prev;
		return MergeQueues(this, max->child);
	}

	void PrintQueue() {
		cout << " wartosc wezla " <<  value << endl;
		cout << " wysokosc drzewa " << rank << endl;
		if (child) {
			child->PrintQueue();
		}
		if (next) {
			next->PrintQueue();
		}
	}
};
