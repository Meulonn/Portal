#include "client.h"
#include "smtp.h"

client::client()
{
CLIENT_CIN="";
NAME_CLIENT="";
PHONE_NUM=0;
D=0;M=0;Y=0;
GENDER=0;
EMAIL="";
ADRESS="";
}

client:: client(QString CLIENT_CIN,QString NAME_CLIENT,long PHONE_NUM,int D,int M,int Y,int GENDER,QString EMAIL,QString ADRESS)
{
    this->CLIENT_CIN=CLIENT_CIN;
    this->NAME_CLIENT=NAME_CLIENT;
    this->PHONE_NUM=PHONE_NUM;
    this->D=D;
    this->M=M;
    this->Y=Y;
    this->GENDER=GENDER;
    this->EMAIL=EMAIL;
    this->ADRESS=ADRESS;
}

QString client:: get_cin(){return CLIENT_CIN;}
void client::set_cin(QString CLIENT_CIN){this->CLIENT_CIN=CLIENT_CIN;}
QString client::get_name(){return NAME_CLIENT;}
void client::set_name(QString NAME_CLIENT){this->NAME_CLIENT=NAME_CLIENT;}
long client::get_num(){return PHONE_NUM;}
void client::set_num(long PHONE_NUM){this->PHONE_NUM=PHONE_NUM;}
int client::get_d(){return D;}
void client::set_d(int D){this->D=D;}
int client::get_m(){return M;}
void client::set_m(int M){this->M=M;}
int client::get_y(){return Y;}
void client::set_y(int Y){this->Y=Y;}
int client::get_gender(){return GENDER;}
void client::set_gender(int GENDER){this->GENDER=GENDER;}
QString client::get_email(){return EMAIL;}
void client::set_email(QString EMAIL){this->EMAIL=EMAIL;}
QString client::get_adress(){return ADRESS;}
void client::set_adress(QString ADRESS){this->ADRESS=ADRESS;}

bool client::add_client()
{
   QSqlQuery query;

   QString phone_num_s= QString::number(PHONE_NUM);
   QString gender_s= QString::number(GENDER);
   QString d_s= QString::number(D);
   QString m_s= QString::number(M);
   QString y_s= QString::number(Y);

   query.prepare("INSERT INTO CLIENTS(CLIENT_CIN,NAME_CLIENT,PHONE_NUM,D,M,Y,GENDER,EMAIL,ADRESS)"
                 "VALUES(:CLIENT_CIN,:NAME_CLIENT,:PHONE_NUM,:D,:M,:Y,:GENDER,:EMAIL,:ADRESS)");
    query.bindValue(":CLIENT_CIN",CLIENT_CIN);
    query.bindValue(":NAME_CLIENT",NAME_CLIENT);
    query.bindValue(":PHONE_NUM",phone_num_s);
    query.bindValue(":D",d_s);
    query.bindValue(":M",m_s);
    query.bindValue(":Y",y_s);
    query.bindValue(":GENDER",gender_s);
    query.bindValue(":EMAIL",EMAIL);
    query.bindValue(":ADRESS",ADRESS);

    if(query.lastError().isValid())
    {qDebug()<<query.lastError();
        QMessageBox::information(0,"error","bug:add_client");}

    return query.exec();
}


bool client:: delete_client(QString client_cin)
{
    QSqlQuery query;
    query.prepare("Delete from clients where client_cin=:client_cin");
    query.bindValue(":client_cin",client_cin);
    return query.exec();
}


QSqlQueryModel * client::view_client()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENTS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CLIENT_CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NAME_CLIENT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PHONE_NUM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("D"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("M"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Y"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("GENDER"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("ADRESS"));
    return model;
}

bool client:: update_client(QString cin,long phone_num,QString email,QString adress)
{
QSqlQuery query;


QString phone_num_s= QString::number(phone_num);
int c=cin.toInt();
query.prepare("UPDATE CLIENTS set PHONE_NUM= :PHONE_NUM,EMAIL= :EMAIL,ADRESS= :ADRESS WHERE CLIENT_CIN= :cin ");
query.bindValue(":cin",c);
 query.bindValue(":PHONE_NUM",phone_num_s);
 query.bindValue(":EMAIL",email);
 query.bindValue(":ADRESS",adress);

 if(query.lastError().isValid())
 {qDebug()<<query.lastError();
     QMessageBox::information(0,"error","bug:add_client");}

 return query.exec();
}

QSqlQueryModel * client::research_client(QString cin)
{
 QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT NAME_CLIENT,PHONE_NUM,D,M,Y,GENDER,EMAIL,ADRESS FROM CLIENTS WHERE CLIENT_CIN = '"+cin+"' ");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NAME_CLIENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PHONE_NUM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("D"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("M"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Y"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("GENDER"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("ADRESS"));

    return model;

}

 QSqlQueryModel * client:: classify_client(QString d,QString m,QString g,QString adress)
 {
  QSqlQueryModel * model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM CLIENTS WHERE D='"+d+"' AND M='"+m+"' OR GENDER = '"+g+"'  OR ADRESS ='"+adress+"' ");
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("CLIENT_CIN"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("NAME_CLIENT"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("PHONE_NUM"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("D"));
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("M"));
  model->setHeaderData(5,Qt::Horizontal,QObject::tr("Y"));
  model->setHeaderData(6,Qt::Horizontal,QObject::tr("GENDER"));
  model->setHeaderData(7,Qt::Horizontal,QObject::tr("EMAIL"));
  model->setHeaderData(8,Qt::Horizontal,QObject::tr("ADRESS"));
  return model;

 }



