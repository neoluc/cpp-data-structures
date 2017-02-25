
int binary_search(vector<int> &v, int target) {
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {  // key point
        int mid = left + (right - left) / 2;  // key point
        if (v[mid] == target) {
            return mid;
        } else if (target < v[mid]) {
            right = mid - 1;  // key point
        } else {
            left = mid + 1;  // key point
        }
    }
    return -1;
}
