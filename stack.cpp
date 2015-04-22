class Stack {
	struct Node;
	Node *first;
public:
	Stack();
	~Stack();
	void push(int);
	int front();
	void pop();
	bool empty();
};

struct Stack::Node {
	Node *next;
	int value;
};

Stack::Stack() {
	first = nullptr;
}

void Stack::push(int v) {
	Node *n = new Node;
	n->next = first;
	n->value = v;
	first = n;
}

bool Stack::empty() {
	return first == nullptr;
}

int Stack::front() {
	return first->value;
}

void Stack::pop() {
	Node *t = first->next;
	delete first;
	first = t;
}