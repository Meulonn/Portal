#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Agent.h"
#include <QIntValidator>
#include <QSqlError>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include <QtCharts>
#include <QChartView>
#include <QFile>

QT_CHARTS_USE_NAMESPACE

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
         flux <<"CIN:"<< ui->lineEditsupprimer->text() << "          Deleted."<<endl ;

         file.close();
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

    flux <<"Name:"<< ui->lineEdit_name->text() <<" , "<<"CIN:" << ui->lineEditCIN->text().toInt()<< " Added."<<endl ;
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
            flux <<"Name:"<< ui->lineEditnamemodifier->text() <<" , "<<"CIN:" << ui->lineEditcinmodifier->text().toInt()<< " modified."<<endl ;
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










void MainWindow::on_pushButton_Chercher_clicked()
{
    Agent a;
    QString A= ui->lineEditchercher->text();
    ui->tab_recherche->setModel(a.rechercher(A));
}



void MainWindow::on_trinumberofabsences_clicked()
{
    Agent a;
    QString y=" ";
    ui->tab_agents->setModel(a.trinbrabsences(y));
}

void MainWindow::on_triposition_clicked()
{
    Agent a;
    QString y=" ";
    ui->tab_agents->setModel(a.triposition(y));

}

void MainWindow::on_triadmissiondate_clicked()
{
    Agent a;
    QString y=" ";
    ui->tab_agents->setModel(a.triadmissiondate(y));
}



void MainWindow::on_print_clicked()
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

                          int aux=ui->lineEditCIN->text().toInt();
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


void MainWindow::on_lineEditchercher_textChanged(const QString &arg1)
{
    Agent a;
    QString A= ui->lineEditchercher->text();
    ui->tab_recherche->setModel(a.rechercher(A));
}


void MainWindow::on_pushButton_stats_clicked()
{

}




void MainWindow::on_statistics_clicked()
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
