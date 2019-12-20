#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QStack>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	ui->lineEdit->setFont(QFont( "Timers" , 28 ,  QFont::Bold) );
	ui->textEdit->setFont(QFont( "Timers" , 14 ,  QFont::Normal) );

	setWindowFlags(Qt::WindowStaysOnTopHint);

	//注册热键 CTRL+X
	//热键功能要求：当在其他程序时，直接通过热键唤醒本计算器并自动显示焦点在输入框
	::RegisterHotKey((HWND)winId(),MY_HOT_KEY,MOD_ALT,'X');

}

MainWindow::~MainWindow()
{
	//反注册热键
	::UnregisterHotKey((HWND)winId(),MY_HOT_KEY);
    delete ui;
}

QString MainWindow::GetWholeWord(const QString& sInput, const int nStartPos, int& nOutEndPos)  
{  
	QString sWord;  
	nOutEndPos = nStartPos;  
	for (int i = nStartPos; i < sInput.length(); i++)  
	{  
		QChar ch = sInput.at(i);  
		if ((ch >= '0' && ch <= '9')  
			|| (ch >= 'a' && ch <= 'z')  
			|| (ch >= 'A' && ch <= 'Z')  
			|| (ch == '.'))  
		{  
			sWord += ch;  
			nOutEndPos = i;  
		}  
		else  
		{  
			break;  
		}  
	}  
	return sWord;  
};  

QString MainWindow::AnlysisExpr(QString sInputExpr)  
{  
	// 获取逆波兰表达式    
	QStack<QString> stackMain;  
	QStack<QString> stackOper;  
	for (int i = 0; i < sInputExpr.length(); i++)  
	{  
		QChar ch = sInputExpr[i];  
		if (ch == ' ')  
		{ // 空格    
			continue;  
		}  
		else if (ch == '(')  
		{ // 左括号    
			stackOper.push(QString(ch));  
		}  
		else if (ch == ')')  
		{ // 右括号    
			while (!stackOper.empty())  
			{  
				QString chPop = stackOper.pop();  
				if (chPop != "(")  
				{  
					stackMain.push(chPop);  
				}  
				else  
				{  
					break;  
				}  
			}  
		}  
		else if ((ch >= '0' && ch <= '9')  
			|| (ch >= 'a' && ch <= 'z')  
			|| (ch >= 'A' && ch <= 'Z')  
			|| (ch == '.'))  
		{ // 数字或字符    
			stackMain.push(GetWholeWord(sInputExpr, i, i));  
		}  
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')  
		{ // 操作符    
			if (stackOper.empty())  
			{ //     
				stackOper.push(QString(ch));  
			}  
			else  
			{ // 出栈直到遇到优先小于等于的    
				QString chTemp = stackOper.top();  
				while (((ch == '+' || ch == '-') && (chTemp == "*" || chTemp == "/"))  
					|| ((ch == '+' || ch == '-') && (chTemp == "+" || chTemp == "-"))  
					|| ((ch == '*' || ch == '/') && (chTemp == "*" || chTemp == "/")))  
				{  
					stackMain.push(stackOper.pop());  
					if (stackOper.size() > 0)  
						chTemp = stackOper.top();  
					else  
						break;  
				}  
				stackOper.push(QString(ch));  
			}  
		}  
	}  
	while (!stackOper.empty())  
	{  
		QString chPop = stackOper.pop();  
		stackMain.push(chPop);  
	}  

	QString sText;  
	QStack<QString> stackCalc;  
	while (!stackMain.empty())  
	{  
		QString chPop = stackMain.pop();  
		stackCalc.push(chPop);  
		sText.push_back(chPop);  
	}  

	// 表达式还原计算  
	QString sNewExpr;  
	double dResultValue = sInputExpr.toDouble();  
	{  
		QString sOper;  

		// 计算逆波兰表达式：重新生成表达式    
		QStack<QString> stackTemp;  
		QStack<double> stackTempValue;  
		while (!stackCalc.empty())  
		{  
			QString sPop = stackCalc.pop();  
			if (sPop.length() == 0)  
				continue;  

			QChar ch = sPop.at(0);  
			if (ch == '+' || ch == '-' || ch == '*' || ch == '/')  
			{  
				if (stackTemp.size() >= 2)  
				{  
					sOper = sPop;  
					QString s1 = stackTemp.pop();  
					QString s2 = stackTemp.pop();  
					if ((sOper == "*" || sOper == "/") && (s2.contains('+') || s2.contains('-')))  
					{  
						s2 = "(" + s2 + ")";  
					}  
					sNewExpr = QString("%1 %2 %3").arg(s2).arg(sOper).arg(s1);  
					stackTemp.push(sNewExpr);  

					double d1 = stackTempValue.pop();  
					double d2 = stackTempValue.pop();  
					switch (ch.cell())  
					{  
					case '+':dResultValue = d2 + d1; break;  
					case '-':dResultValue = d2 - d1; break;  
					case '*':dResultValue = d2 * d1; break;  
					case '/':dResultValue = d2 / d1; break;  
					}  
					stackTempValue.push(dResultValue);  
				}  
			}  
			else  
			{  
				stackTemp.push(sPop);  
				stackTempValue.push(sPop.toDouble());  
			}  
		}  
	}  
	//return QString("%1").arg(dResultValue);		//使用QString的%1方式用浮点数来初始化时，会出现科学计数法的表示结果
	return QString::number(dResultValue,'f',10);	//最多保留小数点后10位
}  

//如果表达式以-开头，就在最前面加个0，防止负数开头的情况下，他认为是减号没有左操作数而忽略掉了
QString MainWindow::AddZeroBefore(QString str)
{
	QString s = str;
	if (s.isEmpty())
	{
		return s;
	}
	if (s[0] == '-')
	{
		s = QString("0") + s;
	}
	return s;
}

//去掉小数点后无效的0
void MainWindow::DeleteZero(QString& s)
{
	int nPos = s.indexOf(".");
	if (nPos != -1)
	{
		int nNum = 0;
		for (int i=s.length()-1; i>=nPos; i--)
		{
			if (s[i] == '0' || s[i] == '.')
			{
				nNum++;
			}
			else
			{
				break;
			}
		}
		if (nNum>0)
		{
			s = s.left(s.length() - nNum);
		}
	}
}

void MainWindow::on_lineEdit_returnPressed()
{
	QString strInput = ui->lineEdit->text();
	if (strInput.isEmpty())
	{
		return ;
	}
	//如果最开始是减号,就在减号前加一个0，因为这个算法会忽略一开始就是运算符的情况，认为没有左操作数 比如导致-1+3=4忽略-号，加上0改成0-1+3=2就正常
	QString strNewInput = AddZeroBefore(strInput);
	QString strResult = AnlysisExpr(strNewInput);
	if (strResult.isEmpty())
	{
		return;
	}
	//去掉小数点后无效的0
	DeleteZero(strResult);

	QString strRecord = strInput;
	if (strRecord.right(1) != "=")
	{
		strRecord += "=";
	}
	strRecord += strResult;

	ui->lineEdit->setText(strResult);
	ui->textEdit->setText(strRecord + "\n" + ui->textEdit->toPlainText());
}

//响应热键
bool MainWindow::nativeEventFilter( const QByteArray &eventType, void *message, long *result )
{
	if (eventType == "windows_generic_MSG" || eventType == "windows_dispatcher_MSG")
	{
		MSG * pMsg = reinterpret_cast<MSG *>(message);

		if (pMsg->message == WM_HOTKEY)
		{
			if (pMsg->wParam == MY_HOT_KEY)
			{
				//setWindowFlags(Qt::WindowStaysOnTopHint);
				this->showNormal();
				//以下两句缺一均不能有效将窗口置顶
				this->setWindowState(Qt::WindowActive);
				this->activateWindow();
				//焦点
				ui->lineEdit->setFocus();
				
				return true;
			}
		}
	}
	return false;
}