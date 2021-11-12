#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Agent.h"
#include <QIntValidator>
#include <QSqlError>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   Agent a;
    ui->setupUi(this);
    ui->lineEditCIN->setValidator( new QIntValidator(00000000, 99999999, this));
    ui->lineEditsupprimer->setValidator( new QIntValidator(00000000, 99999999, this));
    ui->lineEdit_position->setValidator( new QIntValidator(1,4, this));
    ui->lineEdit_numberofabsences->setValidator( new QIntValidator(1,4, this));
    ui->lineEdit_Salary->setValidator(new QIntValidator(300,50000,this));
    ui->lineEditchercher->setValidator( new QIntValidator(00000000, 99999999, this));
    ui->tab_agents->setModel(a.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_supprimer_clicked()
{
    int id_s=ui->lineEditsupprimer->text().toInt();
    qDebug()<< id_s;
    bool test=a.supprimer(id_s);
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("task finished"),
        QObject::tr("Deleted successfully.\n"
                    "Click cancel to exit."), QMessageBox::Cancel);
         ui->tab_agents->setModel(a.afficher());
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("task failed"),
                              QObject::tr("deletion failed.\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_comfirm_clicked()
{
Agent a;
a.setCin(ui->lineEditCIN->text().toInt());
a.setName(ui->lineEdit_name->text());
a.setadress(ui->lineEdit_adress->text());
a.setEmail(ui->lineEdit_email->text());
a.setSalary(ui->lineEdit_Salary->text().toInt());
a.setposition(ui->lineEdit_position->text().toInt());
a.setNumberofabsences(ui->lineEdit_numberofabsences->text().toInt());
a.setadmissiondate(ui->dateEdit->text());

bool test1=a.validEmail(a.getEmail());
if(test1)
{

    bool test=a.ajouter();

if(test)
{
    QMessageBox::information(nullptr,QObject::tr("agent added"),
    QObject::tr("Added successfully.\n"
                "Click cancel to exit."), QMessageBox::Cancel);
    ui->tab_agents->setModel(a.afficher());
}
else
    QMessageBox::critical(nullptr,QObject::tr("Error message"),
                          QObject::tr("failed to add Agent"
                                      "Click Cancel to exit."),QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr,QObject::tr("Error message"),
                          QObject::tr("Check your email adress , "
                                      "Click Cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_modify_clicked()
{
    int cin = ui->lineEditcinmodifier->text().toInt();
    QString nom = ui->lineEditnamemodifier->text();
    QString date = ui->dateEdit_2->text();
    int numberofabsences = ui->lineEditnumberofabsencesmodifier->text().toInt();
    QString adress = ui->lineEditadressmodifier->text();
    int position = ui->lineEditpositionmodifier->text().toInt();
    float salary = ui->lineEditsalarymodifier->text().toInt();
    QString email = ui->lineEditemailmodifier->text();

    bool test1=a.validEmail(email);
    if (test1)
    {
    if (cin==0)
    {

        QMessageBox::information(nullptr,QObject::tr("Add an agent"),
        QObject::tr("Please fill all fields.\n"
                    "Click cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        Agent a ;
        bool test=a.modifier(cin,nom,adress,email,position,numberofabsences,salary,date);
        if (test)
        {
            ui->tab_agents->setModel(a.afficher());
            QMessageBox::information(nullptr,QObject::tr("Modify Agent"),
            QObject::tr("Modified Successfully.\n"
                        "Click cancel to exit."), QMessageBox::Cancel);

            ui->tab_agents->setModel(a.afficherCIN());
            ui->tab_agents->setModel(a.afficher());
        }
            else
                QMessageBox::critical(nullptr, QObject::tr("Modify Agent "),
                                      QObject::tr("Error !\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
        }
    else

    {
        QMessageBox::critical(nullptr, QObject::tr("Modify Agent "),
                              QObject::tr("Adress wrong !\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_Chercher_clicked()
{
    Agent a;
    QString A= ui->lineEditchercher->text();
    ui->tab_recherche->setModel(a.rechercher(A));
}
