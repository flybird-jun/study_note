class car
{
	public:
		virtual string getBrand()=0;
};
class BMWcar:public car
{
	public:
		virtual string getBrand()
		{
			
		}
		virtual string getStyle()=0;
};
class RedBMWcar:public car
{
	public:
		virtual string getStyle()
		{
			
		}
};
class GreenBMWcar:public car
{
	public:
		virtual string getStyle()
		{
			
		}
};

class abstractFactory
{
	public:
		virtual car * createA()=0;
		virtual car * createB()=0;
};
class BMWFactory
{
	public :
		virtual BMWcar *createRed()
		{
			
		}
		virtual BMWcar *createGreen()
		{
			
		}
}