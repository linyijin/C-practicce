#pragma once
#ifndef  STRING_H
#define STRING_H
#include<iostream>
#include<vector>
class stringBad 
{
private:
	char *str;//������һ��ָ��,�ַ����������߱���ַ
	int len;
	static int num_strings;//��̬��Ա�����ַ����������е�num_strings����ͬһ����ַ�ϵı���
public:
	stringBad(const char *s);
	stringBad(const stringBad &s);
	stringBad();
	~stringBad();
	stringBad &operator=(const stringBad &s);
	void change(std::vector<int> &a);//����һ����ַ����
	friend bool operator<(const stringBad &s1, const stringBad &s2);
	friend std::ostream & operator<<(std::ostream &os, const stringBad &st);
};
#endif // ! STRING_H
