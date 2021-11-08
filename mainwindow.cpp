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
    int d=ui->lineEdit_d->text().toInt();
    int m=ui->lineEdit_m->text().toInt();
    int y=ui->lineEdit_y->text().toInt();
    int gender;
        if(ui->radioButton_male->isChecked())
            gender=0;
        if(ui->radioButton_female->isChecked())
            gender=1;
        if(ui->radioButton_other->isChecked())
            gender=2;

    QString email=ui->lineEdit_email->text();
    QString adress=ui->lineEdit_adress->text();

    QString a="@";
    QString com=".com";QString fr=".fr";QString tn=".tn";QString net=".net";QString io=".io";
    QString cin= QString::number(client_cin);
    QString num= QString::number(phone_num);

if(cin.length()!=8)
    QMessageBox::information(0,"Add client","Please fill client_cin section.\n");
else if(name=="")
        QMessageBox::information(0,"Add client","Please fill name section.\n");
    else if(((d<1)||(d>31))||((m<1)||(m>12))||((y<1950)||(y>2021)))
            QMessageBox::information(0,"Add client","check birthday.\n");
         else if((gender!=0)&&(gender!=1)&&(gender!=2))
             QMessageBox::information(0,"Add client","Please check gender section.\n");
            else if(num.length()!=8)
                  QMessageBox::information(0,"Add client","Please fill phone_num section.\n");
                else if((d==0)||(m==0)||(y==0))
                        QMessageBox::information(0,"Add client","Please fill birthday section.\n");
                     else if (adress=="")
                              QMessageBox::information(0,"Add client","Please fill adress section.\n");
                         else if (email=="")
                                 QMessageBox::information(0,"Add client","Please fill email section.\n");
                             else if (email.indexOf(a,0)==-1)
                                     QMessageBox::information(0,"Add client","@ is missing\n");
                                 else if ((email.indexOf(com,0)==-1)&&(email.indexOf(fr,0)==-1)&&(email.indexOf(tn,0)==-1)&&(email.indexOf(net,0)==-1)&&(email.indexOf(io,0)==-1))
                                          QMessageBox::information(0,"Add client",".com OR .fr OR .tn OR .net OR .io is missing\n");




else{

    Client C(client_cin,name,phone_num,d,m,y,gender,email,adress);
    bool test=C.add_client();
    if(test)
        QMessageBox::information(0,"test","vrai");
    else QMessageBox::information(0,"test","faux");


    if(test)
    {
        QMessageBox::information(0,"Add client","new client is added.\n");
                                 //"Click Cancel to exit."),QMessageBox::Cancel);

    }
    else QMessageBox::critical(0,"Add client","new client is not added.\n");
                                          // "Click Cancel to exit."),QMessageBox::Cancel);

}
}
