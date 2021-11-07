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

void MainWindow::male_checked()
{
        ui->male->setChecked(true);
        ui->female->setChecked(false);
        ui->other->setChecked(false);

}

void MainWindow::on_pushButton_add_clicked()
{
    long client_cin=ui->lineEdit_cin->text().toLong();
    QString name=ui->lineEdit_name->text();
    long phone_num=ui->lineEdit_num->text().toLong();
    QDate birthday;
            birthday.fromString(ui->dateEdit->text());
    int gender;
        if(ui->male->isChecked())
        {
            male_checked();
            gender=0;
        }

        /*else if(ui->female->isChecked())
        {
            ui->male->setChecked(false);
            ui->female->setChecked(true);
            ui->other->setChecked(false);
            gender=1;
         }
        else if(ui->other->isChecked())
        {
            ui->male->setChecked(false);
            ui->female->setChecked(false);
            ui->other->setChecked(true);
            gender=2;
         }*/



    //=ui->female->checkState();//0=male/1=female/2=other
    QString email=ui->lineEdit_email->text();
    QString adress=ui->lineEdit_adress->text();

    Client C(client_cin,name,phone_num,birthday,gender,email,adress);

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
