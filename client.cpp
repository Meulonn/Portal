#include "client.h"

Client::Client()
{
client_cin="";
name_client="";
phone_num=0;
d=0;m=0;y=0;
gender=0;
email="";
adress="";
}

Client:: Client(QString client_cin,QString name_client,long phone_num,int d,int m,int y,int gender,QString email,QString adress)
{
    this->client_cin=client_cin;
    this->name_client=name_client;
    this->phone_num=phone_num;
    this->d=d;
    this->m=m;
    this->y=y;
    this->gender=gender;
    this->email=email;
    this->adress=adress;
}

QString Client:: get_cin(){return client_cin;}
void Client::set_cin(QString client_cin){this->client_cin=client_cin;}
QString Client::get_name(){return name_client;}
void Client::set_name(QString name_client){this->name_client=name_client;}
long Client::get_num(){return phone_num;}
void Client::set_num(long phone_num){this->phone_num=phone_num;}
int Client::get_d(){return d;}
void Client::set_d(int d){this->d=d;}
int Client::get_m(){return m;}
void Client::set_m(int m){this->m=m;}
int Client::get_y(){return y;}
void Client::set_y(int y){this->y=y;}
int Client::get_gender(){return gender;}
void Client::set_gender(int gender){this->gender=gender;}
QString Client::get_email(){return email;}
void Client::set_email(QString email){this->email=email;}
QString Client::get_adress(){return adress;}
void Client::set_adress(QString adress){this->adress=adress;}

bool Client::add_client()
{
   QSqlQuery query;

   QString phone_num_s= QString::number(phone_num);
   QString gender_s= QString::number(gender);
   QString d_s= QString::number(d);
   QString m_s= QString::number(m);
   QString y_s= QString::number(y);

   query.prepare("insert into clients(client_cin,name_client,phone_nup,d,m,y,gender,email,adress)"
                 "values(:CLIENT_CIN,:NAME_CLIENT,:PHONE_NUM,:D,:M,:Y,:GENDER,:EMAIL,:ADRESS)");
    query.bindValue(":CLIENT_CIN",client_cin);
    query.bindValue(":NAME_CLIENT",name_client);
    query.bindValue(":PHONE_NUM,",phone_num_s);
    query.bindValue(":D",d_s);
    query.bindValue(":M",m_s);
    query.bindValue(":Y",y_s);
    query.bindValue(":GENDER",gender_s);
    query.bindValue(":EMAIL",email);
    query.bindValue(":ADRESS",adress);

    if(query.lastError().isValid())
    {qDebug()<<query.lastError();
        QMessageBox::information(0,"error","bug:add_client");}

    return query.exec();
}


bool Client:: delete_client(QString client_cin)
{
    QSqlQuery query;
    query.prepare("Delete from client where client_cin=:client_cin");
    query.bindValue(":client_cin",client_cin);
    return query.exec();
}

QSqlQueryModel * Client::view_client()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from clients");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("client_cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("name_client"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("phone_num"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("d-m-y"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("gender"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("adress"));
    return model;
}

/*QSqlQueryModel Client::research_client(QString client_cin)
{
    QSqlQueryModel model=new QSqlQueryModel();
    model->setQuery("select * from clients");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("name_client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("phone_num"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("d-m-y"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("gender"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("adress"));
    return model;
}
*/
//void Client:: update_client(Client*);
//void Client::view_purchaseHistory(Client);
//void Client::classify_client(Client);
//void Client::notify_about_delivery(Client);
