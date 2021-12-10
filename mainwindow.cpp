#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "product.h"
#include "Agent.h"
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
#include <QtCharts>
#include <QFile>
#include <QPieSlice>
#include <QPieSeries>
#include"ExcelExportHelper.h"
#include"mailing.h"
#include"ui_mailing.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{



    ui->setupUi(this);
    ui->tableProduct->setModel(p.view_product());
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
    /*ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
int MainWindow::search_truck(QString s)
{
    int i=0;
    while(ui->DeliveryDetails->model()->rowCount() )
    {
        if(ui->DeliveryDetails->model()->index(i,5).data()==s)
        {
            return 1;
    }
        i++;
    }
    return -1;

}
void MainWindow::update_label()
{
    data=A.read_from_arduino();

    int s = search_truck(data);

       if(s==1)
        A.write_to_arduino("1");
       else if(s==-1)
           A.write_to_arduino("0");



}

//PROOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOODUUUUUUUUUUUUUCT

//
//
//
//

/*void MainWindow::on_STATbutton_clicked()
{
3
}
*/

void MainWindow::on_comfirmaddproduct_clicked()
{
    product p;
    p.setid(ui->idaddproduct->text().toInt());
    p.setquantity(ui->quantityaddproduct->text().toInt());
    p.setprice(ui->priceaddproduct->text().toFloat());
    p.setname(ui->productnameadd->text());
    p.setstate(ui->productstatusadd->text().toInt());
    p.setprovider(ui->providernameadd->text());
    p.setproviderEmail(ui->provideremailadd->text());
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

            flux <<"Name:"<< ui->productnameadd->text() <<" , "<<"Providername:" << ui->providernameadd->text()<< " Added."<<endl ;
            file.close();
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Error message"),
                              QObject::tr("failed to add Agent"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
}



void MainWindow::on_Modifyproduct_clicked()
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

            flux <<"Name:"<< ui->productnameM->text() <<" , "<<"Providername:" << ui->providernameM->text()<< " Modified."<<endl ;
            file.close();
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Error message"),
                              QObject::tr("failed to modify product"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
}






void MainWindow::on_statproduct_clicked()
{
   /* QSqlQueryModel * model= new QSqlQueryModel();
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
                             chartView->show();*/
}

void MainWindow::on_searchproduct_clicked()
{
    product p;
    QString A=ui->lineeditsearchproduct->text();
    ui->tableProduct->setModel(p.research(A));
    if(A=="")
            ui->tableProduct->setModel(p.view_product());
}

void MainWindow::on_lineeditsearchproduct_textChanged(const QString &arg1)
{
    product p;
    QString A=ui->lineeditsearchproduct->text();
    ui->tableProduct->setModel(p.research(A));
    if(A=="")
            ui->tableProduct->setModel(p.view_product());
}



void MainWindow::on_deleteproduct_clicked()
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

void MainWindow::on_pdfproduct_clicked()
{
    QPdfWriter pdf("C:\\Users\\khali\\Desktop\\pdf_table_clients.pdf");
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

                             i = i + 500;;
                          }
                          QMessageBox::information(nullptr, QObject::tr("PDF Enregistré!"),
                                      QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel) ;
}

void MainWindow::on_sortproduct_clicked()
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


//AAAAAAAAAAAAAAAAAAGEEEEEEEEEEEEEEEEEEEENT

//
//
//
//
//
//
void MainWindow::on_comfirmaddagent_clicked()
{
    Agent a;
    a.setCin(ui->lineEditCINaddagent->text().toInt());
    a.setName(ui->lineEditnameaddagent->text());
    a.setadress(ui->adressaddagent->text());
    a.setEmail(ui->emailaddagent->text());
    a.setSalary(ui->salaryaddagent->text().toInt());
    a.setposition(ui->positionaddagent->text().toInt());
    a.setNumberofabsences(ui->numbofabsencaddagent->text().toInt());
    a.setadmissiondate(ui->admissiondateadd->text());

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
        // Création d'un objet QFile
        QFile file("C:/Users/khali/Documents/Smart station agent/Qt.txt");
        // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
            return;
        // Création d'un objet QTextStream à partir de notre objet QFile
        QTextStream flux(&file);
        // On choisit le codec correspondant au jeu de caractères que l'on souhaite ; ici, UTF-8
        flux.setCodec("UTF-8");
        // Écriture des différentes lignes dans le fichier

        flux <<"Name:"<< ui->lineEditnameaddagent->text() <<" , "<<"CIN:" << ui->lineEditCINaddagent->text().toInt()<< " Added."<<endl ;
        file.close();
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

void MainWindow::on_modifyagent_clicked()
{
    int cin = ui->lineEditcinmodifieragent->text().toInt();
    QString nom = ui->lineEditnamemodifieragent->text();
    QString date = ui->admissiondatemodify->text();
    int numberofabsences = ui->lineEditnumberofabsencesmodifieragent->text().toInt();
    QString adress = ui->lineEditadressmodifier->text();
    int position = ui->lineEditpositionmodifieragent->text().toInt();
    float salary = ui->lineEditsalarymodifieragent->text().toInt();
    QString email = ui->lineEditemailmodifieragent->text();

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
            // Création d'un objet QFile
            QFile file("C:/Users/khali/Documents/Smart station agent/Qt.txt");
            // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
                return;
            // Création d'un objet QTextStream à partir de notre objet QFile
            QTextStream flux(&file);
            // On choisit le codec correspondant au jeu de caractères que l'on souhaite ; ici, UTF-8
            flux.setCodec("UTF-8");
            // Écriture des différentes lignes dans le fichier
            flux <<"Name:"<< ui->lineEditnamemodifieragent->text() <<" , "<<"CIN:" << ui->lineEditcinmodifieragent->text().toInt()<< " modified."<<endl ;
            file.close();
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

void MainWindow::on_pushButton_supprimeragent_clicked()
{
    int id_s=ui->lineEditsupprimeragent->text().toInt();
    qDebug()<< id_s;
    bool test=a.supprimer(id_s);
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("task finished"),
        QObject::tr("Deleted successfully.\n"
                    "Click cancel to exit."), QMessageBox::Cancel);
         ui->tab_agents->setModel(a.afficher());
         // Création d'un objet QFile
         QFile file("C:/Users/khali/Documents/Smart station agent/Qt.txt");
         // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
         if (!file.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
             return;
         // Création d'un objet QTextStream à partir de notre objet QFile
         QTextStream flux(&file);
         // On choisit le codec correspondant au jeu de caractères que l'on souhaite ; ici, UTF-8
         flux.setCodec("UTF-8");
         // Écriture des différentes lignes dans le fichier
         flux <<"CIN:"<< ui->lineEditsupprimeragent->text() << "          Deleted."<<endl ;

         file.close();
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("task failed"),
                              QObject::tr("deletion failed.\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_trinumberofabsencesagents_clicked()
{
    Agent a;
    QString y=" ";
    ui->tab_agents->setModel(a.trinbrabsences(y));
}

void MainWindow::on_tripositionagents_clicked()
{
    Agent a;
    QString y=" ";
    ui->tab_agents->setModel(a.triposition(y));
}

void MainWindow::on_triadmissiondateagents_clicked()
{
    Agent a;
    QString y=" ";
    ui->tab_agents->setModel(a.triadmissiondate(y));
}

void MainWindow::on_searchagents_clicked()
{
    Agent a;
    QString A= ui->lineEditchercher->text();
    ui->tab_recherche->setModel(a.rechercher(A));
}

void MainWindow::on_printpaymentsheetagent_clicked()
{
    QPdfWriter pdf("C:\\Users\\khali\\Desktop\\payment_sheet.pdf");
                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::red);
                          painter.setFont(QFont("Arial", 25));
                          painter.drawText(2500,1100,"Agents payment sheet");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial", 15));
                          painter.drawRect(1750,500,5400,1000);
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial", 12));
                          painter.drawText(200,3300,"Agent CIN");
                          painter.drawText(1300,3300,"Name");
                          painter.drawText(2100,3300,"Admission Date");
                          painter.drawText(5300,3300,"Number of absences");
                          painter.drawText(7400,3300,"Position");
                          painter.drawText(8600,3300,"Salary");

                          int aux=ui->lineEditCINaddagent->text().toInt();
                          QString aux1=QString::number(aux);
                          QSqlQuery query;
                          query.prepare("select * from AGENTS ");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(200,i,query.value(0).toString());
                              painter.drawText(1300,i,query.value(1).toString());
                              painter.drawText(2100,i,query.value(2).toString());
                              painter.drawText(5300,i,query.value(3).toString());
                              painter.drawText(7400,i,query.value(5).toString());
                              painter.drawText(8600,i,query.value(6).toString());


                             i = i + 500;
                          }
                          QMessageBox::information(nullptr, QObject::tr("PDF Enregistré!"),
                                      QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_statisticsagents_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                             model->setQuery("select * from AGENTS where NBR_ABSENCES <1 ");
                             float a=model->rowCount();
                             model->setQuery("select * from AGENTS where NBR_ABSENCES between 1 and 3 ");
                             float aa=model->rowCount();
                             model->setQuery("select * from AGENTS where NBR_ABSENCES >3 ");
                             float aaa=model->rowCount();
                             float total=a+aa+aaa;
                             QString d=QString("No absences "+QString::number((a*100)/total,'f',2)+"%" );
                             QString b=QString("between 1 and 3 absences "+QString::number((aa*100)/total,'f',2)+"%" );
                             QString c=QString("more than 3 absences "+QString::number((aaa*100)/total,'f',2)+"%" );
                             QPieSeries *series = new QPieSeries();
                             series->append(d,a);
                             series->append(b,aa);
                             series->append(c,aaa);
                     if (a!=0)
                     {QPieSlice *slice = series->slices().at(0);
                      slice->setLabelVisible();
                      slice->setPen(QPen());}
                     if (aa!=0)
                     {
                              // Add label, explode and define brush for 2nd slice
                              QPieSlice *slice1 = series->slices().at(1);
                              //slice1->setExploded();
                              slice1->setLabelVisible();
                     }
                     if(aaa!=0)
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
                             chart->setTitle("Statistics on the number of absences of AGENTS "+ QString::number(total));
                             chart->legend()->hide();
                             // Used to display the chart
                             QChartView *chartView = new QChartView(chart);
                             chartView->setRenderHint(QPainter::Antialiasing);
                             chartView->resize(1000,500);
                             chartView->show();
}

void MainWindow::on_Productsmenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Agentsmenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_returnagent_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_returnproduct_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_lineEditchercher_textChanged(const QString &arg1)
{
    Agent a;
    QString A= ui->lineEditchercher->text();
    ui->tab_recherche->setModel(a.rechercher(A));
}





void MainWindow::on_deliveriesmenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_delete_2_clicked()
{
    delivery d;

    int package_num=ui->lineEdit_delete->text().toInt();
    qDebug()<<package_num;
    bool test1=search(package_num);
    if(test1==false)
    {

        QMessageBox::critical(nullptr, QObject::tr("delivery not deleted"),
                              QObject::tr("package_num inexsit .\n"
                                          "Click Cancek to exit"), QMessageBox::Cancel);
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

void MainWindow::on_DeliveryDetails_clicked(const QModelIndex &index)
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

void MainWindow::on_lineEdit_rechercher_textChanged(const QString &arg1)
{
    //delivery d;
    QString rech=ui->lineEdit_rechercher->text();
      ui->DeliveryDetails->setModel(d.researchDelivery(rech));
}

void MainWindow::on_excel_clicked()
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

void MainWindow::on_pdf_clicked()
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

void MainWindow::on_mail_clicked()
{
    mailling=new mailing(this);
    mailling->show();
}

void MainWindow::on_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_clicked()
{
    QString username=ui->lineEdit->text();
       QString password=ui->lineEdit_2->text();
       if(username=="" || password=="")
       {
   QMessageBox::critical(nullptr,QObject::tr("Signin"),QObject::tr("Please fill in the fields"),QMessageBox::Ok);
       }
       QSqlQuery qry;
       if(qry.exec("SELECT * FROM EMPLOYEE WHERE USERNAME='"+username+ "' AND PASSWORD='"+password+"'"))
      {

           int count=0;
           while(qry.next())
           {
               count++;
           }
           if(count==1)
           {    QMessageBox::information(nullptr,QObject::tr("Signin"),QObject::tr("connected successfully"),QMessageBox::Ok);

               ui->stackedWidget->setCurrentIndex(1);

           }


           else
           QMessageBox::critical(nullptr,QObject::tr("Signin"),QObject::tr("username and password are not correct"),QMessageBox::Ok);

}
}

