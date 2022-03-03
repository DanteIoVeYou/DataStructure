#pragma once
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
namespace imdanteking
{
	template<class T>
	class stack {
	public:
		stack()
		{}
		~stack()
		{}
		stack(const stack& st) {
			_v(st._v);
		}
		void push(T data) {
			_v.push_back(data);
		}
		void pop() {
			assert(!empty());
			_v.pop_back();
		}
		const T& top() {
			assert(!empty());
			return _v.back();
		}
		bool empty() {
			return _v.empty();
		}
		void swap(stack st) {
			st._v.swap(_v);
		}
		size_t size()const {
			return _v.size();
		}
	private:
		vector<T> _v;
	};


	void Test1() {
		stack<int> st1;
		cout << st1.empty() << endl;
		st1.push(1);
		cout << "size: " << st1.size() << endl;
		st1.push(2);
		st1.push(3);
		st1.push(4);
		st1.push(5);
		st1.push(6);
		cout <<"size: " << st1.size() << endl;
		while (!st1.empty()) {
			cout << st1.top() << endl;
			st1.pop();
		}
		cout << st1.empty() << endl;
		cout << "size: " << st1.size() << endl;

	}
}