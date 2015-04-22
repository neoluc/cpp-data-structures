class Queue {
	struct Node;
	Node *first;
	Node *last;
public:
	Queue();
	~Queue();
	void push(int);
	int front();
	bool empty();
	void pop();
};

Queue::Queue() {
	first = nullptr;
	last = nullptr;
}

struct Queue::Node {
	int value;
	Node *next;
};

void Queue::push(int v) {
	Node *n = new Node;
	n->value = v;
	n->next = nullptr;
	if (first == nullptr) {
		first = n;
	} else {
		last->next = n;
	}
	last = n;
}

bool Queue::empty() {
	return first == nullptr;
}

void Queue::pop() {
	Node *t = first;
	first = first->next;
	if (!first) {
		last = nullptr;
	}
	delete t;
}

int Queue::front() {
	return first->value;
}