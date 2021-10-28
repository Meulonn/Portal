#include "product.h"

product::product()
{
id="";
price="";
name="";
quantity="";
}



void product::setid(QString n){id=n;}
void product::setprice(QString n){price=n;}
void product::setname(QString n){name=n;}
void product::setquantity(QString n){quantity=n;}

QString product::get_id(){return id;}
QString product::get_price(){return price;}
QString product::get_name(){return name;}
QString product::get_quantity(){return quantity;}



