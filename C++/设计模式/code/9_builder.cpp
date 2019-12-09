class builder
{
public:
	virtual void setArm() = 0;
	virtual void setLeg() = 0;
	virtual void setBrain() = 0;
};
class People:public builder
{
public:
	virtual void setArm()
	{
		
	}
	virtual void setLeg()
	{
		
	}
	virtual void setBrain()
	{
		
	}
};
class director
{
protected:
	builder * br;
public:
	virtual void construct() = 0;
};
class PeopleDirector
{
public:
	virtual void construct()
	{
		br->setArm();
		br->setArm();
		br->setLeg();
		br->setBrain();
	}
}