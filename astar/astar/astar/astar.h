#pragma once
#include<iostream>
#include<vector>
#include<list>
const int lcost = 10;
const int tcost = 14;
struct Point {
	int x;
	int y;
	int F, G, H;
	Point *parent;
	Point (int _x, int _y) : x(_x), y(_y), F(0), G(0), H(0), parent(NULL) {}//��ʼ��
};
class Astar {
public:
	Astar() {};
	Astar(const Astar &a) { openlist = a.openlist; };
	int sum = 0;//��¼�����
	void initAstar(std::vector<std::vector<int>> &map);
	std::list<Point *> getPath(Point start, Point end);
private:
	int calG(Point *p,Point *start);
	int calF(Point *p);
	int calH(Point *p, Point *end);
	 std::vector<Point *> nb8(Point *cur);//�˽��ڣ����Ű˸�ָ��
	 std::list<Point*> openlist;
	 std::list<Point*> closelist;
	Point* isInList(Point *p, std::list<Point*> &q);
	bool inMap(Point *p);//�ж��Ƿ��ڵ�ͼ��
	std::vector<std::vector<int>> map_;//��ͼ����
	Point *getLeastPoint(std::list<Point*> p);
	Point * findPath(Point start, Point end);

};