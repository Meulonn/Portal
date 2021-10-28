#include "addproduct.h"
#include "ui_addproduct.h"
#include "product.h"
addProduct::addProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addProduct)
{
    ui->setupUi(this);
}

addProduct::~addProduct()
{
    delete ui;
}

void addProduct::on_pushButton_clicked()
{
product p;
p.setid(ui->label->text());
p.setprice(ui->label_2->text());
p.setname(ui->label_3->text());
p.setquantity(ui->label_4->text());
}
