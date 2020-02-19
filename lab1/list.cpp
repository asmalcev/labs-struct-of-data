#include <iostream>

class LinkedList {

  private:
    class Node { 
      public: 
        Node* prev;
        int data; 
        Node* next; 
    };

    int length = 0;
    Node* head = NULL;
    Node* current = NULL;
    Node* tail = NULL;

  public:

  	int getLength() {
  	  return length;
  	}

    void addNode(int n) {
      Node *tmp = new Node;
      tmp-> data = n;
      tmp-> next = NULL;

      if (head == NULL) {
        head = tmp;
        tail = tmp;
      } else {
        tail-> next = tmp;
        tail = tail-> next;
      }

			length++;
    }

		int getHead() {
			if (head == NULL) {
				return NULL;
			}
			return head-> data;
		}

		int getTail() {
			if (tail == NULL) {
				return NULL;
			}
			return tail-> data;
		}

		int next() {
			if (current == NULL || current == tail) {
				current = head;
				return current-> data;
			}
			current = current-> next;
			return current-> data;
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
}