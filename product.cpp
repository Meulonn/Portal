#include "product.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QApplication>
#include <QSqlDatabase>
#include <QObject>
#include <QFile>
#include <QIntValidator>
#include <QSqlError>




void product::setid(int n){id=n;}
void product::setprice(float n){price=n;}
void product::setname(QString n){name=n;}
void product::setquantity(int n){quantity=n;}
void product::setstate(int n){state=n;}
void product::setprovider(QString n){provider=n;}
void product::setproviderEmail(QString n){providerEmail=n;}




product::product()
{
    id=0;
    price=0;
    name="";
    quantity=0;
    state=0;
    provider="";
    providerEmail="";
}
product::product(int i,float p,QString n,int q,int s,QString pro,QString proE)
{
    id=i;
    price=p;
    name=n;
    quantity=q;
    state=s;
    provider=pro;
    providerEmail=proE;

}


bool product::add_product()
{
    QSqlQuery query;
    QString price_s= QString::number(price);
    QString quantity_s= QString::number(quantity);
    QString state_s= QString::number(state);



          query.prepare("INSERT INTO PRODUCT (PRODUCT_ID, PROVIDER_NAME, QUANTITY, PRICE , PROVIDER_EMAIL, PRODUUCT_STATUS ,PRODUCT_NAME) "
                        "VALUES (:ID, :PROVIDER, :QUANTITY, :PRICE, :PROVIDEREMAIL, :STATE, :NAME )");
          query.bindValue(":ID",id);
          query.bindValue(":PRICE",price_s);
          query.bindValue(":NAME",name);
          query.bindValue(":QUANTITY",quantity_s);
          query.bindValue(":STATE", state_s);
          query.bindValue(":PROVIDER", provider);
          query.bindValue(":PROVIDEREMAIL",providerEmail);

          if (query.lastError().isValid())
              qDebug() << query.lastError();
         return query.exec();

}

QSqlQueryModel * product::view_product()
 {
     QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM PRODUCT");
          model->setHeaderData(0, Qt::Horizontal,  QObject::tr("PRODUCT_ID"));
          model->setHeaderData(1, Qt::Horizontal,  QObject::tr("PROVIDER_NAME"));
          model->setHeaderData(2, Qt::Horizontal,  QObject::tr("QUANTITY"));
          model->setHeaderData(3, Qt::Horizontal,  QObject::tr("PRICE"));
          model->setHeaderData(4, Qt::Horizontal,  QObject::tr("PROVIDER_EMAIL"));
          model->setHeaderData(5, Qt::Horizontal,  QObject::tr("PRODUUCT_STATUS"));
          model->setHeaderData(6, Qt::Horizontal,  QObject::tr("PRODUCT_NAME"));
     return model;
 }

bool product::supprimer(int IDE)
 {
     QSqlQuery query;
     qDebug() << IDE;

     query.prepare("DELETE FROM PRODUCT WHERE PRODUCT_ID= :id ");
     query.bindValue(":id",IDE);
     return query.exec();
 }


bool product::Modify(int id, float price, QString name, int quantity, int state, QString provider, QString providerEmail)
 {
     QSqlQuery query;
     QString id_s= QString::number(id);
     QString price_s= QString::number(price);
     QString quantity_s= QString::number(quantity);
     QString state_s= QString::number(state);
     query.prepare("update PRODUCT set PRODUCT_ID=:id,PROVIDER_NAME=:provider,QUANTITY=:quantity,PRICE=:price,PROVIDER_EMAIL=:providerEmail,PRODUUCT_STATUS=:state,PRODUCT_NAME=:name where PRODUCT_ID=:id");
     query.bindValue(":id",id_s);
     query.bindValue(":name",name);
     query.bindValue(":provider",provider);
     query.bindValue(":quantity",quantity_s);
     query.bindValue(":price", price_s);
     query.bindValue(":providerEmail", providerEmail);
     query.bindValue(":state",state_s);
     return query.exec();

 }


QSqlQueryModel * product::research (const QString &aux)

{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from PRODUCT where ((PRODUCT_ID || PROVIDER_NAME || QUANTITY || PRICE || PROVIDER_EMAIL || PRODUUCT_STATUS || PRODUCT_NAME) LIKE '%"+aux+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("provider"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantity"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("price"));
    model->setHeaderData(4, Qt::Horizontal,  QObject::tr("providerEmail"));
    model->setHeaderData(5, Qt::Horizontal,  QObject::tr("state"));
    model->setHeaderData(6, Qt::Horizontal,  QObject::tr("name"));


    return model;

}
    QSqlQueryModel * product::triid(QString y)
    {



        QSqlQueryModel* model=new QSqlQueryModel();
             model->setQuery("SELECT* FROM PRODUCT ORDER BY PRODUCT_ID"+y);
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
             model->setHeaderData(1, Qt::Horizontal,  QObject::tr("provider"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantity"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("price"));
             model->setHeaderData(4, Qt::Horizontal,  QObject::tr("providerEmail"));
             model->setHeaderData(5, Qt::Horizontal,  QObject::tr("state"));
             model->setHeaderData(6, Qt::Horizontal,  QObject::tr("name"));


        return  model;
    }

    QSqlQueryModel * product::triname(QString y)
    {
        QSqlQueryModel* model=new QSqlQueryModel();
             model->setQuery("SELECT* FROM PRODUCT ORDER BY PRODUCT_NAME"+y);
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
             model->setHeaderData(1, Qt::Horizontal,  QObject::tr("provider"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantity"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("price"));
             model->setHeaderData(4, Qt::Horizontal,  QObject::tr("providerEmail"));
             model->setHeaderData(5, Qt::Horizontal,  QObject::tr("state"));
             model->setHeaderData(6, Qt::Horizontal,  QObject::tr("name"));


        return  model;
    }

    QSqlQueryModel * product::triprice(QString y)
    {
        QSqlQueryModel* model=new QSqlQueryModel();
             model->setQuery("SELECT* FROM PRODUCT ORDER BY PRICE"+y);
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
             model->setHeaderData(1, Qt::Horizontal,  QObject::tr("provider"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantity"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("price"));
             model->setHeaderData(4, Qt::Horizontal,  QObject::tr("providerEmail"));
             model->setHeaderData(5, Qt::Horizontal,  QObject::tr("state"));
             model->setHeaderData(6, Qt::Horizontal,  QObject::tr("name"));


        return  model;
    }
