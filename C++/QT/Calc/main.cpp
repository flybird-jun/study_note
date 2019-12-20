/************************************************************************/
/*           
工程名: Calc.exe
说明:   QT实战项目之五--计算器
作者:   逆风微光
qq:     787701109
blog:   http://blog.csdn.net/dpsying

特性：
1，支持常规四则表达式求值。
2，支持显示输入的历史记录，并拷贝复制。
3，保持置顶。
4，支持热键唤醒。
*/
/************************************************************************/


#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
	a.installNativeEventFilter(&w);
    w.show();

    return a.exec();
}
