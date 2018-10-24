#include<cmath>
#include<iostream>
#include<fstream>
#include<algorithm>
#include"astar.h"


std::vector<std::vector<int>> costmap_(80, std::vector<int>(80, 0));
int main()
{
	int start_x, start_y;
	int end_x, end_y;
	std::cout << "empty map" << std::endl;
	for (int i = 0; i < 80; i++)
	{

		for (int j = 0; j < 80; j++)
			std::cout << costmap_[i][j] << ' ';
		std::cout << std::endl;
	}
	Astar astar;
	std::cout << "enter start point" << std::endl;
	std::cin >> start_x;
	std::cin >> start_y;
	costmap_[start_x][start_y] = 2;
	std::cout << "enter end point" << std::endl;
	std::cin >> end_x;
	std::cin >> end_y;
	Point start(start_x, start_y);
	Point end(end_x, end_y);
	astar.initAstar(costmap_);
	std::list<Point *>path_=astar.getPath(start, end);
	for (auto &p : path_)
		costmap_[p->x][p->y] = 1;
	costmap_[end_x][end_y] = 2;
	costmap_[start_x][start_y] = 2;
	std::cout << "path size is" << path_.size() << std::endl;
	int map[80][80];//Êä³öÓÃ
	std::ofstream OutFile;
	OutFile.open("map.txt");
	for (int i = 0; i < 80; i++)
	{
		OutFile << '{';
		for (int j = 0; j < 80; j++)
		{
			map[i][j] = costmap_[i][j];
			OutFile << map[i][j]<<',';
			std::cout << costmap_[i][j] << ' ';
		}
		std::cout << std::endl;
		OutFile << '}'<<','<<std::endl;
	}	
	OutFile.close();
	system("PAUSE");
	return 0;
}