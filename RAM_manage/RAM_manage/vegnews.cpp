#include<iostream>
#include<vector>
using std::cout;

#include "string.h"
void callme1(stringBad &);//����
void callme2(stringBad);//������

int main()
{/*
	using std::endl;
	{
		stringBad name;
		char temp[40];
		std::cin.getline(temp, 40);
		name = temp;
		cout << "string an inner block\n";
		stringBad headline1("celery stalks at midnight");
		stringBad headline2("lettuce prey");
		stringBad sports("spinach leave bowl for dollar");
		cout<<"headline1: "<<headline1<< endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;
		callme1(headline1);
		cout << "headline1:" << headline1 << endl;
		callme2(headline2);//��ֵ���ݣ��뿪�ú������������
		cout << "headline2" << headline2 << endl;//��������
		cout << "initialize one object to another:\n";
		stringBad sailor = sports;//=stringBad sailor=stringBad(sports),ʹ���˹��캯��ԭ�ͣ�stringBad(const stringBad &),δ����Ĺ��캯�����ɱ������Զ����ɣ��ʲ���Զ������+1
		cout << "sailor:" << sailor << endl;
		cout << "assign one object to another:\n";
		stringBad knot;
		knot = headline1;
		cout << "knot:" << knot << endl;
		cout << "exiting the block.\n";

	}//������������ж���˳���빹���෴��knot->sailor->sport
	cout << "end of main()\n";//ִ�в����ͻ��Զ��˳�����Ϊ��������Ѿ�Ϊ��
	*/
	stringBad hello;
	std::vector<int> a(10,0);
	hello.change(a);
	for(auto &iter :a)
		std::cout << iter << std::endl;
	system("pause");
}
void callme1(stringBad &rsb)
{
	cout << "string pass by reference: \n";
	cout << "  \"" << rsb << "\"\n";
}
void callme2(stringBad sb)
{
	cout << "string pass by value:\n";
	cout << " \"" << sb << "\"\n";
}