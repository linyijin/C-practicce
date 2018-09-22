#include<iostream>
#include<CString>
#include "String.h"
using namespace std;
String::String(const char *s) 
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy_s(str,len+1, s);
}
String::String() 
{
	len = 0;
	str = new char[len + 1];
	str[0] = '0';
}
String::~String()
{
	cout << "该字符组将被清除" << str << endl;
	delete[] str;
}
ostream & operator<<(ostream & os, const String &st)
{
	os << st.str;
	return os;
}