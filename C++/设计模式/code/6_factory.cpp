class car
{
	public:
		virtual string getbrand()=0;
};
class BMWCar:public car
{
	public:
		virtual stirng getbrand();
};
class AoDiCar:public car
{
	public:
		virtual stirng getbrand();
};

class Factory
{
public:
	virtual car * createCar()=0;
}
class BMWCarFactory:public Factory
{
public:
	virtual car * createCar()
	{
		return new BMWCar;
	}
};
class AodiCarFactory:public Factory
{
public:
	virtual car * createCar()
	{
		return new AoDiCar;
	}
};
int main()
{
	BMWCarFactory bf = new BMWCarFactory();
	bf->createCar();
}