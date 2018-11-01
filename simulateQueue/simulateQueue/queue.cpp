#include "queue.h"
#include<cstdlib>
Queue::Queue(int qs) :qsize(qs)
{
	front = rear = NULL;
	items = 0;
}
Queue::~Queue()//显式析构函数
{
	Node * temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}
bool Queue::isEmpty() const
{
	return items == 0;
}
bool Queue::isFull() const
{
	return items == qsize;
}
int Queue::queuecount() const
{
	return items;
}
bool Queue::enqueue(const Item &item)
{
	if (isFull())
		return false;
	Node *add = new Node;
	add->item = item;
	add->next = NULL;
	items++;
	if (front == NULL)//没有元素，插入队头
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}
bool Queue::dequeue(Item &item)//用item去取队头元素
{
	if (front == NULL)
		return false;
	item = front->item;
	items--;
	Node * temp = front;
	front = front->next;
	delete temp;
	if (items == 0)//队列为空
		rear = NULL;
	return true;
}
void Customer::set(long when)
{
	processTime = std::rand() % 3 + 1;
	arrive = when;
}