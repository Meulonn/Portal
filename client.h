#ifndef CLIENT_H
#define CLIENT_H
#include <QSqlDatabase>
#include<QString>
#include<QSqlQuery>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include<QApplication>
#include<QMessageBox>
#include<QDebug>
#include <QDate>
#include <QObject>

class client
{private:
    QString CLIENT_CIN;
    QString NAME_CLIENT;
    long PHONE_NUM;
    int D,M,Y;
    int GENDER;
    QString EMAIL;
    QString ADRESS;
  public:
    client();
    client(QString ,QString,long,int,int,int,int,QString,QString);
    QString get_cin();void set_cin(QString);
    QString get_name();void set_name(QString);
    long get_num();void set_num(long);
    int get_d();void set_d(int);
    int get_m();void set_m(int);
    int get_y();void set_y(int);
    int get_gender();void set_gender(int);
    QString get_email();void set_email(QString);
    QString get_adress();void set_adress(QString);

   bool add_client();
   bool delete_client(QString);
   QSqlQueryModel * view_client();
   bool update_client(QString,long,QString,QString);

   QSqlQueryModel * research_client(QString);
   QSqlQueryModel * classify_client(QString,QString,QString,QString);




};

#endif // CLIENT_H
