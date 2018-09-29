#include<iostream>
#include<CString>
#include "String.h"
using namespace std;
String::String(const char *s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
}
String::String(const String &s) //ΪĬ�Ϲ���ʹ�����ã�����ǳ����
{
	len = s.len;
	str = new char(len+1);
	strcpy_s(str,len+1,s.str);
}
String::String() 
{
	len = 0;
	str = new char[len + 1];
	str[0] = '0';
}
String::~String()
{
	cout << "���ַ��齫�������" << str << endl;
	delete[] str;
}
ostream & operator<<(ostream & os, const String &st)
{
	os << st.str;
	return os;
}
String & String::operator=(const String& a)
{
	if (this == &a)
		return *this;
	delete[] str;
	len = a.len;
	str = new char[len + 1];
	strcpy_s(str,len+1, a.str);
	return *this;
}