#include "test.h"
#include <QDebug>
#include <QVariant>
#include <QtSql/QSqlQuery>
test::test()
{
id="";
nom="";
}
test::test(QString id, QString nom){
    this->id=id;
    this->nom=nom;
}
QString test::getid(){return id;}
QString test::getnom(){return nom;}
bool test::ajout()
{
    QSqlQuery query;
    query.prepare("INSERT INTO test (id, nom)"
                  "VALUES (:id, :nom)");


    query.bindValue(":id",id);
    query.bindValue(":nom",nom);


    return query.exec();
}
QSqlQueryModel * test::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM test");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));


    return model;

}
