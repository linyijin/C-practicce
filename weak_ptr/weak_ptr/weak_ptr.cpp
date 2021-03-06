// weak_ptr.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<memory>
#include<string>
int main()
{
	int* ptr = new int(10);
	int* ref = ptr;
	delete ptr;
	std::shared_ptr<int> sptr;
	sptr.reset(new int);
	*sptr = 10;
	std::weak_ptr<int> weak1 = sptr;
	sptr.reset(new int);
	*sptr = 5;
	std::weak_ptr<int> weak2 = sptr;
	if (auto tmp = weak1.lock())
		std::cout << *tmp << '\n';
	else
		std::cout << "weak1 is expired\n";
	if (auto tmp = weak2.lock())
		std::cout << *tmp << '\n';
	else
		std::cout << "weak2 is expired\n";
}



