struct note {
	int id;
	int deposit;
	char name[30];
	char category[5];
	char date[9];
};

std::ostream& operator << (std::ostream &out, const struct note memo) {
	out << memo.id << " " << memo.name << " " << memo.category << " " << memo.deposit << " " << memo.date;
  return out;
}

class LinkedList {

private:
	struct Node {
		struct note data;
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

	void pushNode(struct note data) {
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

	void shiftNode(struct note data) {
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

	void addNode(struct note data, int index) {
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

	struct note getHead() const {
		if (head == NULL) {
			throw std::out_of_range("List is empty");
		}
		return head->data;
	}

	struct note getTail() const {
		if (tail == NULL) {
			throw std::out_of_range("List is empty");
		}
		return tail->data;
	}

	struct note next() {
		if (current == NULL || current == tail) {
			current = head;
			return current->data;
		}
		current = current->next;
		return current->data;
	}

	struct note prev() {
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

	struct note &operator[] (int index) {
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

	void print() {
		Node *cur = head;
		while (cur != NULL) {
			std::cout << cur->data << std::endl;
			cur = cur->next;
		}
	}
};