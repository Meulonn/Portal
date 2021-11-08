#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_OK1()
{
    long client_cin=ui->lineEdit_cin->text().toLong();
    QString name=ui->lineEdit_name->text();
    long phone_num=ui->lineEdit_num->text().toLong();
    QDate birthday;
            birthday.fromString(ui->dateEdit->text());
    int gender;
        if(ui->radioButton_male->isChecked())
            gender=0;
        if(ui->radioButton_female->isChecked())
            gender=1;
        if(ui->radioButton_other->isChecked())
            gender=2;

    QString email=ui->lineEdit_email->text();
    QString adress=ui->lineEdit_adress->text();
//email@
while((client_cin==0)||(name=="")||(phone_num==0)||(sizeof (phone_num)!=8)||(gender!=0)||(gender!=1)||(gender!=2)||(email=="")||(adress==""))
{
    QMessageBox::information(nullptr,QObject::tr("Add client"),
                 QObject::tr("Please fill all the fields.\n"),QMessageBox::Ok);

  }
    Client C(client_cin,name,phone_num,birthday,gender,email,adress);
QMessageBox::information(0,"test","tessst");
    bool test=C.add_client();
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                     QObject::tr("new client is added\n"
                                 "Click Cancel to exit."),QMessageBox::Cancel);

    }
    else QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                               QObject::tr("not added\n"
                                           "Click Cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_pushButton_ooo_clicked()
{bool test=(1<2);
    if(test)
       QMessageBox::information(0,"test","tessst1");
}
