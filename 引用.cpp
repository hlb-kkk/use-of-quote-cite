#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//这是不对的，不能返回局部变量地址
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
	static int a = 10;//不能直接返回局部变量引用
	return a;
}

int main()
{

	int* p = fun1();

	cout << *p << endl;
	cout << *p << endl;
	//计算机由于设定在第一次执行时会执行正确的，但是第二次开始就会出现错误
	//这是由于，局部变量存放于栈区，程序运行会自动释放那块地址

	int* u = fun2();

	cout << *u << endl;
	cout << *u << endl;

	delete u;

	//cout << *u << endl; //delete之后再输出就会显示错误


	//为什么用new就得采用指针形式，因为利用new创建的
	//开辟新数组
	int* arr = new int [3];
	for (int i = 0; i < 3; i++)
	{
		arr[i] = i + 4;
	}
	for (int i = 0; i < 3; i++)
	{
		cout << arr[i] << endl;
	}

	//引用：用的取址符号&，本质上与被引用指的同一块地址。类似于指针常量，一旦初始化，不能修改被引用对象，
	//但是能修改被引用对象的值
	int a = 10;
	int b = 20;
	int& c = a;
	cout << c << endl;
	cout << endl;

	//引用做函数参数，效果与地址传递类似
	swap01(a, b);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	
	//引用做函数返回值
	int& ref = test01();
	cout << ref << endl;

	//如果函数做左值，那么必须返回引用
	test01() = 200;
	cout << ref << endl;


	system("pause");
	return 0;
}