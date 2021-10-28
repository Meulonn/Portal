#ifndef PRODUCT_H
#define PRODUCT_H
#include<QString>

class product
{
public:
    void setid(QString n);
    void setprice(QString n);
    void setname(QString n);
    void setquantity(QString n);
    QString get_id();
    QString get_price();
    QString get_name();
    QString get_quantity();
    product();

private:
    QString id, price, name, quantity;
};

#endif // PRODUCT_H
