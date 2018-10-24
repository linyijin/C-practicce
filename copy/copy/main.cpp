#include <iostream>
#include "Astar.h"
using namespace std;

int main()
{
	vector<vector<int>> maze(80, vector<int>(80, 0));
	for (int i = 0; i < 20; i++)
		maze[i][12] = 1;
	for (int i = 0; i < 20; i++)
		maze[i][13] = 1;
	cout << "empty map" << endl;
	for (int i = 5; i < 60; i++)
		maze[i][30] = 1;
	for (int i = 5; i < 60; i++)
		maze[i][31] = 1;
	Astar astar;
	astar.InitAstar(maze);

	//设置起始和结束点
	cout << "enter the start" << endl;
	int start_x, start_y;
	cin >> start_x;
	cin >> start_y;
	Point start(start_x,start_y);
	cout << "enter the end" << endl;
	int end_x, end_y;
	cin >> end_x;
	cin >> end_y;
	Point end(end_x,end_y);
	//A*算法找寻路径
	list<Point *> path = astar.GetPath(start, end, false);
	//打印
	for (auto &p : path)
		cout << '(' << p->x << ',' << p->y << ')' << endl;
	for (auto &p : path)
		maze[p->x][p->y] = 6;
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			std::cout << maze[i][j] << " ";
		}
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}