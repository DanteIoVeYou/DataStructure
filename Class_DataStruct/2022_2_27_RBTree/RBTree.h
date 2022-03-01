#pragma once
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
enum Color{
	BLACK,
	RED
};
template<class K, class V>
struct RBTreeNode {
	pair<K, V> _kv;
	Color _color;
	RBTreeNode<K, V>* _parent;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode(const pair<K, V>& kv)
		:_parent(nullptr)
		,_left(nullptr)
		,_right(nullptr)
		,_color(RED)
		,_kv(kv)
	{}
};
template<class K, class V>
class RBTree {
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(nullptr)
	{}
	void RotateR(Node* parent) {
		Node* pparent = parent->_parent;
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
	}
	bool Insert(const pair<K, V>& kv) {
		if (_root == nullptr) {
			_root = new Node(kv);
			_root->_color = BLACK;
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
		cur->_color = RED;
		cur->_parent = parent;
		if (cur->_kv.first < parent->_kv.first) {
			parent->_left = cur;
		}
		else {
			parent->_right = cur;
		}

		// ���������

		// 1.��������Ľڵ�ĸ����Ǻ�ɫ������Ҫ����
		// DO NOTHING

		// 2.��������Ľڵ�ĸ����Ǻ�ɫ������Ҫ���������
		// 2.1.curΪ�죬parentΪ�죬grandfatherΪ�ڣ�uncleΪ��
		// 2.2.curΪ�죬parentΪ�죬grandfatherΪ�ڣ�uncle������
		// 2.3.curΪ�죬parentΪ�죬grandfatherΪ�ڣ�uncleΪ��
		while (parent && parent->_color == RED) {
			Node* grandfather = parent->_parent;
			// ���
			if (parent == grandfather->_left) {
				Node* uncle = grandfather->_right;
				// ���һ�� uncle������Ϊ�죬ֻ��Ҫ��ɫ
				if (uncle && uncle->_color == RED) {
					parent->_color = uncle->_color = BLACK;
					grandfather->_color = RED;
					cur = grandfather;
					parent = grandfather->_parent;
				}
				// �����+���� uncle�����ڻ���Ϊ�ڣ���ת+��ɫ
				else {
					// ������� ����+��ɫ
					if (cur == parent->_left) {
						RotateR(grandfather);
						grandfather->_color = RED;
						parent->_color = BLACK;
					}
					// ������� ˫��+��ɫ
					else {
						RotateL(parent);
						RotateR(grandfather);
						cur->_color = BLACK;
						grandfather->_color = RED;
					}
					break;
				}
			}
			// �ұ�
			else {
				Node* uncle = grandfather->_left;
				// ���һ�� uncle������Ϊ�죬ֻ��Ҫ��ɫ
				if (uncle && uncle->_color == RED) {
					uncle->_color = parent->_color = BLACK;
					grandfather->_color = RED;
					cur = grandfather;
					parent = grandfather->_parent;
				}
				// �����+���� uncle�����ڻ���Ϊ�ڣ���ת+��ɫ
				else {
					// ������� ����+��ɫ
					if (cur == parent->_right) {
						RotateL(grandfather);
						parent->_color = BLACK;
						grandfather->_color = RED;
					}
					// ������� ˫��+��ɫ
					else {
						RotateR(parent);
						RotateL(grandfather);
						cur->_color = BLACK;
						grandfather->_color = RED;
					}
					break;
				}
			}
		}
		_root->_color = BLACK;
		return true;
	}
	////////////////////////////////////////////////////isBalance()//////////////////////////////////////////
	bool isBalance() {
		if (!_root) {
			return true;
		}
		if (_root->_color == RED) {
			cout << "���ڵ��Ǻ죬Υ������1" << endl;
			return false;
		}
		return CheckDoubleRED(_root) && CheckBlackNum(_root, 0, GetBlackNum(_root));
	}
	bool CheckDoubleRED(Node* root) {
		if (root == nullptr) {
			return true;
		}
		if (root->_color == RED && root->_parent->_color == RED) {
			return false;
		}
		return 1 && CheckDoubleRED(root->_left) && CheckDoubleRED(root->_right);
	}
	bool CheckBlackNum(Node* root, int num, int BlackNum) {
		if (root == nullptr) {
			return num == BlackNum;
		}
		if (root->_color == BLACK) {
			return CheckBlackNum(root->_left, num + 1, BlackNum) && CheckBlackNum(root->_right, num + 1, BlackNum);
		}
		else {
			return CheckBlackNum(root->_left, num, BlackNum) && CheckBlackNum(root->_right, num, BlackNum);
		}
	}
	int GetBlackNum(Node* root) {
		int cnt = 0;
		while (root) {
			if (root->_color == BLACK) {
				cnt++;
			}
			root = root->_left;
		}
		return cnt;
	}
	void _Inorder(Node* root) {
		if (root == nullptr) {
			return;
		}
		_Inorder(root->_left);
		cout << "key: " << root->_kv.first << " value: " << root->_kv.second << " color: " << root->_color << endl;
		_Inorder(root->_right);
	}
	void Inorder() {
		_Inorder(_root);
	}
	////////////////////////////////////////////////////isBalance()//////////////////////////////////////////
private:
	Node* _root;
};