#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//���ǲ��Եģ����ܷ��ؾֲ�������ַ
int* fun1()
{
	int a = 10;
	return &a;
}


int* fun2()
{
	int* a = new int(10);
	return a;
}

void swap01(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int& test01()
{
	static int a = 10;//����ֱ�ӷ��ؾֲ���������
	return a;
}

int main()
{

	int* p = fun1();

	cout << *p << endl;
	cout << *p << endl;
	//����������趨�ڵ�һ��ִ��ʱ��ִ����ȷ�ģ����ǵڶ��ο�ʼ�ͻ���ִ���
	//�������ڣ��ֲ����������ջ�����������л��Զ��ͷ��ǿ��ַ

	int* u = fun2();

	cout << *u << endl;
	cout << *u << endl;

	delete u;

	//cout << *u << endl; //delete֮��������ͻ���ʾ����


	//Ϊʲô��new�͵ò���ָ����ʽ����Ϊ����new������
	//����������
	int* arr = new int [3];
	for (int i = 0; i < 3; i++)
	{
		arr[i] = i + 4;
	}
	for (int i = 0; i < 3; i++)
	{
		cout << arr[i] << endl;
	}

	//���ã��õ�ȡַ����&���������뱻����ָ��ͬһ���ַ��������ָ�볣����һ����ʼ���������޸ı����ö���
	//�������޸ı����ö����ֵ
	int a = 10;
	int b = 20;
	int& c = a;
	cout << c << endl;
	cout << endl;

	//����������������Ч�����ַ��������
	swap01(a, b);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	
	//��������������ֵ
	int& ref = test01();
	cout << ref << endl;

	//�����������ֵ����ô���뷵������
	test01() = 200;
	cout << ref << endl;


	system("pause");
	return 0;
}