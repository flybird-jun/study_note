class Command
{
	protected:
		Receiver * receiver;
	public:
		Command(Receiver * receiver)
		{
			this->receiver = receiver;
		}
		virtual void Execute()=0;
};
class ConcreteCommand:public Command
{
	public:
		ConcreteCommand(Receiver *receiver):Command(receiver)
		{
			
		}
		void Execute()
		{
			receiver->Action();
		}
};
class Invoker
{
	protected:
		Command *cmd;
	public:
		void setCommand(Command *cc)
		{
			cmd = cc;
		}
		void ExecuteCommand()
		{
			cmd->Execute();
		}
		
	
};
class Receiver
{
	public:
	
		void Action()
		{
			
		}
};