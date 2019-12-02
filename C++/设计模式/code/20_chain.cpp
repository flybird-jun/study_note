class chain
{
public:
	virtual void setNext(chain * cn) = 0;
	virtual chain* getNext() = 0;
	virtual void process()=0;
};
class Monitor:public chain
{
private:
	chain * next;
public:
	void process()
	{//处理请求
		if(...)
		{
			
		}
		else
		{
			this->getNext()->process();
		}
		
	}
	virtual chain* getNext()
	{
		return next;
	}
	virtual void setNext(chain *cn)
	{
		next = cn;
	}
};
class Teach:public chain
{
	private:
	chain * next;
public:
	void process()
	{//处理请求
		if(...)
		{
			
		}
		else
		{
			this->getNext()->process();
		}
		
	}
	virtual chain* getNext()
	{
		return next;
	}
	virtual void setNext(chain *cn)
	{
		next = cn;
	}
};