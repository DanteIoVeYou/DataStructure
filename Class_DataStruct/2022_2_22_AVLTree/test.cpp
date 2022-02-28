#define _CRT_SECURE_NO_WARNINGS 1

#include "AVLTree.h"
void Test2() {
	AVLTree<int, int> tree;
	//int a[] = { 16,3,7,11,9,26,18,14,15 }; 
	int a[] = { 4,2,6,1,3,5,15,7,16,14 };
	for (auto e : a) {
		tree.Insert(make_pair(e, e));
	}
	cout << "isBalance: " << tree.isBalance() << endl;
}
void Test1() {
	AVLTree<int, int> tree;
	tree.Insert(make_pair(1, 1));
	tree.Insert(make_pair(2, 12));
	tree.Insert(make_pair(3, 13));
	tree.Insert(make_pair(4, 13));
	tree.Insert(make_pair(5, 13));
	tree.Insert(make_pair(6, 13));
	tree.Insert(make_pair(8, 13));
	tree.Insert(make_pair(90, 13));
	tree.Insert(make_pair(822, 13));
	tree.Insert(make_pair(23, 13));

	cout << "isBalance: " << tree.isBalance() << endl;
}
int main() {
	//Test1();
	Test2();

	return 0;
}