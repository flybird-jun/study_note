class Vistor
{
public:
	virtual void visitElemtA()=0;
	virtual void visitElemtB()=0;
};
class Vistor1:public Vistor
{
public:
	virtual void visitElemtA(Elemt* ea)
	{
		
	}
	virtual void visitElemtB(Elemt* eb)
	{
		
	}
};
class Vistor2:public Vistor
{
public:
	virtual void visitElemtA()
	{
		
	}
	virtual void visitElemtB()
	{
		
	}	
};
class Elemt
{
public:
	virtual void Accept(Vistor *vr)=0;
};
class ElemtA
{
public:
	virtual void Accept(Vistor *vr)
	{
		vr->visitElemtA(this);
	}
};
class ElemtB
{
public:
	virtual void Accept()
	{
		
	}
};