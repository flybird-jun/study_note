#include<iostream>
#include<vector>
using namespace std;
/*
	市政府发布通知，各单位接收
*/
class notice
{
public:
   virtual void notify()=0;
};
class police:public notice
{
public:
	virtual void notify()
	{
		cout<<"police:government notify"<<endl;
	}
};
class edu:public notice
{
public:
	virtual void notify()
	{
		cout<<"edu:goverment notify"<<endl;
	}
};
class goverment
{
private:
	vector<notice *>inotice;
public:
	void addNoticeUnit(notice * unit)
	{
		inotice.push_back(unit);
	}
	void releaseNotice()
	{
		for(auto it:inotice)
		{
			it->notify();
		}
	}
};
int main()
{
	goverment gv;
	gv.addNoticeUnit(new police);
	gv.addNoticeUnit(new edu);
	gv.releaseNotice();
}