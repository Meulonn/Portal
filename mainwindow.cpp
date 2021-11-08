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


void MainWindow::on_pushButton_OK1_clicked()
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
if(client_cin==0)
    QMessageBox::information(0,"Add client","Please fill client_cin section.\n");
else if(name=="")
        QMessageBox::information(0,"Add client","Please fill name section.\n");
    else if((gender!=0)&&(gender!=1)&&(gender!=2))
            QMessageBox::information(0,"Add client","Please check gender section.\n");
        else {QString num= QString::number(phone_num);
            if(sizeof(num)!=8)
                QMessageBox::information(0,"Add client",num.length(),"Please fill phone_num section.\n");

            else if ((email=="")||(email.indexOf("@",sizeof(email))!=-1)||(email.indexOf(".com",sizeof(email))!=-1)
                                                                         ||(email.indexOf(".fr",sizeof(email))!=-1)
                                                                         ||(email.indexOf(".tn",sizeof(email))!=-1))
                    QMessageBox::information(0,"Add client","Please fill email section.\n");
                else if (adress=="")
                        QMessageBox::information(0,"Add client","Please fill adress section.\n");



else{
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
}}
