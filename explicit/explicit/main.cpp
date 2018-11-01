#include<iostream>
#include "class.h"
using std::cout;
using std::endl;
int main()
{
	A a(1, 2);
	//a = A(1.1);
	a.show();
	//std::cout << a.num << std::endl;
	double p = a;
	cout << p << endl;
	system("pause");
	return 0;
}