
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QTextDocument>
#include <QTextStream>
#include <QComboBox>
#include <QTabWidget>
#include"QDate"
#include <QDebug>
#include <list>
#include "test.h"
#include "delivery.h"
#include <QTextBrowser>
#include<QSystemTrayIcon>
#include<QComboBox>
#include<QDebug>
#include<QDate>
#include"ExcelExportHelper.h"
#include <QPrinter>
#include <QtPrintSupport/QPrinter>
#include<QPrintDialog>
#include <QDate>
#include<QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QPdfWriter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);

     ui->DeliveryDetails->setModel(d.view_delivery());

     QSqlQueryModel * model= new QSqlQueryModel;
     model->setQuery("SELECT CLIENT_CIN FROM CLIENTS");
     ui->comboBox_client->setModel(model);
     qDebug()<<(model->rowCount());

     QSqlQueryModel * model1= new QSqlQueryModel;
     model1->setQuery("SELECT TRUCK_ID FROM TRUCK");
     ui->comboBox_truck->setModel(model1);
     qDebug()<<(model1->rowCount());


     ui->lineEdit_rechercher->setPlaceholderText(QString("Research"));



}

MainWindow::~MainWindow()
{

    delete ui;

}
bool MainWindow::search(int package_num)
{
    bool test=false;
    for(int i=0;i<ui->DeliveryDetails->model()->rowCount();i++)
        if(ui->DeliveryDetails->model()->index(i,0).data().toInt()==package_num)
        {
            test=true;
        }
    return test;
}
void MainWindow::on_add_clicked()
{

int package_num=ui->lineEdit_4_PackageNumber->text().toInt();
  QString delivery_date=ui->dateEdit->text();
   int payement=ui->lineEdit_5_Payment->text().toFloat();
  QString destination=ui->comboBox_destination->currentText();
   QString client_cin=ui->comboBox_client->currentText();
   QString truck_id=ui->comboBox_truck->currentText();
  delivery d(package_num, delivery_date,  payement,  destination,  client_cin,truck_id) ;

if((package_num==0)||(delivery_date=="")||(payement==0)||(destination=="")||(client_cin=="")||(truck_id==""))
{
   QMessageBox::information(nullptr,QObject::tr("Add a delivery"),QObject::tr("Please fill in the fields"),QMessageBox::Ok);
}

 else
{

bool test=d.create_delivery();
 if(test)
{


    QMessageBox::information(nullptr, QObject::tr("delivery added"),
                QObject::tr("delivery added.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    ui->DeliveryDetails->setModel(d.view_delivery());
}

else
 {        QMessageBox::critical(nullptr, QObject::tr("delivery not added"),
                                   QObject::tr("delivery not added.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}
}


}
void MainWindow::on_update_clicked()
{
    int package_num = ui->lineEdit_4_PackageNumber->text().toInt();
     QString delivery_date = ui->dateEdit->text();
     int payement = ui->lineEdit_5_Payment->text().toFloat();
      QString destination = ui->comboBox_destination->currentText();
      QString client_cin =ui->comboBox_client->currentText();
      QString truck_id= ui->comboBox_truck->currentText();
      if((package_num==0)||(delivery_date=="")||(payement==0.0)||(destination=="")||(client_cin==""))//||(truck_id==""))
      {
         QMessageBox::information(nullptr,QObject::tr("Add a delivery"),QObject::tr("Please fill in the fields"),QMessageBox::Ok);
      }
      delivery d;

      bool test=d.update_delivery(package_num,delivery_date,payement,destination,client_cin,truck_id);
      if(test)
      {ui->DeliveryDetails->setModel(d.view_delivery());
          QMessageBox::information(nullptr, QObject::tr("delivery updated"),
                      QObject::tr("delivery updated.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      }
      else
       {        QMessageBox::critical(nullptr, QObject::tr("delivery not updated"),
                                         QObject::tr("delivery not updated.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
      }
      }


void MainWindow::on_delete_2_clicked()
{
    delivery d;

    int package_num=ui->lineEdit_4_PackageNumber->text().toInt();
    qDebug()<<package_num;
    bool test1=search(package_num);
    if(test1==false)
    {

        QMessageBox::critical(nullptr, QObject::tr("delivery not deleted"),
                              QObject::tr("package_num inexsit .\n"
                                          "Click Cancek to exit"), QMessageBox::Cancel);
    }
    else
    {
       bool test2=d.delete_delivery(package_num);
           if(test2)
           {

               QMessageBox::information(nullptr, QObject::tr("delivery deleted"),
                                        QObject::tr("delivery deleted.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
           ui->DeliveryDetails->setModel(d.view_delivery());}
           else{
               QMessageBox::critical(nullptr, QObject::tr("delivery not deleted"),
                                     QObject::tr("delivery not deleted .\n"
                                                 "Click Cancek to exit"), QMessageBox::Cancel);
}
    }
}



void MainWindow::on_DeliveryDetails_clicked()
{
    int package_num=ui->DeliveryDetails->model()->data(ui->DeliveryDetails->model()->index(ui->DeliveryDetails->currentIndex().row(),0)).toInt();
        QString package_num1=QString::number(package_num);
        ui->lineEdit_4_PackageNumber->setText(package_num1);
        QDate delivery_date=ui->DeliveryDetails->model()->data(ui->DeliveryDetails->model()->index(ui->DeliveryDetails->currentIndex().row(),1)).toDate();
        ui->dateEdit->setDate(delivery_date);
        int payement=ui->DeliveryDetails->model()->data(ui->DeliveryDetails->model()->index(ui->DeliveryDetails->currentIndex().row(),2)).toInt();
        QString payement1=QString::number(payement);
        ui->lineEdit_5_Payment->setText(payement1);
        QString destination=ui->DeliveryDetails->model()->data(ui->DeliveryDetails->model()->index(ui->DeliveryDetails->currentIndex().row(),3)).toString();
        ui->comboBox_destination->setCurrentText(destination);
        QString client_cin=ui->DeliveryDetails->model()->data(ui->DeliveryDetails->model()->index(ui->DeliveryDetails->currentIndex().row(),4)).toString();
        ui->comboBox_client->setCurrentText(client_cin);
        QString truck_id=ui->DeliveryDetails->model()->data(ui->DeliveryDetails->model()->index(ui->DeliveryDetails->currentIndex().row(),5)).toString();
        ui->comboBox_truck->setCurrentText(truck_id);
}

void MainWindow::on_lineEdit_rechercher_textChanged()
{
    //delivery d;
    QString rech=ui->lineEdit_rechercher->text();
      ui->DeliveryDetails->setModel(d.researchDelivery(rech));
}

void MainWindow::on_classify_clicked()
{
    QString classify=ui->comboBox->currentText();
   if(classify=="By Package_Number")
       ui->DeliveryDetails->setModel(d.view_tri_package_num());
   else if(classify=="By Payement")
       ui->DeliveryDetails->setModel(d.view_tri_payement());
   else if(classify=="By date")
       ui->DeliveryDetails->setModel(d.view_tri_date());
}

void MainWindow::on_pushButton_5_clicked()
{
    try
    {
        const QString fileName = "g:\\temp\\kaka2.xlsx";

        ExcelExportHelper helper;

        helper.SetCellValue(1,1,"PACKAGE_NUM");
        helper.SetCellValue(1,2,"DELIVERY_DATE");
        helper.SetCellValue(1,3,"PAYEMENT");
        helper.SetCellValue(1,4,"DESTINATION");
        helper.SetCellValue(1,5,"CLIENT_CIN");
        helper.SetCellValue(1,6,"TRUCK_ID");
        int j=2;
        //int a=ui->DeliveryDetails->model()-index
        for(int i=0;i<ui->DeliveryDetails->model()->rowCount();i++)
        {
            helper.SetCellValue(j,1,ui->DeliveryDetails->model()->index(i,0).data().toString());
            helper.SetCellValue(j,2,ui->DeliveryDetails->model()->index(i,1).data().toString());
            helper.SetCellValue(j,3,ui->DeliveryDetails->model()->index(i,2).data().toString());
            helper.SetCellValue(j,4,ui->DeliveryDetails->model()->index(i,3).data().toString());
            helper.SetCellValue(j,5,ui->DeliveryDetails->model()->index(i,4).data().toString());
            helper.SetCellValue(j,6,ui->DeliveryDetails->model()->index(i,5).data().toString());
            j++;

        }
        helper.SaveAs(fileName);
    }
    catch(_exception ex)
    {}

}


void MainWindow::on_pushButton_7_clicked()
{
    mailling=new mailing(this);
    mailling->show();
}

void MainWindow::on_pushButton_clicked()
{
    QString strStream;
                         QTextStream out(&strStream);

                         const int rowCount = ui->DeliveryDetails->model()->rowCount();
                         const int columnCount = ui->DeliveryDetails->model()->columnCount();
                         QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                         QString DD=QDateTime::currentDateTime().toString();
                         out <<"<html>\n"
                               "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             << "<title>ERP - DELIVERIES LIST<title>\n "
                             << "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                             "<h1 style=\"text-align: center;\"><strong> ******LISTE DES COMMANDES ******"+TT+" </strong></h1>"
                             "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                               "</br> </br>";
                         // headers
                         out << "<thead><tr bgcolor=#d6e5ff>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->DeliveryDetails->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->DeliveryDetails->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->DeliveryDetails->isColumnHidden(column)) {
                                     QString data =ui->DeliveryDetails->model()->data(ui->DeliveryDetails->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table>\n"
                             "</body>\n"
                             "</html>\n";

                         QTextDocument *document = new QTextDocument();
                         document->setHtml(strStream);

                         QPrinter printer;

                         QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                         if (dialog->exec() == QDialog::Accepted) {
                             document->print(&printer);
                         }

                         delete document;
}
