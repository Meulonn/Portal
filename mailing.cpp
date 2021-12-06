#include "mailing.h"
#include "ui_mailing.h"
#include<QSqlQueryModel>
#include<QDebug>
#include<QString>
#include"smtp.h"



mailing::mailing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mailing)
{
    ui->setupUi(this);
    QSqlQueryModel * model= new QSqlQueryModel;
    model->setQuery("SELECT EMAIL FROM CLIENTS");
    ui->comboboxEmail->setModel(model);
    qDebug()<<(model->rowCount());

}

mailing::~mailing()
{
    delete ui;
}

void mailing::on_sendmail_clicked()
{
    Smtp* smtp = new Smtp("stationsmart2021@gmail.com","dali123***","smtp.gmail.com",465);
    QString object=ui->lineEdit_object->text();
    QString email=ui->comboboxEmail->currentText();
    QString message=ui->message->toPlainText();

                connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
                smtp->sendMail("stationsmart2021@gmail.com","trabelsi.dali484@gmail.com",object,message);
}
