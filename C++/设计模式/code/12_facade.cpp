class patient
{
public:
	virtual void register() = 0;//挂号
	virtual void pay() = 0;//缴费
	virtual void service()=0;//门诊
	virtual void medicine()=0;//取药
};
class facade
{
	private:
		patient *ipatient;
	public:
		void treat()//封装的接口
		{
			ipatient->register();
			ipatient->pay();
			ipatient->service();
			ipatient->medicine();
		}
}