#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "product.h"
#include <QIntValidator>
#include <QSqlError>
#include <QMessageBox>
#include <QApplication>
#include <QStringList>
#include <QPdfWriter>
#include <QPainter>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QLabel>
#include <QtPrintSupport/QPrintDialog>
#include <QDebug>
//#include <QtCharts>
#include <QFile>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableProduct->setModel(p.view_product());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    product p;
    p.setid(ui->lineEditID->text().toInt());
    p.setquantity(ui->lineEditPname->text().toInt());
    p.setprice(ui->lineEditPrice->text().toFloat());
    p.setname(ui->lineEditPname->text());
    p.setstate(ui->lineEditPstate->text().toInt());
    p.setprovider(ui->lineEditProname->text());
    p.setproviderEmail(ui->lineEditProE->text());
    bool test=p.add_product();

    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("product added"),
        QObject::tr("Added successfully.\n"
                    "Click cancel to exit."), QMessageBox::Cancel);
        ui->tableProduct->setModel(p.view_product());
        // Création d'un objet QFile
            QFile file("C:\\Users\\mahdo\\Desktop\\Qt.txt");
            // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
                return;
            // Création d'un objet QTextStream à partir de notre objet QFile
            QTextStream flux(&file);
            // On choisit le codec correspondant au jeu de caractères que l'on souhaite ; ici, UTF-8
            flux.setCodec("UTF-8");
            // Écriture des différentes lignes dans le fichier

            flux <<"Name:"<< ui->lineEditPname->text() <<" , "<<"Providername:" << ui->lineEditProname->text()<< " Added."<<endl ;
            file.close();

}
else
    QMessageBox::critical(nullptr,QObject::tr("Error message"),
                          QObject::tr("failed to add Agent"
                                      "Click Cancel to exit."),QMessageBox::Cancel);
}








void MainWindow::on_pushButton_4_clicked()
{
    int IDS=ui->lineEditDelete->text().toInt();
        qDebug()<< IDS;
        bool test=p.supprimer(IDS);
        if(test)
        {
            QMessageBox::information(nullptr,QObject::tr("task finished"),
            QObject::tr("Deleted successfully.\n"
                        "Click cancel to exit."), QMessageBox::Cancel);
             ui->tableProduct->setModel(p.view_product());
             // Création d'un objet QFile
                 QFile file("C:\\Users\\mahdo\\Desktop\\Qt.txt");
                 // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
                 if (!file.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
                     return;
                 // Création d'un objet QTextStream à partir de notre objet QFile
                 QTextStream flux(&file);
                 // On choisit le codec correspondant au jeu de caractères que l'on souhaite ; ici, UTF-8
                 flux.setCodec("UTF-8");
                 // Écriture des différentes lignes dans le fichier

                 flux <<"ID:"<< ui->lineEditDelete->text() << " Deleted."<<endl ;
                 file.close();
    }
        else
            QMessageBox::critical(nullptr,QObject::tr("task failed"),
                                  QObject::tr("deletion failed.\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
    }

void MainWindow::on_Modify_clicked()
{
    int id = ui->productidM->text().toInt();
    int quantity = ui->quantityM->text().toInt();
    float price = ui->priceM->text().toFloat();
    QString name = ui->productnameM->text();
    int state = ui->productstatusM->text().toInt();
    QString provider = ui->providernameM->text();
    QString providerEmail = ui->ProvideremailM->text();
    product p(id,price,name,quantity,state,provider, providerEmail);
    bool test=p.Modify(id,price,name,quantity,state,provider,providerEmail);

    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("product modified"),
        QObject::tr("modified successfully.\n"
                    "Click cancel to exit."), QMessageBox::Cancel);
        ui->tableProduct->setModel(p.view_product());
        // Création d'un objet QFile
            QFile file("C:\\Users\\mahdo\\Desktop\\Qt.txt");
            // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
                return;
            // Création d'un objet QTextStream à partir de notre objet QFile
            QTextStream flux(&file);
            // On choisit le codec correspondant au jeu de caractères que l'on souhaite ; ici, UTF-8
            flux.setCodec("UTF-8");
            // Écriture des différentes lignes dans le fichier

            flux <<"Name:"<< ui->lineEditPname->text() <<" , "<<"Providername:" << ui->lineEditProname->text()<< " Modified."<<endl ;
            file.close();
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Error message"),
                              QObject::tr("failed to modify product"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
    }








void MainWindow::on_recherche_clicked()
{

        product p;
        QString A=ui->lineEditrecherche->text();
        ui->tableProduct->setModel(p.research(A));
        if(A=="")
                ui->tableProduct->setModel(p.view_product());
    }

void MainWindow::on_Tri_clicked()
{
    QString y;
              if(ui->TriID->isChecked())
              {y=" ";

                ui->tableProduct->setModel(p.triid(y));
        }else if (ui->TriPrice->isChecked()) {
                  y=" ";

                    ui->tableProduct->setModel(p.triprice(y));


        }else if (ui->TriName->isChecked())
              {
                  y=" ";

                    ui->tableProduct->setModel(p.triname(y));
              }
}

void MainWindow::on_PDFbuttonn_clicked()
{
    QPdfWriter pdf("C:\\Users\\mahdo\\Desktop\\pdf_table_clients.pdf");
                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::blue);
                          painter.setFont(QFont("Arial", 25));
                          painter.drawText(950,1100,"PRODUCT TABLE");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial", 15));
                          //painter.drawText(1100,2000,afficheDC);
                          painter.drawRect(100,100,7300,2600);
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial", 9));
                          painter.drawText(200,3300,"ID PRODUCT");
                          painter.drawText(1300,3300,"PROVIDER NAME ");
                          painter.drawText(2100,3300,"QUANTITY ");
                          painter.drawText(3200,3300,"PRICE");
                          painter.drawText(5300,3300,"PROVIDER EMAIL");
                          painter.drawText(7400,3300,"PRODUCT STATE");
                          painter.drawText(8600,3300,"PRODUCT NAME");
                          int aux=ui->lineEditDelete->text().toInt();
                          QString aux1=QString::number(aux);
                          QSqlQuery query;
                          query.prepare("select * from PRODUCT ");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(200,i,query.value(0).toString());
                              painter.drawText(1300,i,query.value(1).toString());
                              painter.drawText(2100,i,query.value(2).toString());
                              painter.drawText(3200,i,query.value(3).toString());
                              painter.drawText(5300,i,query.value(4).toString());
                              painter.drawText(7400,i,query.value(5).toString());
                              painter.drawText(8600,i,query.value(6).toString());

                             i = i + 500;
                          }
                          QMessageBox::information(nullptr, QObject::tr("PDF Enregistré!"),
                                      QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}



/*void MainWindow::on_STATbutton_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                             model->setQuery("select * from PRODUCT where PRICE <5 ");
                             float age=model->rowCount();
                             model->setQuery("select * from PRODUCT where PRICE between 5 and 10 ");
                             float agee=model->rowCount();
                             model->setQuery("select * from PRODUCT where PRICE >10 ");
                             float ageee=model->rowCount();
                             float total=age+agee+ageee;
                             QString a=QString("costs less than 5 dt "+QString::number((age*100)/total,'f',2)+"%" );
                             QString b=QString("costs between 5 and 10 dt "+QString::number((agee*100)/total,'f',2)+"%" );
                             QString c=QString("costs more than 10 dt "+QString::number((ageee*100)/total,'f',2)+"%" );
                             QPieSeries *series = new QPieSeries();
                             series->append(a,age);
                             series->append(b,agee);
                             series->append(c,ageee);
                     if (age!=0)
                     {QPieSlice *slice = series->slices().at(0);
                      slice->setLabelVisible();
                      slice->setPen(QPen());}
                     if ( agee!=0)
                     {
                              // Add label, explode and define brush for 2nd slice
                              QPieSlice *slice1 = series->slices().at(1);
                              //slice1->setExploded();
                              slice1->setLabelVisible();
                     }
                     if(ageee!=0)
                     {
                              // Add labels to rest of slices
                              QPieSlice *slice2 = series->slices().at(2);
                              //slice1->setExploded();
                              slice2->setLabelVisible();
                     }
                             // Create the chart widget
                             QChart *chart = new QChart();
                             // Add data to chart with title and hide legend
                             chart->addSeries(series);
                             chart->setTitle("Statistiques sur le nombre de visites des clients "+ QString::number(total));
                             chart->legend()->hide();
                             // Used to display the chart
                             QChartView *chartView = new QChartView(chart);
                             chartView->setRenderHint(QPainter::Antialiasing);
                             chartView->resize(1000,500);
                             chartView->show();
}
*/
