#ifndef DELIVERY_H
#define DELIVERY_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class delivery
{
    private :
    int package_num;
    QString delivery_date;
    int payement;
    QString destination;
    QString client_cin;
    QString  truck_id;

    public:
    delivery();
    delivery(int package_num,QString delivery_date,int payement,QString destination,QString client_cin,QString truck_id);
    bool create_delivery();
    QSqlQueryModel *view_delivery();
    bool update_delivery(int,QString,int,QString,QString,QString);
    bool delete_delivery(int);
    QSqlQueryModel * researchDelivery(QString);
    QSqlQueryModel *  view_tri_package_num();
     QSqlQueryModel *  view_tri_payement();
     QSqlQueryModel *  view_tri_date();








};

#endif // DELIVERY_H
