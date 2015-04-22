class BinarySearchTree {
	struct Node;
	Node *root;
	void print_preorder_until(Node *n);
	void print_inorder_until(Node *n);
	void print_postorder_until(Node *n);
public:
	BinarySearchTree();
	~BinarySearchTree();
	void insert_incorrect(int);
	void insert(int);
	void print_preorder();
	void print_postorder();
	void print_inorder();
	void print_levelorder();
	void remove(int);
};

struct BinarySearchTree::Node {
	Node *l;
	Node *r;
	int v;
};

BinarySearchTree::BinarySearchTree() {
	root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {

}

void BinarySearchTree::insert_incorrect(int nv) {
	Node *t = root;
	while (t != nullptr) {
		if (nv > t->v) {
			t = t->r;
		} else {
			t = t->l;
		}
	}
	// at this moment, t doesn't point to anyway (NULL), so it has no information
	// so we need to use double pointer to also know the info of the last pointer which pointer to null
	t = new Node(); // this is incorrect since it just change what t points to
	t->l = nullptr;
	t->r = nullptr;
	t->v = nv;
}

void BinarySearchTree::insert(int nv) {
	Node **t = &root; // make a pointer of correct type (pointer to pointer)
	while (*t != nullptr) { // *t == root, t == &root
		if (nv > (*t)->v) {
			t = &((*t)->r);
		} else {
			t = &((*t)->l);
		}
	}
	*t = new Node();
	(*t)->l = nullptr;
	(*t)->r = nullptr;
	(*t)->v = nv;
}

void BinarySearchTree::print_preorder_until(Node *t) {
	if (t == nullptr) {
		return;
	}
	cout << t->v << '\n';
	print_preorder_until(t->l);
	print_preorder_until(t->r);
}

void BinarySearchTree::print_preorder() {
	print_preorder_until(root);
}

void BinarySearchTree::print_inorder_until(Node *t) {
	if (t == nullptr) {
		return;
	}
	print_preorder_until(t->l);
	cout << t->v << '\n';
	print_preorder_until(t->r);
}

void BinarySearchTree::print_inorder() {
	print_preorder_until(root);
}

void BinarySearchTree::print_postorder_until(Node *t) {
	if (t == nullptr) {
		return;
	}
	print_preorder_until(t->l);
	print_preorder_until(t->r);
	cout << t->v << '\n';
}

void BinarySearchTree::print_postorder() {
	print_preorder_until(root);
}

void BinarySearchTree::print_levelorder() {
	if (root == nullptr) {
		return;
	}
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node *t = q.front();
		cout << t->v << endl;
		q.pop();
		if (t->l != nullptr) {
			q.push(t->l);
		}
		if (t->r != nullptr) {
			q.push(t->r);
		}
	}
}

void binary_search_tree_testing() {
	BinarySearchTree bst;
	bst.insert(1);
	bst.insert(5);
	bst.insert(9);
	bst.insert(2);
	bst.insert(6);
	bst.insert(7);
}