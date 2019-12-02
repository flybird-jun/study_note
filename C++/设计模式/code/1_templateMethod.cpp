#include<iostream>
using namespace std;
class Base
{ 
public:
	void run()
	{/*
		基类实现算法的公共部分，step3,step5.
		派生类可根据需要覆写基类方法
	*/
		step1();
		for(int i=0;i<5;i++)
		{
			step2();
		}
		step3();
		step4();
		step5();
	}
	virtual void step1()=0;
	virtual void step2()=0;
	void step3()
	{
		cout<<"base step3"<<endl;
	}
	virtual void step4()=0;
	void step5()
	{
		cout<<"base step5"<<endl;
	}	
	virtual ~Base()
	{
	}
};
class Derive:public Base
{
public:
	virtual void step1()
	{
		cout<<"Derive step1"<<endl;
	}
	virtual void step2()
	{
		cout<<"Derive step2"<<endl;
	}
	virtual void step4()
	{
		cout<<"Derive step4"<<endl;
	}
	 void step5()
	{
		cout<<"Derive step5"<<endl;
	}
};
int main()
{
	Derive dd;
	dd.run();
	return 0;
}
