#include "LinkedList.hpp"
#include "string.h"

LinkedList::LinkedList() {
	head = NULL;
	current = NULL;
	tail = NULL;
	length = 0;
}

LinkedList::~LinkedList() {
	clear();
}

void LinkedList::clear() {
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

const int LinkedList::getLength() {
	return length;
}

void LinkedList::pushNode(Data data) {
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

void LinkedList::shiftNode(Data data) {
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

void LinkedList::addNode(Data data, int index) {
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

const Data LinkedList::getHead() {
	if (head == NULL) {
		throw std::out_of_range("List is empty");
	}
	return head->data;
}

const Data LinkedList::getTail() {
	if (tail == NULL) {
		throw std::out_of_range("List is empty");
	}
	return tail->data;
}

Data& LinkedList::next() {
	if (current == NULL || current == tail) {
		current = head;
		return current->data;
	}
	current = current->next;
	return current->data;
}

Data& LinkedList::prev() {
	if (current == NULL || current == head) {
		current = tail;
		return current->data;
	}
	current = current->prev;
	return current->data;
}

void LinkedList::setIterator(int index) {
	current = head;
	for (int i = 0; i < index - 1; i++) {
		current = current->next;
	}
}

void LinkedList::clearIterator() {
	current = NULL;
}

void LinkedList::remove(const char* key) {
	if (head == NULL) {
		return;
	}
	Node *cur = head;

	while (cur != NULL) {
		if (strcmp(cur->data.key, key)) {
			if (cur->prev == NULL) {
				if (tail->prev == NULL) {
					delete head;
					tail = head = NULL;
				} else {
					head = head->next;
					delete head->prev;
					head->prev = NULL;
				}
			} else if (cur->next == NULL) {
				tail = tail->prev;
				delete tail->next;
				tail->next = NULL;
			} else {
				Node *prevEl = cur->prev;
				Node *nextEl = cur->next;
				prevEl->next = nextEl;
				nextEl->prev = prevEl;
				delete cur;
			}
			length--;
			clearIterator();
			return;
		}
		cur = cur->next;
	}
}

bool LinkedList::empty() {
	return head == NULL;
}