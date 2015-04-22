class PriorityQueue {
	struct Node;
	Node *first;
	Node *last;
public:
	PriorityQueue();
	bool empty();
	void push(int);
	int pop();
};

struct PriorityQueue::Node {
	Node *next;
	Node *prev;
	int value;
};

PriorityQueue::PriorityQueue() {
	first = nullptr;
	last = nullptr;
}

bool PriorityQueue::empty() {
	return first == nullptr;
}

void PriorityQueue::push(int v) { // normal push
	Node *t = new Node;
	t->next = nullptr;
	t->prev = nullptr;
	t->value = v;
	if (first == nullptr) {
		first = t;
	} else {
		last->next = t;
		t->prev = last;
	}
	last = t;
}

int PriorityQueue::pop() { // just pop the max one and reconnect those linked list
	Node *m = nullptr;
	for (Node *t = first; t != nullptr; t = t->next) {
		if (m == nullptr || m->value > t->value) {
			m = t;
		}
	}
	int r = m->value;
	Node *p = m->prev;
	if (p) {
		p->next = m->next;
	}
	if (m->next) {
		m->next->prev = p;
	}
	delete m;
	return r;
}