/*
	咖啡店有猫耳咖啡、星巴克、....
	每种咖啡都可以加配料:糖、摩卡、...
*/
class coffee
{
	public:
		virtual int cost()=0;
};
class catCoffee:public coffee
{
private:
	string history;
public:
	virtual int cost()
	{
		
	}
};
class starCoffee:public coffee
{
private:
	string history;
public:
	virtual int cost()
	{
		
	}
};
class suger:public coffee
{
	private:
		coffee * co;
		int cost = 10;
	public
		suger(coffee *cofe)
		{
			co = cofe;
		}
		virtual int cost()
		{
			return cost+co->cost();
		}
};
class moka:public coffee
{
	private:
		coffee * co;
		int cost = 15;
	public:
		moka(coffee*cofe)
		{
			co = cofe;
		}
		virtual int cost()
		{
			return cost+co->cost();
		}
	
};