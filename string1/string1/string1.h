#pragma once
#ifndef STRING1_H
#define STRING1_H
#include<iostream>
using std::ostream;
using std::istream;

class String {
private:
	char *str;
	int len;
	static int num_string;
	static const int CINLIM = 80;
public:
	String(const char *s);
	String();
	String(const String &);
	~String();
	int length() const { return len; }

	String &operator=(const String &);//对象引用
	String &operator=(const char *); //一段字符地址
	char & operator[](int i);//引用下标
	const char &operator[](int i) const;//值下标

	friend bool operator <(const String &st, const String &st2);
	friend bool operator >(const String &st1, const String &st2);
	friend bool operator ==(const String &st1, const String &st2);
	friend ostream &operator <<(ostream &os,const String &st);
	friend istream &operator >>(ostream &os, const String &st);

	static int HowMany();
};
#endif // !STRING1_H
