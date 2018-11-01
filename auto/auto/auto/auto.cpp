#include<iostream>
<<<<<<< HEAD
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
=======
#include<vector>
using namespace std;
int main()
{
	vector<double> score;
	auto p = score.begin();
	float da = 31415926.53589;
	float fb = 0.01;
	da += fb;
	cout << da << endl;
>>>>>>> c7b3aa74aee2984e5a2dc39787170f0df00a0371
	return 0;
}