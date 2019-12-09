class prototype
{
public:
	virtual prototype *clone()=0;
};
class concretePrototype:public prototype
{
private:
	//....
public:
	virtual prototype * clone()
	{
		return new concretePrototype(*this);
	}
};
int main()
{
	prototype *a = new concretePrototype(/*...*/);
	prototype *b = a->clone();
}