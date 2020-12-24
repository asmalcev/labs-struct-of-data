template <typename T>
class StackVector {

private:

	int size;
  int maxSize;
  T* arr;


public:
	StackVector(int maxSizeOfStack) {
    maxSize = maxSizeOfStack;
    size = 0;
    arr = new T[maxSize];
	}

	~StackVector() {
		delete[] arr;
	}

	void push(T data) {
    if (maxSize == size) {
			throw std::out_of_range("Stack is full");
    } else {
      arr[size++] = data;
    }
	}

	T getTop() const {
		if (size == 0) {
			throw std::out_of_range("Stack is empty");
		} else {
  		return arr[size - 1];
    }
	}

	T pull() {
		if (size == 0) {
			throw std::out_of_range("Stack is empty");
		} else {
      return arr[--size];
    }
  }

  bool isEmpty() {
    if (size == 0) {
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
