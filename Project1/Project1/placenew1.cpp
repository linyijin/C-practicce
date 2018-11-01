#include<iostream>
#include<string>
#include<new>
using namespace std;
const int BUF = 512;
class JustTesting
{
	string word;
	int number;
public:
	JustTesting(const string & s = "Just Testing ", int n = 0)
	{
		word = s; number = n; cout << word << "constructed\n";
	}
	~JustTesting() { cout << word << "destroyed\n"; }
	void show() const { cout << word << "," << number << endl;}
};
int main()
{
	char *buffer = new char[BUF];
	JustTesting *pc1, *pc2;
	pc1 = new (buffer) JustTesting;//ʹ��buffer�еĵ�ַ��������
	pc2 = new JustTesting("Heap1", 20);
	cout << "address buffer:" << (void *)buffer << "heap:" << pc2 << endl;//���Buffer���ݼ�pc2��ַ
	cout << pc1 << ':';
	pc1->show();
	cout << pc2 << ':';
	pc2->show();

	JustTesting *pc3, *pc4;
	//pc3 = new(buffer) JustTesting("bad idea", 6);//pc1���󽫱�����
	pc3 = new(buffer + sizeof(JustTesting)) JustTesting("better idea", 6);
	pc4 = new JustTesting("Heap2", 10);

	cout << "memory contents:\n";
	cout << pc3 << ":";
	pc3->show();
	cout << pc4 << ":";
	pc4->show();

	delete pc2;
	delete pc4;
	pc3->~JustTesting();
	pc1->~JustTesting();
	delete[] buffer;//����ɾ��
	cout << "Done\n";
	system("pause");
	return 0;

}