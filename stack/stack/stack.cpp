#include "stack.h"
void Stack::reSet() {
	for (int i = 0; i < 10; i++)
		arr[i] = 0;
	size = 0;
}
bool Stack::push(int x) {
	if (size==10)
		return false;
	arr[size - 1] = x;
	return true;
}
int  Stack::pop() {
	if (size == 0)
		return -1;
	return arr[size - 1];
}
int getTop()
