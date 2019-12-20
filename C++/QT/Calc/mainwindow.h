#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <QAbstractNativeEventFilter>
#include <windows.h>

namespace Ui {
class MainWindow;
}

#define MY_HOT_KEY 4009

class MainWindow : public QMainWindow,public QAbstractNativeEventFilter
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	QString AnlysisExpr(QString sInputExpr);
	QString GetWholeWord(const QString& sInput, const int nStartPos, int& nOutEndPos);

    virtual bool nativeEventFilter( const QByteArray &eventType, void *message, long *result );

private:
	QString AddZeroBefore(QString str);			//如果表达式以-开头，就在最前面加个0
	void DeleteZero(QString& s);				//去掉小数点后无效的0

private slots:
	void on_lineEdit_returnPressed();
	
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
