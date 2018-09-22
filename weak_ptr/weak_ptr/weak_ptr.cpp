// weak_ptr.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<memory>
#include<string>
int main()
{
	try {
		std::shared_ptr<std::string> sp(new std::string("hello world"));
		std::weak_ptr<std::string> wp = sp;
		sp.reset();
		std::cout << wp.use_count() << std::endl << wp.expired() << std::endl;
		std::shared_ptr<std::string> p(wp);
	}
	catch(const std::exception & e){
		std::cerr << "exception" << e.what() << std::endl;
	}
}

