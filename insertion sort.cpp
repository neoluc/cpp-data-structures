for (int i = 0; i < v.size(); i++) {
	for (int j = i - 1; j >= 0; j--) {
		if (v[j] > v[j + 1]) {
			swap(v[j], v[j + 1]);
		}
	}
}