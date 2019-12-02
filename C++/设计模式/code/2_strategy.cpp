/*
	背景:分享内容到wechat sina
*/
class Base
{
protected:
	string str;
public:
	virtual void shared()=0;
}
class wechat:public Base
{
public:
	virtual void shared()
	{
		str = "wechat share";
		cout<<str<<endl;
	}
}
class sina:public Base
{
public:
	virtual void shared()
	{
		str = "sina share";
		cout<<str<<endl;
	}

}
/*调用*/
void fun(Base * bb)
{
	b->shared();
}
/*****************************************************************************/
/*传统方式*/
class shared
{
 private:
	string str;
 public:
	void shared(int style)
	{
		if(style == 1)
		{
			str = "wechat share";
		}
		else if(style == 2)
		{
			str = "sina share";
		}
		cout<<str<<endl;
	}
}


int main()
{

}
