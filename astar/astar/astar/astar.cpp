#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
static vector<vector<int>> costmap_(80, vector<int>(80,0));

struct location {
	int x;
	int y;
	int F;
	bool closed=false;
	bool openiing = false;//设置两个标志位
};
typedef location loc ;
struct greater1
{
	bool operator()(const loc& a, const loc& b) const
	{
		return a.F <b.F;
	}
};
//return 8 near neiboghr
vector<loc> node8(const loc point)
{
	vector<loc> node8;
	node8.clear();
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (point.x + i >= 80 || point.x + i < 0 || point.y + j >= 80 || point.y + j < 0)//越界判断
				continue;
			if ((i != 0) || (j != 0))
			{
				loc nbx;
				nbx.x = point.x+i;
				nbx.y = point.y+j;
				node8.push_back(nbx);
			}
				
		}
	}
	return node8;
}
vector<loc> node4(const loc point)
{
	vector<loc> node4;
	node4.clear();
	
	return node4;
}
//calculate for astar path
bool astar(const int start_x, const int start_y, const int end_x, const int end_y)
{
	vector<loc> open;
	vector<loc> close;
	loc start_loc;
	loc end_loc;
	start_loc.x = start_x;
	start_loc.y = start_y;
	start_loc.F = 0;
	end_loc.x = end_x;
	end_loc.y = end_y;
	open.clear();
	open.push_back(start_loc);
	start_loc.openiing = true;
	loc current = open[0];
	while (!open.empty())
	{
		current = open[0];
		cout << "top=" << current.x << ' ' << current.y << ' ' << current.F << endl;//log
		if (current.x == end_loc.x && current.y == end_loc.y)
		{
			cout << "reach the end" << endl;
			close.push_back(end_loc);
			break;
		}
		pop_heap(open.begin(), open.end(), greater1());//对open进行数值F排列
		open.pop_back();//删除了栈顶元素
		costmap_[current.x][current.y]=0;//记录在地图上
		vector<loc> nbx=node8(current);//寻找当前位置八近邻
		vector<loc>::iterator iter;
		for (iter = nbx.begin(); iter != nbx.end(); iter++)
		{
			if (costmap_[iter->x][iter->y] == 8)
				continue;
			else if (costmap_[iter->x][iter->y]==4);
			else if (costmap_[iter->x][iter->y]==3)
			{
				int G = abs(current.x - start_x) + abs(current.y - start_y);
				int H= abs(iter->x - end_x) + abs(iter->y - end_y);
				vector<loc>::iterator iter_2;
				for (iter_2 = open.begin(); iter_2 != open.end(); iter_2++)//去open中取出该值的权重
				{
					if ((iter_2->x == iter->x) && (iter_2->y == iter->y))
					{
						if (iter_2->F > (G + H + 1))//判断是否能缩短近邻的路径
						{
							iter_2->F = (G + H + 1);
						}
						break;
					}
						
				}
				
				
				
			}
			else 
			{
				iter->F = abs(iter->x - start_x) + abs(iter->y - start_y) + abs(iter->x - end_x) + abs(iter->y - end_y);
				costmap_[iter->x][iter->y] = 3;
				open.push_back(*iter);//将邻居放入open中
			}
		}
		//current.closed = true;//置位标志位
		costmap_[current.x][current.y] = 4;//记录在地图上
		close.push_back(current);//放入close,不再计算
		cout << "close is" << endl;
		for (iter = close.begin(); iter != close.end(); iter++)
		{

			cout << iter->x << ' ' << iter->y << ' ' << iter->F<<' ';
			cout << "closed" << endl;
		}
		sort(open.begin(), open.end(), greater1());//对open中排序
		cout << "open is" << endl;
		for (iter = open.begin(); iter != open.end(); iter++)
		{

			cout << iter->x << ' ' << iter->y << ' ' << iter->F << ' ';
			cout << "open" << endl;
		}
	}
	cout << "calculate over" << endl;
	//测试

	//输出path
	
	loc search_point;
	search_point = end_loc;
	
	while (search_point.x != start_x || search_point.y != start_y)
	{
		cout << "plan path" << endl;
		cout << "search_point" << search_point.x << ' ' << search_point.y << endl;
		int min = 10e6;
		vector<loc> nbx = node8(search_point);
		vector<loc>::iterator iter;
		for (iter = nbx.begin(); iter != nbx.end(); iter++)
		{
			if (costmap_[iter->x][iter->y]==4)
			{
				vector<loc>::iterator iter_2;
				for (iter_2 = close.begin(); iter_2 != close.end(); iter_2++)//去close中取出该值的权重
				{
					if ((iter_2->x == iter->x) && (iter_2->y == iter->y))
					{
						if (iter_2->F < min)
						{
							search_point.x = iter->x;
							search_point.y = iter->y;
							min = iter_2->F;
						}
					}

				}

			}
		}
		costmap_[search_point.x][search_point.y] = 1;
	}
	return true;
}

int main()
{
	int start_x, start_y;
	int end_x, end_y;
	cout << "empty map" << endl;
	for (int i = 0; i < 20; i++)
		costmap_[i][12] = 8;
	for (int i = 0; i < 20; i++)
		costmap_[i][13] = 8;
	cout << "empty map" << endl;
	for (int i = 5; i < 60; i++)
		costmap_[i][30] = 8;
	for (int i = 5; i < 60; i++)
		costmap_[i][31] = 8;
	for (int i = 0; i < 80; i++)
	{

		for (int j = 0; j < 80; j++)
			cout << costmap_[i][j]<<' ';
		cout << endl;
	}
	cout << "enter start point" << endl;
	cin >> start_x;
	cin >> start_y;
	costmap_[start_x][start_y] = 2;
	cout << "enter end point" << endl;
	cin >> end_x;
	cin >> end_y;
	costmap_[end_x][end_y] = 2;
	if (astar(start_x, start_y, end_x, end_y))
	{
		cout << "calculate success" << endl;
	}
	costmap_[start_x][start_y] = 2;
	costmap_[end_x][end_y] = 2;
	for (int i = 0; i < 80; i++)
	{

		for (int j = 0; j < 80; j++)
			cout << costmap_[i][j] << ' ';
		cout << endl;
	}	return 0;
}