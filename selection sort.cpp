for (int i = 0; i < v.size(); i++) {
	swap(v[i], *min_element(v.begin() + i, v.end()));
}