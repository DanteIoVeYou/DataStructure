#define _CRT_SECURE_NO_WARNINGS 1
#include "RBTree.h"
void Test2() {
	int N = 1000;
	vector<int> random;
	random.reserve(N);
	srand(time(0));
	for (int i = 0; i < N; i++) {
		random.push_back(rand());
	}
	RBTree<int, int> tree;
	for (auto e : random) {
		tree.Insert(make_pair(e, e));
	}
	tree.Inorder();
	cout << "isBalance: " << tree.isBalance() << endl;
}
void Test1() {
	RBTree<int, int> tree;
	int a[] = { 4,2,6,1,3,5,15,7,16,14 };
	for (auto e : a) {
		tree.Insert(make_pair(e, e));
	}
	cout << "isBalance: " << tree.isBalance() << endl;
}
int main() {
	Test2();

	return 0;
}