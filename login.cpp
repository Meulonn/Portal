#include "login.h"
#include "ui_login.h"
#include"login.h"
#include <QSqlQuery>
#include "mainwindow.h"
#include<QMessageBox>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}



void login::on_Login_dali_clicked()
{
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_password->text();
    if(username=="" || password=="")
    {
QMessageBox::critical(nullptr,QObject::tr("Signin"),QObject::tr("Please fill in the fields"),QMessageBox::Ok);
    }
    QSqlQuery qry;
    if(qry.exec("SELECT * FROM DELIVERIES_AGENT WHERE USERNAME='"+username+ "' AND PASSWORD='"+password+"'"))
   {

        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {    QMessageBox::information(nullptr,QObject::tr("Signin"),QObject::tr("connected successfully"),QMessageBox::Ok);
        //this->hide();
        //MainWindow mainwindow;
        //mainwindow.setModal(true);
        //mai0nwindow.exc()
        mainwindow=new MainWindow(this);
        mainwindow->show();

        }
        else

QMessageBox::critical(nullptr,QObject::tr("Signin"),QObject::tr("username and password are not correct"),QMessageBox::Ok);

    }
}
