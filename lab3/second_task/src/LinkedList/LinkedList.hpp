#include <iostream>
#include "Data.hpp"

class LinkedList {

private:
	struct Node {
		Data * data;
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
	void pushNode(Data * data);
	void shiftNode(Data * data);
	void addNode(Data * data, int index);
	Data * next();
	Data * prev();
	void setIterator(int index);
	void clearIterator();
	void remove(unsigned key);
	bool empty();

};