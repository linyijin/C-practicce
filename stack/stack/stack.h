#pragma once
#include<iostream>
class Stack {
public:
	bool push(int x);
	int pop();
	int getTop();
	int getSize();
	void reSet();
private:
	int top;
	int arr[10];
	int size;
};