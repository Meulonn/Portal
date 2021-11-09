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
#include <QList>
class Client
{private:
    QString client_cin;
    QString name_client;
    long phone_num;
    int d,m,y;
    int gender;
    QString email;
    QString adress;
  public:
    Client();
    Client(QString ,QString,long,int,int,int,int,QString,QString);
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
   bool delete_client(long);
   /* void view_client(Client);
    void update_client(Client*);
   void view_purchaseHistory(Client);
   void classify_client(Client);
   Client research_client(Client);
   void notify_about_delivery(Client);*/


};

#endif // CLIENT_H
