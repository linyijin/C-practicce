#pragma once
#ifndef CLASS_H
#define CLASS_H
#include<iostream>
class A {
	float num;
	float angle;
public:
	A();
	 A(float b,float a);
	//~A();
	void show();
	operator long() const;
};
void A::show()
{
	std::cout << num <<std::endl;
}
A::A(float b,float a):num(b) 
{

}
A::operator long() const
{
	return num;
}
#endif