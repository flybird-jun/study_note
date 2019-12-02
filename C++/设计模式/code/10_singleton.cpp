class singleTon
{
	private:
		singleTon();
	public:
		singleTon *getSingleTon()
		{
			static singleTon * instance = nullptr;

			if(instance == nullptr)
			{
				LOCK;
					if(instance == nullptr)
					{
						instance = new singleTon();
					}
				UNLOCK;
			}
			return instance;
			
		}
};