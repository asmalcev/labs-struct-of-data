#include <iostream>

template <typename T>
class LinkedList {

private:
	struct Node {
		T data;
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

	void pushNode(T data) {
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

	void shiftNode(T data) {
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

	void addNode(T data, int index) {
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

	T getHead() const {
		if (head == NULL) {
			throw std::out_of_range("List is empty");
		}
		return head->data;
	}

	T getTail() const {
		if (tail == NULL) {
			throw std::out_of_range("List is empty");
		}
		return tail->data;
	}

	T next() {
		if (current == NULL || current == tail) {
			current = head;
			return current->data;
		}
		current = current->next;
		return current->data;
	}

	T prev() {
		if (current == NULL || current == head) {
			current = tail;
			return current->data;
		}
		current = current->prev;
		return current->data;
	}

	void setIterator(int index) {
		current = head;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
	}

	void clearIterator() {
		current = NULL;
	}

	void remove(int index) {
		if (index < 0 || index >= length || length == 0) {
			throw std::out_of_range("Index is out of range");
		} else if (index == 0) {
			if (length == 1) {
				delete head;
				tail = head = NULL;
			} else {
				head = head->next;
				delete head->prev;
				head->prev = NULL;
			}
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
		clearIterator();
	}

	void print() {
		Node *cur = head;
		while (cur != NULL) {
			std::cout << cur->data << " ";
			cur = cur->next;
		}
		std::cout << std::endl;
	}

	T &operator[] (int index) {
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
	LinkedList<int> a;
	a.pushNode(1);
	a.print();
	a.remove(0);
}