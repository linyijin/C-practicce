#include<iostream>
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
	return 0;
}