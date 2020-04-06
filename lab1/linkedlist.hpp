union contribution {
	long long int depositI;
	double depositD;
};

struct note {
	size_t id;
	contribution deposit;			
	char name[15];
	char category[5];
	char date[11];
	bool isDepositDouble;
};

std::ostream& operator << (std::ostream &out, const struct note memo);

class LinkedList {

protected:
	struct Node {
		struct note data;
		Node *next;
		Node *prev;
	};

	int length;
	Node* head;
	Node* current;
	Node* tail;

	void insert(Node* cur, Node* tmp);

public:
	LinkedList();

	~LinkedList();

	void clear();

	int getLength() const;

	void push(struct note data);

	struct note next();

	struct note prev();

	void setIterator(int index);

	void clearIterator();

	int remove(int index);

	void print();

	double findTheBigestDeposit();

	struct note &operator[] (int index);

	size_t getId();
};