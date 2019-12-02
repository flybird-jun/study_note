//紧耦合
class FlyWeight
{
private:
	string m_key;
public:
	FlyWeight(string str):m_key(str)
	{
		
	}
};
class FlyWeightFactory
{
private:
	map<string,FlyWeight *> table;
public:
	FlyWeight* CreateFlyWeight(string key)
	{
		auto it = it.find(key);
		if(it!=table.end())
		{
			return it->second;
		}
		FlyWeight * fw = new FlyWeight(key);
		table.insert(std::map<string, FlyWeight*>::value_type(key,fw));
	}
}