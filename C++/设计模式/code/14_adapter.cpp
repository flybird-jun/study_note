class target
{
public:
	virtual void target()=0;
};
class OldInterface
{
public:
	void process();
};
class Adapter:public target
{
private:
	OldInterface *pOldInterface;
public:
	virtual void target()
	{
		//...
		pOldInterface->process();
		//...
	}
}