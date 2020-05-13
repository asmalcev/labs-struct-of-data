#include <iostream>

class LinkedList {

private:
	struct Node {
		int  data;
		Node *next;
		Node *prev;
	};

	int length;
	Node* head;
	Node* current;
	Node* tail;

public:
	LinkedList();
	~LinkedList();
	void clear();
	const int getLength();
	void pushNode(int  data);
	void shiftNode(int  data);
	void addNode(int  data, int index);
	const int getHead();
	const int getTail();
	const int next();
	const int prev();
	void setIterator(int index);
	void clearIterator();
	void remove(int index);
	bool empty();

};