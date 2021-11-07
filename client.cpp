#include "client.h"

Client::Client()
{
client_cin=0;
phone_num=0;
gender=0;
}

Client:: Client(long client_cin,QString name,long phone_num,QDate birthday,int gender,QString email)
{
    this->client_cin=client_cin;
    this->name=name;
    this->phone_num=phone_num;
    this->birthday=birthday;
    this->gender=gender;
    this->email=email;
}

long Client:: get_cin(){return client_cin;}
void Client::set_cin(long client_cin){this->client_cin=client_cin;}
QString Client::get_name(){return name;}
void Client::set_name(QString name){this->name=name;}
long Client::get_num(){return phone_num;}
void Client::set_num(long phone_num){this->phone_num=phone_num;}
QDate Client::get_birthday(){return birthday;}
void Client::set_birthday(QDate birthday){this->birthday=birthday;}
int Client::get_gender(){return gender;}
void Client::set_gender(int gender){this->gender=gender;}
QString Client::get_email(){return email;}
void Client::set_email(QString email){this->email=email;}

bool Client::add_client()
{QVariant client_cin,phone_num;
   QSqlQuery query;

   client_cin= QVariant::fromValue(client_cin);
   phone_num= QVariant::fromValue(phone_num);


   query.prepare("INSERT INTO client(client_cin, name, phone_num, birthday, gender, email) "
                 "VALUES(cin, nom, num, date, gend, mail) ");
    query.bindValue("cin",client_cin);
    query.bindValue("nom",name);
    query.bindValue("num",phone_num);
    query.bindValue("date",birthday);
    query.bindValue("gend",gender);
    query.bindValue("mail",email);

    return query.exec();
}

//void Client::view_client(Client);
//void Client:: update_client(Client*);
//void Client::delete_client(Client*);
//void Client::view_purchaseHistory(Client);
//void Client::classify_client(Client);
//Client Client:research_client(Client);
//void Client::notify_about_delivery(Client);
