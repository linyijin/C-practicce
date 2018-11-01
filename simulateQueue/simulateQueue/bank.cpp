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
	long turnaways = 0;//�������뿪�Ŀͻ�
	long customers = 0;//������еĿͻ�
	long served = 0;//����Ŀͻ�
	long sum_line = 0;//�ۻ��Ķ��г���
	int wait_time = 0;//ATM����ʱ��
	long line_wait = 0;//�����ۻ���ʱ��

	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (line.isFull())//������
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);//���õ���ʱ��
				line.enqueue(temp);
			}
		}
		if (wait_time <= 0 && !line.isEmpty())
		{
			line.dequeue(temp);//������һ���ͻ�
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
		cout.precision(2);//�趨������ľ���ֵ
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