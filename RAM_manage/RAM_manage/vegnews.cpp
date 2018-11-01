#include<iostream>
#include<vector>
using std::cout;

#include "string.h"
void callme1(stringBad &);//引用
void callme2(stringBad);//非引用

int main()
{/*
	using std::endl;
	{
		stringBad name;
		char temp[40];
		std::cin.getline(temp, 40);
		name = temp;
		cout << "string an inner block\n";
		stringBad headline1("celery stalks at midnight");
		stringBad headline2("lettuce prey");
		stringBad sports("spinach leave bowl for dollar");
		cout<<"headline1: "<<headline1<< endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;
		callme1(headline1);
		cout << "headline1:" << headline1 << endl;
		callme2(headline2);//按值传递，离开该函数会调用析构
		cout << "headline2" << headline2 << endl;//产生乱码
		cout << "initialize one object to another:\n";
		stringBad sailor = sports;//=stringBad sailor=stringBad(sports),使用了构造函数原型：stringBad(const stringBad &),未定义的构造函数，由编译器自动生成，故不会对对象计数+1
		cout << "sailor:" << sailor << endl;
		cout << "assign one object to another:\n";
		stringBad knot;
		knot = headline1;
		cout << "knot:" << knot << endl;
		cout << "exiting the block.\n";

	}//析构里面的所有对象，顺序与构造相反：knot->sailor->sport
	cout << "end of main()\n";//执行不到就会自动退出，因为对象计数已经为负
	*/
	stringBad hello;
	std::vector<int> a(10,0);
	hello.change(a);
	for(auto &iter :a)
		std::cout << iter << std::endl;
	system("pause");
}
void callme1(stringBad &rsb)
{
	cout << "string pass by reference: \n";
	cout << "  \"" << rsb << "\"\n";
}
void callme2(stringBad sb)
{
	cout << "string pass by value:\n";
	cout << " \"" << sb << "\"\n";
}