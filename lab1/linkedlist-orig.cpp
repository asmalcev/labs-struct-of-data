#include <iostream>

class LinkedList {

private:
	struct Node {
		int data;
		Node *next;
		Node *prev;
	};

	int length = 0;
	Node *head = NULL;
	Node *current = NULL;
	Node *tail = NULL;

public:
	~LinkedList() {
		while (head != NULL) {
			current = head->next;
			delete head;
			head = current;
		}
	}

	int getLength() {
		return length;
	}

	void addNode(int n) {
		Node *tmp = new Node;
		tmp->data = n;
		tmp->next = NULL;
		tmp->prev = NULL;

		if (head == NULL) {
			head = tail = tmp;
		} else {
			tail->next = tmp;
			tmp->prev = tail;
			tail = tail->next;
		}

		length++;
	}

	int getHead() {
		if (head == NULL) {
			throw std::out_of_range("List is empty");
		}
		return head->data;
	}

	int getTail() {
		if (tail == NULL) {
			throw std::out_of_range("List is empty");
		}
		return tail->data;
	}

	int next() {
		if (current == NULL || current == tail) {
			current = head;
			return current->data;
		}
		current = current->next;
		return current->data;
	}

	void remove(int index) {
		if (index == 0) {
			
		}
		if (index < 1 || index >= length) {
			throw std::out_of_range("Index is out of range");
		}
		Node *cur = head;
		int currentIndex = 0;

		while (currentIndex++ < index) {
			cur = cur->next;
		}
		Node *prevEl = cur->prev;
		Node *nextEl = cur->next;

		prevEl->next = nextEl;
		nextEl->prev = prevEl;

		delete cur;
	}

	void print() {
		Node *cur = head;
		while (cur != NULL) {
			std::cout << cur->data << " ";
			cur = cur->next;
		}
		std::cout << std::endl;
	}
};

int main() {
	LinkedList a;
	std::cout << "Length: " << a.getLength() << std::endl;
	a.addNode(1);
	a.addNode(2);
	a.addNode(3);
	a.addNode(9);
	a.addNode(4);
	a.addNode(7);
	std::cout << "Length: " << a.getLength() << std::endl;
	std::cout << "Head: " << a.getHead() << std::endl;
	std::cout << "Tail: " << a.getTail() << std::endl;
	a.print();
	a.remove(4);
	a.print();
}