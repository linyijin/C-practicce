// practice.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct Item {
	int x;
	int y;
	float theta;
};
	T *operator[](size_t i);
	void assign(size_t i, auto_ptr<T> &p);
	void assign_direct(size_t i, T *p);
	void Push_back(auto_ptr<T> &p);
	auto_ptr<T> Pop_back();
public:
	typedef auto_iterator<T> iterator;
	iterator begin() { return _arr; };
	iterator end() { return _arr + _end;  };
template <class T>//定制一个模板，模板内各数据参数待定
class auto_vector {
public:
	explicit auto_vector(size_t capacity = 0);//构造函数
	T *const operator[](size_t i) const;
private:
	void grow(size_t reCapacity);
	auto_ptr<T> *_arr;
	size_t capacity;
	size_t _end;
};
template <class T>
auto_vector::assign(size_t i, auto_ptr<T> &p) {
	_arr[i] = p;//直接对数组赋值
}
template<class T>
auto_vector::T *operator[](size_t i) {
	return _arr[i].get();
}
template<class T>
class auto_iterator :public iterator<random_access_iterator_tag, T *>
{
public:
	auto_iterator() :_pp(0) {};
	auto_iterator(auto_ptr<T> *pp) :_pp(pp) {};
	bool operator !=(auto_iterator<T>const &it)const { return it._pp != _pp; };
	auto_iterator operator ++() { return ++_pp; };
	T *operator *() { return _pp->get(); };
private:
	auto_ptr<T> *_pp;
};

void main() {
	vector<auto_ptr<Item>> auto_vector;
	auto_ptr<Item> item = auto_vector[0];
}


