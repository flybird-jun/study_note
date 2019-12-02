class state
{
public:
	virtual void display()=0;
};

class GoodMood:public state
{
public:
	virtual void display()
	{
		
	}
};

class BadMood:public state
{
public:
	virtual void display()
	{
		
	}
};

class Context
{
private:
	state *pstate;
public:
	void request()
	{
		pstate->display();
	}
	void changeState(state *istate)
	{
		pstate = istate;
	}
}