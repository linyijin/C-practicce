#include<iostream>
#include<array>
#include<string>
const int season = 4;
const std::array<std::string, 4> sname = { "spring","summer","fall","winter" };
void fill(std::array<double, season> *pa);
void show(std::array<double, season> p);
int main()
{
	std::array<double, 4> expense;
	fill(&expense);
	show(expense);
	return 0;
}
void fill(std::array<double, season> *pa)
{
	using namespace std;
	for (int i = 0; i < season; i++) {
		cout << "enter " << sname[i] << " expense" << endl;
		cin >> (*pa)[i];
	}
}
void show(std::array<double, season> p)
{
	using namespace std;
	double total = 0.0;
	for (int i = 0; i < season; i++)
	{
		cout << sname[i] << "=$" << p[i] << endl;
		total += p[i];
	}
	cout << "total=" << total << endl;
}