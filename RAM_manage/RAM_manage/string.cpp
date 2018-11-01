#include "string.h"
#include<cstring>

using std::cout;

int stringBad::num_strings = 0;//���ļ��г�ʼ����������ͷ�ļ��г�ʼ�����ᵼ������ͷ�ļ�ʱ��ʼ�����������

stringBad::stringBad(const char *s)
{
	len = std::strlen(s);
	str = new char[len + 1];//�ṩ�ڴ�	
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
stringBad::stringBad(const stringBad &s)//����һ����ʽ�ĸ��ƺ���
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
	if (this == &s)//��ַ��ͬ
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