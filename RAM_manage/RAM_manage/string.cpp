#include "string.h"
#include<cstring>

using std::cout;

int stringBad::num_strings = 0;//在文件中初始化，不能在头文件中初始化，会导致引用头文件时初始化出多个副本

stringBad::stringBad(const char *s)
{
	len = std::strlen(s);
	str = new char[len + 1];//提供内存	
	strcpy_s(str,len+1, s);
	num_strings++;
	cout << num_strings << ":\"" << str << "\"object create\n";
}
stringBad::stringBad()
{
	len = 4;
	str = new char[4];
	strcpy_s(str,4, "C++");
	num_strings++;
	cout << num_strings << ":\"" << str << "\"default object created\n";
}
stringBad::stringBad(const stringBad &s)//定义一个显式的复制函数
{
	num_strings++;
	len = s.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, s.str);
	cout << num_strings << ":\"" << str << "\"object created\n";
}
stringBad::~stringBad()
{
	cout << "objdect delete";
	--num_strings;
	cout << num_strings << "left\n";
	delete [] str;
}
std::ostream & operator<<(std::ostream &os, const stringBad &st)
{
	os << st.str;
	return os;
}
stringBad &stringBad::operator=(const stringBad &s)
{
	if (this == &s)//地址相同
		return *this;
	delete[]str;
	len = s.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, s.str);
	return *this;
}
void stringBad::change(std::vector<int> &a)
{
	std::vector<int> *b=&a;
	b->push_back(1);
	b[1]= 1;
}