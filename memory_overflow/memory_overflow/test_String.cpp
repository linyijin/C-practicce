#include<iostream>
#include "String.h"
#include<stdlib.h>
using namespace std;
void show_right(const String &);
void show_String(const String);
int main() 
{
	String test1("第一个示例");
	String test2("第二个示例");
	String test3("第三个示例");
	String test4("第四个示例");
	cout << test1 << endl;
	cout << test2 << endl;
	cout << test3 << endl;
	String *String1 = new String(test1);//默认构造（返回值为对象本身），string1和test1指向同一段内存
	cout << *String1 << endl;//正常输出
	delete String1;//调用析构函数
	cout << "test1=" << test1 << endl;//test1中的字符已经被删除
	cout << "使用正确函数" << endl;
	show_right(test2);//仅复制内容，不指向同一段内存
	cout << "使用错误函数" << endl;
	show_String(test2);//默认构造（参数为对象本身），指向同一段内存
	cout << "test2=" << test2 << endl;
	String String2(test3);//深度复制
	cout << "String2=" << String2 << endl;
	String String3;
	String3 = test4;//=运算符重载
	cout << "String3=" << String3 << endl;
	cout << "程序结束，解析函数将被调用" << endl;
	return 0;
}
void show_right(const String &a) //仅引用地址
{
	cout << a << endl;
}
void show_String(const String a) //按值传递
{
	cout << a << endl;
}
