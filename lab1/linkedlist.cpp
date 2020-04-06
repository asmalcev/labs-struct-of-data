#include <iostream>
#include <string.h>
#include "linkedlist.hpp"

std::ostream& operator << (std::ostream &out, const struct note memo) {
	out << memo.date << " " << memo.id << " " << memo.name << " " << memo.category << " ";
	if (memo.isDepositDouble) {
		out << memo.deposit.depositD;
	} else {
		out << memo.deposit.depositI;
	}

  return out;
}

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

int LinkedList::getLength() const {
	return length;
}

void LinkedList::insert(Node* cur, Node* tmp) {
	if (cur->prev == NULL) {
		tmp->prev = NULL;
		cur->prev = tmp;
		tmp->next = cur;
		head = tmp;
	} else if (cur->next == NULL) {
		tmp->next = NULL;
		tail->next = tmp;
		tmp->prev = tail;
		tail = tail->next;
	} else {
		tmp->prev = cur->prev;
		tmp->next = cur;
		tmp->prev->next = tmp;
		cur->prev = tmp;
	}
}

void LinkedList::push(struct note data) {
	Node *tmp = new Node;
	tmp->data = data;
	if (head == NULL) {
		tmp->prev = NULL;
		tmp->next = NULL;
		head = tail = tmp;
	} else {
		Node *cur = head;
		int day, month, year;
  	int dayToAdd, monthToAdd, yearToAdd;
		bool isAdded = false;
		sscanf(data.date, "%2d.%2d.%4d", &dayToAdd, &monthToAdd, &yearToAdd);

		while(cur != NULL) {
			sscanf(cur->data.date, "%2d.%2d.%4d", &day, &month, &year);
			if (year < yearToAdd) {
				insert(cur, tmp);
				isAdded = true;
				break;
			} else if (year == yearToAdd && month < monthToAdd) {
				insert(cur, tmp);
				isAdded = true;
				break;
			} else if (year == yearToAdd && month == monthToAdd && day < dayToAdd) {
				insert(cur, tmp);
				isAdded = true;
				break;
			}
			cur = cur->next;
		}

		if (!isAdded) {
			tmp->next = NULL;
			tail->next = tmp;
			tmp->prev = tail;
			tail = tail->next;
		}
	}
	clearIterator();
	length++;
}

struct note LinkedList::next() {
	if (current == NULL || current == tail) {
		current = head;
		return current->data;
	}
	current = current->next;
	return current->data;
}

struct note LinkedList::prev() {
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

int LinkedList::remove(int id) {
	if (head == NULL) {
		return 1;
	}
	Node *cur = head;

	while (cur != NULL) {
		if (cur->data.id == id) {
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
			return 0;
		}
		cur = cur->next;
	}
	return 2;
}

void LinkedList::print() {
	Node *cur = head;
	while (cur != NULL) {
		std::cout << cur->data << std::endl;
		cur = cur->next;
	}
}

double LinkedList::findTheBigestDeposit() {
	Node* cur = head;
	double maxDeposit = -1;

	while (cur != NULL) {
		if(!strcmp(cur->data.category, "fast")) {
			if (cur->data.isDepositDouble) {
				if (cur->data.deposit.depositD > maxDeposit) {
					maxDeposit = cur->data.deposit.depositD;
				}
			} else {
				if ((double) cur->data.deposit.depositI > maxDeposit) {
					maxDeposit = (double) cur->data.deposit.depositI;
				}
			}
		}
		cur = cur->next;
	}

	return maxDeposit;
}

struct note &LinkedList::operator[] (int index) {
	if (index < 0 || index >= length) {
		throw std::out_of_range("Index is out of range");
	} else {
		Node *cur;
		if (index > length / 2) {
			cur = head;
			for (int i = 0; i < index; i++) {
				cur = cur->next;
			}
		} else {
			cur = tail;
			for (int i = length; i > index; i--) {
				cur = cur->next;
			}
		}
		
		return cur->data;
	}
}

size_t LinkedList::getId() {
	if (tail == NULL) {
		return 100000;
	} else {
		return tail->data.id + 1;	 
	}
}