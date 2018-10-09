#include<iostream>
#include<cmath>
using namespace std;
struct rec {
	double x;
	double y;
};
struct polar {
	double distance;
	double angle;
};
int main()
{
	rec r;
	polar p;
	cout << "please enter the x,y" << endl;
	while (cin >> r.x >> r.y);
	p.distance = sqrt(pow(r.x,2)+pow(r.y,2));
	p.angle = atan2(r.y, r.x);
	cout << p.distance << ' ' << p.angle << endl;
	return 0;
}
