for (int i = 0; i < v.size(); i++) {
	swap(v[i], v[rand() % (i + 1)]);
}