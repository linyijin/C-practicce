#include<iostream>
using namespace std;
char *buildstr(char c, int len)
{
	char *ptr = new char[len + 1];
	ptr[len] = '\n';
	while (len--)
	{
		ptr[len] = c;
	}
	return ptr;
}
int main()
{
	int len = 5;
	char c;
	cin >> c;
	char *p;
	p = buildstr(c, len);
	cout << p << endl;
	delete[] p;
	return 0;
}