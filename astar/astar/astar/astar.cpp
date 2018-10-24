#include"astar.h"
#include<math.h>

void Astar::initAstar(std::vector<std::vector<int>> &map)//����
{
	map_ = map;//����ͼ����astar����
}
int Astar::calG(Point *p, Point *start)//��������֮���G
{
	int externG= abs(start->x - p->x) + abs(start->y - p->y) == 1 ? lcost : tcost;
	int parentG= start->parent == NULL ? 0 :start->parent->G;//�˴��߼������⣬Ӧ�ÿ��ǵ��ǵ�ǰ���G���ۣ�������֮ǰ�����parent
	//p->G = abs(start->x - p->x) + abs(start->y - p->y) == 1 ? lcost : tcost;
	//p->G=p->parent == NULL ? 0 : p->G + p->parent->G;//��ʼ�ڵ�Ϊ0�������ڵ�Ϊ���ڵ�+�������
	return externG+parentG;
}
int Astar::calH(Point *p, Point *end)
{
	//p->H = abs(end->x-p->x) + abs(end->y-p->y)*lcost;//�����پ���
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

			if (i == 0 && j == 0)//������ǰ�غϽڵ�
				continue;
			
			int x = cur->x + i;
			int y = cur->y + j;
			Point *p = new Point(x,y);
			if (inMap(p) && !isInList(p,closelist))//ѡȡ�ڵ�ͼ�У�����close�еİ˽���,open������һ���µĸ�����Ҫע������
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
	openlist.push_back(new Point(start_.x, start_.y));//�����µ�start��:����������int���ݣ���Ҫ����point�ռ�
	while (!openlist.empty())
	{
		auto current = getLeastPoint(openlist);//ȡ����СFֵ��open
		openlist.remove(current);
		closelist.push_back(current);

		auto nbr = nb8(current);
		for (auto &iter : nbr)//iterȡ������ԭ����ֵ��
		{
			if (map_[iter->x][iter->y] == 8)//�����ϰ�
				continue;
			if (!isInList(iter,openlist))//����openlist��
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
				
				int tempG=calG(iter, current);//��current����
				Point *temp = isInList(iter, openlist);//Ӧ��ȡ��open�б��ֵ�ֵ���бȽ�
				if (tempG < temp->G)//����Gֵ��Fֵ
				//if (tempG < iter->G)//����Gֵ��Fֵ
				{
					iter->G = tempG;
					iter->F = calF(iter);
					iter->parent = current;
				}
			}
			Point * resPoint = isInList(&end_, openlist);
			if (resPoint)
				return resPoint;//�ҵ��յ㣬ֱ�ӷ����յ�
		}
	}
	return NULL;
}
std::list<Point *> Astar::getPath(Point start,Point end)
{
	std::list<Point*> path;//����һ������
	Point * result = findPath(start, end);
	while (result)//���ĸ��ڵ�ΪNULL��������Ϊ�˳�ѭ������
	{
		path.push_front(result);
		if (result->G == 14)
			sum += 14;
		else
			sum += 10;//�ж������
		result = result->parent;
	}
	std::cout << "sum=" << sum << std::endl;
	if (!path.empty())
		return path;
}

