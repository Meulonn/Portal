#include "mainwindow.h"
#include"connexion.h"
#include<QMessageBox>
#include <QApplication>
#include<QtDebug>
#include<QString>


int main(int argc,  char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnection();
    //MainWindow w;
    MainWindow l;
   // l.show();
    if(test)
    {
        l.show();
        QMessageBox::information(nullptr,QObject::tr("database is open"),
        QObject::tr("connection successful.\n"
                    "Click cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);

return a.exec();
}
