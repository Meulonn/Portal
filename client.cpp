#include "client.h"

Client::Client()
{
client_cin=0;
name="";
phone_num=0;
gender=0;
email="";
adress="";
}

Client:: Client(long client_cin,QString name,long phone_num,QDate birthday,int gender,QString email,QString adress)
{
    this->client_cin=client_cin;
    this->name=name;
    this->phone_num=phone_num;
    this->birthday=birthday;
    this->gender=gender;
    this->email=email;
    this->adress=adress;
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
QString Client::get_adress(){return adress;}
void Client::set_adress(QString adress){this->adress=adress;}

bool Client::add_client()
{
   QSqlQuery query;

   QString client_cin_s= QString::number(client_cin);
   QString phone_num_s= QString::number(phone_num);
   QString gender_s= QString::number(gender);


   query.prepare("INSERT INTO client(client_cin_s, name, phone_num_s, birthday, gender_s, email,adress) "
                 "VALUES(:client_cin,:name,:phone_num,:birthday,:gender,:email,:adress) ");
    query.bindValue(":client_cin",client_cin_s);
    query.bindValue(":name",name);
    query.bindValue(":phone_num",phone_num_s);
    query.bindValue(":birthday",birthday);
    query.bindValue(":gender",gender_s);
    query.bindValue(":email",email);
    query.bindValue(":adress",adress);

    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    return query.exec();
}

//void Client::view_client(Client);
//void Client:: update_client(Client*);
//void Client::delete_client(Client*);
//void Client::view_purchaseHistory(Client);
//void Client::classify_client(Client);
//Client Client:research_client(Client);
//void Client::notify_about_delivery(Client);
