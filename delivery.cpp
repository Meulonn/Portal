#include"delivery.h"
#include <QDebug>
#include <iostream>
#include <list>
#include <QString>
#include<QDate>
delivery::delivery()
{
    package_num=0;
    delivery_date="";
    payement=0;
    destination="";
    client_cin="";
    truck_id="";
}
delivery::delivery(int package_num, QString delivery_date, int payement, QString destination, QString client_cin, QString truck_id)
{
    this->package_num=package_num;
    this->delivery_date=delivery_date;
    this->payement=payement;
    this->destination=destination;
    this->client_cin=client_cin;
    this->truck_id=truck_id;

}

bool delivery::create_delivery()
{

    QSqlQuery query;
    QString string_package_num = QString::number(package_num);
    QString string_payment = QString::number(payement);

    query.prepare("INSERT INTO DELIVERIES (PACKAGE_NUM,DELIVERY_DATE,PAYEMENT,DESTINATION,CLIENT_CIN,TRUCK_ID) "
                  "VALUES (:0,:1,:2,:3,:4,:5)");
    query.bindValue(":0",string_package_num);
    query.bindValue(":1",delivery_date);
    query.bindValue(":2",string_payment);
    query.bindValue(":3",destination);
    query.bindValue(":4",client_cin);
    query.bindValue(":5",truck_id);




      return query.exec();
}
QSqlQueryModel * delivery::view_delivery()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM DELIVERIES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("PACKAGE_NUM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DELIVERY_DATE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYEMENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESTINATION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CLIENT_CIN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("TRUCK_ID"));



    return model;
}
bool delivery::update_delivery(int package_num, QString delivery_date, int payement, QString destination,QString client_cin,QString truck_id)
{
    QSqlQuery query;
    query.prepare("UPDATE DELIVERIES SET DELIVERY_DATE=:delivery_date,PAYEMENT=:payement,DESTINATION=:destination,CLIENT_CIN=:client_cin,TRUCK_ID=:truck_id WHERE (PACKAGE_NUM=:package_num  )");
    query.bindValue(":package_num",package_num);
    query.bindValue(":delivery_date",delivery_date);
    query.bindValue(":payement",payement);
    query.bindValue(":destination",destination);
    query.bindValue(":client_cin",client_cin);
    query.bindValue(":truck_id",truck_id);
    return query.exec();
}
bool delivery::delete_delivery( int package_num)
{
    QSqlQuery query;
    query.prepare("DELETE FROM DELIVERIES WHERE PACKAGE_NUM = :package_num ");
    query.bindValue(":package_num", package_num);

    return  query.exec();
}
QSqlQueryModel * delivery::researchDelivery(QString recherche)
{
    QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM DELIVERIES WHERE PACKAGE_NUM LIKE '"+recherche+"%' OR CLIENT_CIN LIKE '"+recherche+"%' OR TRUCK_ID LIKE '"+recherche+"%'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("PACKAGE_NUM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DELIVERY_DATE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYEMENT"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESTINATION"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("CLIENT_CIN"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("TRUCK_ID"));

        return model;
}
QSqlQueryModel * delivery:: view_tri_package_num()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT *FROM DELIVERIES  ORDER BY PACKAGE_NUM ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("PACKAGE_NUM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DELIVERY_DATE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYEMENT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESTINATION"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("CLIENT_CIN"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("TRUCK_ID"));
return model;
}
QSqlQueryModel *delivery:: view_tri_payement()
{
 QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT *FROM DELIVERIES  ORDER BY PAYEMENT ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("PACKAGE_NUM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DELIVERY_DATE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYEMENT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESTINATION"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("CLIENT_CIN"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("TRUCK_ID"));
return model;
 }
QSqlQueryModel *delivery:: view_tri_date()
{
    QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("SELECT *FROM DELIVERIES  ORDER BY DELIVERY_DATE DESC ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("PACKAGE_NUM"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("DELIVERY_DATE"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYEMENT"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESTINATION"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("CLIENT_CIN"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("TRUCK_ID"));
   return model;
}
