template <typename T>
class Stack {

private:
	struct Node {
		T data;
		Node *below;
	};

	int size;
  int maxSize;
	Node* top;

public:
	Stack(int maxSizeOfStack = -1) {
		top = NULL;
    maxSize = maxSizeOfStack;
    size = 0;
	}

	~Stack() {
		Node *tmp;
		while (top != NULL) {
      tmp = top;
      top = top->below;
			delete tmp;
		}
	}

	void push(T data) {
    if (maxSize != -1 && maxSize == size) {
			throw std::out_of_range("Stack is full");
    } else {
      Node *tmp = new Node;
      tmp->data = data;
      tmp->below = NULL;

      if (top == NULL) {
        top = tmp;
      } else {
        tmp->below = top;
        top = tmp;
      }
      size++;
    }
	}

	T getTop() const {
		if (top == NULL) {
			throw std::out_of_range("Stack is empty");
		} else {
  		return top->data;
    }
	}

	T pull() {
		if (top == NULL) {
			throw std::out_of_range("Stack is empty");
		} else {
      Node *tmp;
      tmp = top;
      T dataToReturn = tmp->data;
      top = top->below;

      delete tmp;
      return dataToReturn;
      size--;
    }
  }

  bool isEmpty() {
    if (top == NULL) {
      return true;
    } else {
      return false;
    }
    
  }

  bool isFull() {
    if (size == maxSize) {
      return true;
    } else {
      return false;
    } 
  }
};