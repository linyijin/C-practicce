#include"astar.h"
#include<math.h>

void Astar::initAstar(std::vector<std::vector<int>> &map)//引用
{
	map_ = map;//将地图给予astar对象
}
int Astar::calG(Point *p, Point *start)//计算两点之间的G
{
	int externG= abs(start->x - p->x) + abs(start->y - p->y) == 1 ? lcost : tcost;
	int parentG= start->parent == NULL ? 0 :start->parent->G;//此处逻辑有问题，应该考虑的是当前点的G代价，而不是之前算过的parent
	//p->G = abs(start->x - p->x) + abs(start->y - p->y) == 1 ? lcost : tcost;
	//p->G=p->parent == NULL ? 0 : p->G + p->parent->G;//初始节点为0，其他节点为父节点+自身代价
	return externG+parentG;
}
int Astar::calH(Point *p, Point *end)
{
	//p->H = abs(end->x-p->x) + abs(end->y-p->y)*lcost;//曼哈顿距离
	return sqrt((double)(end->x - p->x)*(double)(end->x - p->x) + (double)(end->y - p->y)*(double)(end->y - p->y))*lcost;
	//return p->H;
}
int Astar::calF(Point *p)
{
	return p->F = p->G + p->H;
}
bool Astar::inMap(Point *p)
{
	if (p->x<0 || p->y<0 || p->x>map_[0].size() - 1 || p->y>map_[0].size() - 1 || map_[p->x][p->y]==8 )
		return false;
}
Point *Astar::isInList(Point *p, std::list<Point*> &q)
{
	for (auto iter : q)
	{
		if (iter->x == p->x && iter->y == p->y)
			return iter;
	}
	return NULL;
}
std::vector<Point *> Astar::nb8(Point *cur)
{
	std::vector<Point *> nbr;
	nbr.reserve(8);
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{

			if (i == 0 && j == 0)//跳过当前重合节点
				continue;
			
			int x = cur->x + i;
			int y = cur->y + j;
			Point *p = new Point(x,y);
			if (inMap(p) && !isInList(p,closelist))//选取在地图中，不在close中的八近邻,open创建了一个新的副本，要注意区别
			{
				nbr.push_back(new Point(p->x, p->y));
			}
			delete p;
		}
	}
	return nbr;
}
Point *Astar::getLeastPoint(std::list<Point*> p)
{
	if (!openlist.empty())
	{
		auto min = p.front();
		for (auto &iter : p)//??
		{
			if (iter->F < min->F)
				min = iter;
		}
		return min;
	}
	return NULL;
}
Point * Astar::findPath(Point start_, Point end_)
{
	openlist.push_back(new Point(start_.x, start_.y));//创建新的start点:参数是两个int数据，需要开辟point空间
	while (!openlist.empty())
	{
		auto current = getLeastPoint(openlist);//取出最小F值的open
		openlist.remove(current);
		closelist.push_back(current);

		auto nbr = nb8(current);
		for (auto &iter : nbr)//iter取出的是原来的值？
		{
			if (map_[iter->x][iter->y] == 8)//跳过障碍
				continue;
			if (!isInList(iter,openlist))//不在openlist中
			{
				
				iter->G = calG(iter, current);
				iter->H = calH(iter, &end_);
				iter->F = calF(iter);
				iter->parent = current;
				//std::cout << "out openlist" << std::endl;
				//std::cout << "x=" << iter->x << "y=" << iter->y << ' ' << iter->G << std::endl;
				openlist.push_back(iter);
			}
			else 
			{
				
				int tempG=calG(iter, current);//从current计算
				Point *temp = isInList(iter, openlist);//应该取出open中保持的值进行比较
				if (tempG < temp->G)//更新G值和F值
				//if (tempG < iter->G)//更新G值和F值
				{
					iter->G = tempG;
					iter->F = calF(iter);
					iter->parent = current;
				}
			}
			Point * resPoint = isInList(&end_, openlist);
			if (resPoint)
				return resPoint;//找到终点，直接返回终点
		}
	}
	return NULL;
}
std::list<Point *> Astar::getPath(Point start,Point end)
{
	std::list<Point*> path;//创建一个链表
	Point * result = findPath(start, end);
	while (result)//起点的父节点为NULL，可以作为退出循环条件
	{
		path.push_front(result);
		if (result->G == 14)
			sum += 14;
		else
			sum += 10;//判定总里程
		result = result->parent;
	}
	std::cout << "sum=" << sum << std::endl;
	if (!path.empty())
		return path;
}

