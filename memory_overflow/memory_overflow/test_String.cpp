#include<iostream>
#include "String.h"
#include<stdlib.h>
using namespace std;
void show_right(const String &);
void show_String(const String);
int main() 
{
	String test1("��һ��ʾ��");
	String test2("�ڶ���ʾ��");
	String test3("������ʾ��");
	String test4("���ĸ�ʾ��");
	cout << test1 << endl;
	cout << test2 << endl;
	cout << test3 << endl;
	String *String1 = new String(test1);//Ĭ�Ϲ��죨����ֵΪ��������string1��test1ָ��ͬһ���ڴ�
	cout << *String1 << endl;//�������
	delete String1;//������������
	cout << "test1=" << test1 << endl;//test1�е��ַ��Ѿ���ɾ��
	cout << "ʹ����ȷ����" << endl;
	show_right(test2);//���������ݣ���ָ��ͬһ���ڴ�
	cout << "ʹ�ô�����" << endl;
	show_String(test2);//Ĭ�Ϲ��죨����Ϊ��������ָ��ͬһ���ڴ�
	cout << "test2=" << test2 << endl;
	String String2(test3);//��ȸ���
	cout << "String2=" << String2 << endl;
	String String3;
	String3 = test4;//=���������
	cout << "String3=" << String3 << endl;
	cout << "�������������������������" << endl;
	return 0;
}
void show_right(const String &a) //�����õ�ַ
{
	cout << a << endl;
}
void show_String(const String a) //��ֵ����
{
	cout << a << endl;
}
