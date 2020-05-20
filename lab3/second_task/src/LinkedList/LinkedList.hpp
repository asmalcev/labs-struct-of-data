#include <iostream>
#include "Data.hpp"

class LinkedList {

private:
	struct Node {
		Data data;
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
	void pushNode(Data data);
	void shiftNode(Data data);
	void addNode(Data data, int index);
	const Data getHead();
	const Data getTail();
	Data& next();
	Data& prev();
	void setIterator(int index);
	void clearIterator();
	void remove(const char* key);
	bool empty();

};