Vector::Vector() {
	a = new int[1];
	size = 0;
	capacity = 1;
}

void Vector::push_back(int v) {
	if (size == capacity) {
		resize_capacity(2 * size);
	}
	a[size] = v;
	size++;
}

int Vector::back() {
	return a[size - 1];
}

void Vector::pop_back() {
	size--;
	if (size > 0 && size == capacity / 4) {
		resize_capacity(size / 2);
	}
}

void Vector::resize_capacity(int c) {
	int *t = a;
	a = new int[c];
	size = min(c, size);
	for (int i = 0; i < size; i++) {
		a[i] = t[i];
	}
	delete t;
	capacity = c;
}