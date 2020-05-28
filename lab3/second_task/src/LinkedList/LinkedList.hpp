#include <iostream>

class LinkedList {

private:
	struct Node {
		int data;
		Node * next;
		Node * prev;
	};

	int length;
	Node * head;
	Node * current;
	Node * tail;

public:
	LinkedList();
	~LinkedList();
	void clear();
	const int getLength();
	void pushNode(int data);
	void shiftNode(int data);
	void addNode(int data, int index);
	int next();
	int prev();
	void setIterator(int index);
	void clearIterator();
	void remove(unsigned key);
	bool empty();

};