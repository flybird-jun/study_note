/*
	pen 类型上分为smallpen bigpen
		颜色上分为red green
*/


class color
{
	public:
			virtual string getColor()=0;
};
class red:public color
{
	public:
			virtual string getColor()
			{
				return "red";
			}
};
class green:public color
{
	public:
			virtual string getColor()
			{
				return "green";
			}
};
class pen
{
private:
	color *cc;
public:
	virtual void draw()=0;
	pen(color *c):cc(c);
};
class smPen:public pen
{
	public:
		smPen(color *c):pen(c)
		{
			
		}
		virtual void draw()
		{
			cout<<"small pen"<<cc->getColor()<<endl;
		}
};
class biPen:public pen
{
	public:
		biPen(color *c):pen(c)
		{
			
		}
		virtual void draw()
		{
			cout<<"big pen"<<cc->getColor()<<endl;
		}
};
