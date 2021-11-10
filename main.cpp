#include "mainwindow.h"
#include "connection.h"
#include "client.h"
#include<QApplication>
#include<QMessageBox>
#include<QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();
    MainWindow w;
    if (test)
    {
    w.show();
    QMessageBox::information(0,"Database","conncetion successful.\n");

    }
    else
        QMessageBox::critical(0,"Database","connection failed.\n");

    return a.exec();
}
