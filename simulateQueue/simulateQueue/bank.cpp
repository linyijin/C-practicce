#include<iostream>
#include<cstdlib>
#include<ctime>
#include "queue.h"
const int MIN_PER_HR_ = 60;
bool newcustomer(double x);
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0));

	cout << "enter maximum size of queue:";
	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "enter time of simulate hour:";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR_ * hours;

	cout << "enter the average number of customer per hour:";
	double perhour;
	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR_ / perhour;

	Item temp;
	long turnaways = 0;//队列满离开的客户
	long customers = 0;//加入队列的客户
	long served = 0;//服务的客户
	long sum_line = 0;//累积的队列长度
	int wait_time = 0;//ATM工作时间
	long line_wait = 0;//队伍累积的时间

	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (line.isFull())//队列满
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);//设置到达时间
				line.enqueue(temp);
			}
		}
		if (wait_time <= 0 && !line.isEmpty())
		{
			line.dequeue(temp);//加入下一个客户
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.queuecount();
	}
	if (customers > 0)
	{
		cout << "customer accepted:" << customers << endl;
		cout << "customer served:" << served << endl;
		cout << "turnaway:" << turnaways << endl;
		cout << "average queue size:";
		cout.precision(2);//设定输出流的精度值
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << "average wait time:" << (double)line_wait / served << "minute\n";
	}
	else
		cout << "No customer\n";
	cout << "Done\n";
	system("pause");
	return 0;
}
bool newcustomer(double x)
{
	return (std::rand()*x / RAND_MAX < 1);
}