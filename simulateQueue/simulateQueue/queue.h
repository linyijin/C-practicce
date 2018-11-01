#pragma once
#ifndef QUEUE_H
#define QUEUE_H
class Customer 
{
private:
	long arrive;
	int processTime;
public:
	Customer() { arrive = processTime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processTime; }
};
typedef Customer Item;

class Queue
{
private:
	struct Node { Item item; struct Node * next; };
	enum {Q_SIZE=10};

	Node * front;
	Node * rear;
	int items;
	const int qsize;
	Queue(const Queue &q) :qsize(0) {}//阻止默认构造函数
	Queue &operator=(const Queue &q) { return *this; }//防止直接赋值
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isEmpty() const;
	bool isFull() const;
	int queuecount() const;
	bool enqueue(const Item &item);
	bool dequeue(Item &item);
};
#endif // !QUEUE_H
