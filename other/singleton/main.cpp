// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
using namespace std;
//�鿴�麯���� classB{};
class B1 {
public: B1()
{
	cout<<"B1 constructor"<<endl;
};//���캯������Ϊvirtual����
};
class B2:public B1
{
public:
	B2()
	{
		cout<<"B2 constructor"<<endl;
	};//���캯������Ϊvirtual����
	void f2()
	{
		cout << "B2::f2" << endl;
	}
};
class B3:public B1
{
public:
	B3()
	{
		cout<<"B3 constructor"<<endl;
	};//���캯������Ϊvirtual����
	void f3()
	{
		cout << "B3::f3" << endl;
	}
};
class D :public B2,public B3
{
public:
	D()
	{
		cout<<"D constructor"<<endl;
	};//���캯������Ϊvirtual����
	void v3()
	{
		cout << "D::v3" << endl;
	}
};
//=======================================
int main (int argc,const char * argv[])
{
	//cout<<sizeof(B)<<endl;
	cout<<sizeof(B1)<<endl;
	cout<<sizeof(B2)<<endl;
	cout<<sizeof(B3)<<endl;
	cout<<sizeof(D)<<endl;
	D* d=new D;
	B1* b1=new B1;
	B2* b2=new B2;
	B3* b3=new B3;
	d->v3();
	return 0;
}
