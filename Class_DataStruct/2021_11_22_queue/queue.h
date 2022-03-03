#pragma once
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

namespace imdanteking
{
	template <class T>
	class queue {
	public:
		queue() {}
		~queue() {}

		void push(const T& val) {
			_v.push_back(val);
		}
		void pop() {
			assert(!_v.empty());
			_v.erase(_v.begin());
		}
		const T& front() const {
			assert(!_v.empty());
			return _v.front();
		}
		const T& back() const {
			assert(!_v.empty());
			return _v.back();
		}
		bool empty() {
			return _v.size() == 0;
		}
		size_t size() {
			return _v.size();
		}
		void swap(queue q) {
			_v.swap(q._v);
		}
	private:
		vector<T> _v;
	};

	void Test1() {
		queue<int> q;
		q.push(1);
		q.push(2);
		cout << q.back() << endl;
		q.push(3);
		cout << q.back() << endl;
		q.push(4);
		q.push(5);
		cout << "size: " << q.size() << endl;
		cout << q.front() << endl;
		while (!q.empty()) {
			cout << "front: " << q.front() << endl;
			cout << "back: " << q.back() << endl;
			q.pop();
		}
		cout << "size: " << q.size() << endl;
	}
}
