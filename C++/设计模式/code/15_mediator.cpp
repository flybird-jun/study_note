class colleage
{
public:
	virtual void send()=0;
	virtual void notify()=0;
protected:
 Mediator *m_pMediator;
};
class ConcretColleage:public colleage
{
	public:
		virtual void send(...)
		{
			m_pMediator->sent(...);
		}
		virtual void notify()
		{
			
		}
};
class Mediator
{
protected:
	vector<colleage *>m_colleage;
public:
	virtual void sent() = 0;
};
class ConcretMediator:public Mediator
{
public:
	virtual void sent()
	{
		//parse
		for(auto it:m_colleage)
		{
			if(it == reciever)
			{
				reciever.notify();
			}
		}
	}
};