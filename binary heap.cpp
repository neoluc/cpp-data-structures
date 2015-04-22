class BinaryHeap {
	vector<int> v;
	void swim(int);
	void push(int);
public:
	void sink(int);
	int front();
	void pop();
};

void BinaryHeap::swim(int k) { 
	while (k > 1 && v[k / 2] < v[k]) {
		swap(v[k / 2], v[k]);
		k = k / 2;
	}
}

void BinaryHeap::sink(int k) {
	while (2 * k <= v.size()) {
		int j = 2 * k;
		if (j < v.size() && v[j] < v[j + 1]) {
			j++;
		}
		if (v[j] >= k) {
			break;
		}
		swap(k, j);
		k = j;
	}
}

void BinaryHeap::push(int t) {
	v.push_back(t);
	swim(v.size() - 1);
}

int BinaryHeap::front() {
	return v.front();
}

void BinaryHeap::pop() {
	swap(v.front(), v.back());
	sink(0);
	v.pop_back();
}
