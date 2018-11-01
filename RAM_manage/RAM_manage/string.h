#pragma once
#ifndef  STRING_H
#define STRING_H
#include<iostream>
#include<vector>
class stringBad 
{
private:
	char *str;//定义了一个指针,字符串本身并不具备地址
	int len;
	static int num_strings;//静态成员共享地址，多个对象中的num_strings都是同一个地址上的变量
public:
	stringBad(const char *s);
	stringBad(const stringBad &s);
	stringBad();
	~stringBad();
	stringBad &operator=(const stringBad &s);
	void change(std::vector<int> &a);//引用一个地址过来
	friend bool operator<(const stringBad &s1, const stringBad &s2);
	friend std::ostream & operator<<(std::ostream &os, const stringBad &st);
};
#endif // ! STRING_H
