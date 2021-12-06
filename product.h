#ifndef PRODUCT_H
#define PRODUCT_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QRegularExpression>

class product
{
public:
    void setid(int n);
    void setprice(float n);
    void setname(QString n);
    void setquantity(int n);
    void setstate(int n);
    void setprovider(QString n);
    void setproviderEmail(QString n);

    int get_id(){return id;}
    float get_price(){return price;}
    QString get_name(){return name;}
    int get_quantity(){return quantity;}
    int get_state(){return state;}
    QString get_provider(){return provider;}
    QString get_providerEmail(){return providerEmail;}
    QSqlQueryModel * research (const QString &aux);
    QSqlQueryModel * triid(QString y);
    QSqlQueryModel * triname(QString y);
    QSqlQueryModel * triprice(QString y);


    bool add_product();
    QSqlQueryModel * view_product();
    bool supprimer(int id);
    bool Modify(int id, float price, QString name, int quantity, int state, QString provider, QString providerEmail);

    product();
    product(int id,float price,QString name,int quantity,int state,QString provider, QString providerEmail);

private:
    QString  name,provider,providerEmail;
    float price;
    int quantity,state,id;
};

#endif // PRODUCT_H
