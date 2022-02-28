#pragma once
#include <iostream>
#include <assert.h>
using namespace std;


template<class K, class V>
struct AVLTreeNode{
	pair<K, V> _kv;
	int _bf; // balance factor = h(subRight) - h(subLeft)
	AVLTreeNode<K, V>* _parent;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;

	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_bf(0)
		,_parent(nullptr)
		,_left(nullptr)
		,_right(nullptr)
	{}
};


template<class K, class V>
class AVLTree {
	typedef AVLTreeNode<K, V> Node;
 public:
	AVLTree()
		:_root(nullptr)
	{}
	void RotateR(Node* parent) {
		Node* pparent = parent-> _parent;
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		subL->_right = parent;
		if (subLR) {
			subLR->_parent = parent;
		}
		parent->_parent = subL;

		if (parent == _root) {
			_root = subL;
			subL->_parent = nullptr;
		}
		else {
			subL->_parent = pparent;
			if (pparent->_left == parent) {
				pparent->_left = subL;
			}
			else {
				pparent->_right = subL;
			}
		}

		subL->_bf = parent->_bf = 0;
		
	}
	void RotateL(Node* parent) {
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* pparent = parent->_parent;

		parent->_right = subRL;
		subR->_left = parent;

		if (subRL) {
			subRL->_parent = parent;
		}
		parent->_parent = subR;

		if (parent == _root) {
			_root = subR;
			subR->_parent = nullptr;
		}
		else {
			subR->_parent = pparent;
			if (pparent->_left == parent) {
				pparent->_left = subR;
			}
			else {
				pparent->_right = subR;
			}
		}

		subR->_bf = parent->_bf = 0;
	}

	// X
	//   X
	// X
	void RotateRL(Node* parent) {
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		RotateR(parent->_right);
		RotateL(parent);

		if (bf == -1) {
			subR->_bf = 1;
			parent->_bf = subRL->_bf = 0;
		}
		else if (bf == 1) {
			parent->_bf = -1;
			subR->_bf = subRL->_bf = 0;
		}
		else if (bf == 0) {
			parent->_bf = subR->_bf = subRL->_bf = 0;
		}
		else {
			assert(false);
		}
	}

	//  X
	//X
	//  X
	void RotateLR(Node* parent) {
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotateL(parent->_left);
		RotateR(parent);

		if (bf == -1) {
			parent->_bf = 1;
			subLR->_bf = subL->_bf = 0;
		}
		else if (bf == 1) {
			subL->_bf = -1;
			subLR->_bf = parent->_bf = 0;
		}
		else if (bf == 0) {
			parent->_bf = subL->_bf = subLR->_bf = 0;
		}
		else {
			assert(false);
		}
	}
	bool Insert(const pair<K, V>& kv) {
		if (_root == nullptr) {
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) {
			if (kv.first < cur->_kv.first) {
				parent = cur;
				cur = cur->_left;
			}
			else if (kv.first > cur->_kv.first) {
				parent = cur;
				cur = cur->_right;
			}
			else {
				return false;
			}
		}
		cur = new Node(kv);
		if (kv.first < parent->_kv.first) {
			parent->_left = cur;
			cur->_parent = parent;
		}
		else {
			parent->_right = cur;
			cur->_parent = parent;
		}
		// above insert, below judge bf
		while (parent != nullptr) {
			// 1.update bf
			if (cur == parent->_left) {
				--parent->_bf;
			}
			else {
				++parent->_bf;
			}

			if (parent->_bf == 0) {
				break;
			}
			else if(parent->_bf == 1 || parent->_bf == -1) {
				cur = parent;
				parent = parent->_parent;
			}
			else if(parent->_bf == 2 || parent->_bf == -2) {
				if (parent->_bf == -2 && cur->_bf == -1) {
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1) {
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1) {
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1) {
					RotateRL(parent);
				}
				break;
			}
			else {
				assert(false);
			}
		}
		return true;
	}

	int Height(Node* root) {
		if (root == nullptr) {
			return 0;
		}
		else {
			return 1 + max(Height(root->_left), Height(root->_right));
		}
	}
	bool _isBalance(Node* root) {
		if (root == nullptr) {
			return true;
		}

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		if (rightHeight - leftHeight != root->_bf) {
			cout << "bf wrong:" << root->_kv.first << endl;
		}

		return abs(leftHeight - rightHeight) < 2 && _isBalance(root->_left) && _isBalance(root->_right);

	}
	bool isBalance() {
		return _isBalance(_root);
	}
private:
	Node* _root;
};