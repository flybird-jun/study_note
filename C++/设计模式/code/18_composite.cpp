class Compent
{
	protected:
		string m_string;
	public:
		Compent(string str){}
		virtual void add(Compent *com)=0;
		virtual void visit() = 0;
		virtual void remove(Compent *com) = 0;
};
class leafCompent
{
		
	public:
	virtual void add(Compent *com)
	{
		
	}
	virtual void remove(Compent *com)
	{
		
	}
	virtual void visit()
	{
		cout<<"leafCompent"<<endl;
	}		
};
class nodeCompent
{
	protected:
		vector<Compent*>child;
	public:
		virtual void add(Compent *com)
		{
			child.push_back(com);
		}
		virtual void remove(Compent *com)
		{
			child.earse(com);
		}
		virtual void visit()
		{
			for(auto it:child)
			{
				it->visit();
			}
		}
};
