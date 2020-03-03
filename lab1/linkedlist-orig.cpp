#include <iostream>

class LinkedList {

private:
	struct Node {
		int data;
		Node *next;
		Node *prev;
	};

	int length;
	Node* head;
	Node* current;
	Node* tail;

public:
	LinkedList() {
		head = NULL;
		current = NULL;
		tail = NULL;
		length = 0;
	}

	~LinkedList() {
		clear();
	}

	void clear() {
		while (head != NULL) {
			current = head->next;
			delete head;
			head = current;
		}
		head = NULL;
		current = NULL;
		tail = NULL;
		length = 0;
	}

	int getLength() const {
		return length;
	}

	void pushNode(int data) {
		Node *tmp = new Node;
		tmp->data = data;
		tmp->next = NULL;

		if (head == NULL) {
			head = tail = tmp;
		} else {
			tail->next = tmp;
			tmp->prev = tail;
			tail = tail->next;
		}

		length++;
	}

	void shiftNode(int data) {
		Node *tmp = new Node;
		tmp->data = data;
		tmp->prev = NULL;

		if (head == NULL) {
			head = tail = tmp;
		} else {
			head->prev = tmp;
			tmp->next = head;
			head = head->prev;
		}

		length++;
	}

	void addNode(int data, int index) {
		if (index < 0 || index >= length) {
			throw std::out_of_range("Index is out of range");
		} else if (index == 0) {
			shiftNode(data);
		} else if (index == length - 1) {
			pushNode(data);
		} else {
			Node *cur = head;
			for (int i = 0; i < index - 1; i++) {
				cur = cur->next;
			}
			Node *tmp = new Node;
			tmp->data = data;
			tmp->prev = cur;
			tmp->next = cur->next;
			tmp->next->prev = tmp;
			cur->next = tmp;
			length++;
		}
	}

	int getHead() const {
		if (head == NULL) {
			throw std::out_of_range("List is empty");
		}
		return head->data;
	}

	int getTail() const {
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

	int prev() {
		if (current == NULL || current == head) {
			current = tail;
			return current->data;
		}
		current = current->prev;
		return current->data;
	}

	void remove(int index) {
		if (index < 0 || index >= length) {
			throw std::out_of_range("Index is out of range");
		} else if (index == 0) {
			head = head->next;
			delete head->prev;
			head->prev = NULL;
		} else if (index == length - 1) {
			tail = tail->prev;
			delete tail->next;
			tail->next = NULL;
		} else {
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
		length--;
	}

	void print() {
		Node *cur = head;
		while (cur != NULL) {
			std::cout << cur->data << " ";
			cur = cur->next;
		}
		std::cout << std::endl;
	}

	int &operator[] (int index) {
		if (index < 0 || index >= length) {
			throw std::out_of_range("Index is out of range");
		} else {
			Node *cur = head;
			for (int i = 0; i < index; i++) {
				cur = cur->next;
			}
			return cur->data;
		}
	}
};

int main() {
	LinkedList a;
	std::cout << "Length: " << a.getLength() << std::endl;
	a.pushNode(1);
	a.pushNode(2);
	a.pushNode(3);
	a.pushNode(9);
	a.pushNode(4);
	a.pushNode(7);
	std::cout << "Length: " << a.getLength() << std::endl;
	std::cout << "Head: " << a.getHead() << std::endl;
	std::cout << "Tail: " << a.getTail() << std::endl;
	a.print();
	a.remove(4);
	a.print();
	for (int i = 0; i < a.getLength(); i++)
		std::cout << a.next() << " ";
	std::cout << std::endl;
	a.remove(0);
	a.remove(3);
	a.print();
	std::cout << "Length: " << a.getLength() << std::endl;
	a.clear();
	std::cout << "Length: " << a.getLength() << std::endl;
	a.print();
	for (int i = 0; i < 10; i++)
		a.pushNode(i);
	a.print();
	a[0] = 5;
	a.print();
	a.remove(0);
	a.addNode(99, 3);
	a.addNode(-4, 0);
	for (int i = 0; i < a.getLength(); i++)
		std::cout << a.prev() << " ";
	std::cout << std::endl;
	std::cout << "Length: " << a.getLength() << std::endl;
}