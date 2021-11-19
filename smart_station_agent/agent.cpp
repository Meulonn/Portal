#include "Agent.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QApplication>
#include <QSqlDatabase>
#include <QObject>
#include <QtCharts>
#include <QFile>

Agent::Agent()
{
    cin=0;
    name="";
    email="";
    adress="";
    position=0;
    numberofabsences=0;
    salary=0;
    date = "";
}
Agent::Agent(int c,QString n,QString em,QString a,int p,int na,float s,QString d)
{
    cin=c;
    name=n;
    email=em;
    adress=a;
    position=p;
    numberofabsences=na;
    salary=s;
    date=d;

}
void Agent::setCin(int n)
{
    cin=n;
}
void Agent::setName(QString n)
{
    name=n;
}
void Agent::setEmail(QString n)
{
    email=n;
}
void Agent::setNumberofabsences(int n)
{
    numberofabsences=n;
}
void Agent::setposition(int n)
{
    position=n;
}
void Agent::setSalary(float n)
{
    salary=n;
}
void Agent::setadmissiondate(QString n)
{
    date = n;
}
void Agent::setadress(QString n)
{
    adress=n;
}


bool Agent::validEmail(QString email)
{
    ;
    bool test = true;

    qDebug() << email;

    QRegularExpression regex("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");

    if(!regex.match(email).hasMatch())
    {
        test = false;
    }

    return test;
}


bool Agent::ajouter()
{
    QSqlQuery query;
    QString cin_s= QString::number(cin);
    QString numberofabsences_s= QString::number(numberofabsences);
    QString salary_s= QString::number(salary);
    QString position_s= QString::number(position);



          query.prepare("INSERT INTO AGENTS (CIN, NAME, ADMISSIONDATE, NBR_ABSENCES , ADRESS, POSITION , SALARY, EMAIL ) "
                        "VALUES (:CIN, :NAME, :ADMISSIONDATE, :NBR_ABSENCES, :ADRESS , :POSITION, :SALARY , :EMAIL )");
          query.bindValue(":CIN",cin_s);
          query.bindValue(":NAME",name);
          query.bindValue(":ADMISSIONDATE",date);
          query.bindValue(":NBR_ABSENCES",numberofabsences_s);
          query.bindValue(":ADRESS", adress);
          query.bindValue(":POSITION", position_s);
          query.bindValue(":SALARY",salary_s);
          query.bindValue(":EMAIL",email);

          if (query.lastError().isValid())
              qDebug() << query.lastError();
         return query.exec();

}


QSqlQueryModel * Agent::afficher()
 {
     QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM AGENTS");
          model->setHeaderData(0, Qt::Horizontal,  QObject::tr("CIN"));
          model->setHeaderData(1, Qt::Horizontal,  QObject::tr("NAME"));
          model->setHeaderData(2, Qt::Horizontal,  QObject::tr("ADMISSIONDATE"));
          model->setHeaderData(3, Qt::Horizontal,  QObject::tr("NBR_ABSENCES"));
          model->setHeaderData(4, Qt::Horizontal,  QObject::tr("ADRESS"));
          model->setHeaderData(5, Qt::Horizontal,  QObject::tr("POSITION"));
          model->setHeaderData(6, Qt::Horizontal,  QObject::tr("SALARY"));
          model->setHeaderData(7, Qt::Horizontal,  QObject::tr("EMAIL"));
     return model;
 }

/*bool Agent::supprimer(QString id)
{
    QSqlQuery query;
    qDebug() << id;
    int v=id.toInt();
    query.prepare("DELETE FROM AGENTS WHERE CIN= :id ");
    query.bindValue(":id",v);
    return query.exec();
}
*/

 bool Agent::supprimer(int id)
 {
     QSqlQuery query;
     qDebug() << id;

     query.prepare("DELETE FROM AGENTS WHERE CIN= :id ");
     query.bindValue(":id",id);
     return query.exec();
 }

 bool Agent::modifier(int cin, QString name, QString adress, QString email, int position, int numberofabsences, float salary, QString date)
 {
     QSqlQuery query;
     QString cin_s= QString::number(cin);
     QString numberofabsences_s= QString::number(numberofabsences);
     QString salary_s= QString::number(salary);
     QString position_s= QString::number(position);
     query.prepare("update AGENTS set CIN=:cin,NAME=:name,ADMISSIONDATE=:admissiondate,NBR_ABSENCES=:nbr_absences,ADRESS=:adress,POSITION=:position,SALARY=:salary,EMAIL=:email where CIN=:cin");
     query.bindValue(":cin",cin_s);
     query.bindValue(":name",name);
     query.bindValue(":admissiondate",date);
     query.bindValue(":nbr_absences",numberofabsences_s);
     query.bindValue(":adress", adress);
     query.bindValue(":position", position_s);
     query.bindValue(":salary",salary_s);
     query.bindValue(":email",email);
     return query.exec();

 }

 QSqlQueryModel * Agent::afficherCIN()
 {  QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("SELECT CIN FROM AGENTS");
          model->setHeaderData(0, Qt::Horizontal,  QObject::tr("CIN"));

     return model;
 }

 QSqlQueryModel * Agent::rechercher (const QString &aux)

 {
     QSqlQueryModel * model = new QSqlQueryModel();

     model->setQuery("select * from AGENTS where ((CIN || NAME || ADMISSIONDATE || NBR_ABSENCES || ADRESS || POSITION || SALARY || EMAIL) LIKE '%"+aux+"%')");
     model->setHeaderData(0, Qt::Horizontal,  QObject::tr("CIN"));
     model->setHeaderData(1, Qt::Horizontal,  QObject::tr("NAME"));
     model->setHeaderData(2, Qt::Horizontal,  QObject::tr("ADMISSIONDATE"));
     model->setHeaderData(3, Qt::Horizontal,  QObject::tr("NBR_ABSENCES"));
     model->setHeaderData(4, Qt::Horizontal,  QObject::tr("ADRESS"));
     model->setHeaderData(5, Qt::Horizontal,  QObject::tr("POSITION"));
     model->setHeaderData(6, Qt::Horizontal,  QObject::tr("SALARY"));
     model->setHeaderData(7, Qt::Horizontal,  QObject::tr("EMAIL"));
     return model;
 }


 QSqlQueryModel *  Agent::tri(const QString &critere)
 {
     QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from AGENTS order by "+critere+"");
    model->setHeaderData(0, Qt::Horizontal,  QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("NAME"));
    model->setHeaderData(2, Qt::Horizontal,  QObject::tr("ADMISSIONDATE"));
    model->setHeaderData(3, Qt::Horizontal,  QObject::tr("NBR_ABSENCES"));
    model->setHeaderData(4, Qt::Horizontal,  QObject::tr("ADRESS"));
    model->setHeaderData(5, Qt::Horizontal,  QObject::tr("POSITION"));
    model->setHeaderData(6, Qt::Horizontal,  QObject::tr("SALARY"));
    model->setHeaderData(7, Qt::Horizontal,  QObject::tr("EMAIL"));
     return model;
 }

 QSqlQueryModel * Agent::triposition(QString y)
 {


     QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT* FROM AGENTS ORDER BY POSITION"+y);
          model->setHeaderData(0, Qt::Horizontal,  QObject::tr("CIN"));
          model->setHeaderData(1, Qt::Horizontal,  QObject::tr("NAME"));
          model->setHeaderData(2, Qt::Horizontal,  QObject::tr("ADMISSIONDATE"));
          model->setHeaderData(3, Qt::Horizontal,  QObject::tr("NBR_ABSENCES"));
          model->setHeaderData(4, Qt::Horizontal,  QObject::tr("ADRESS"));
          model->setHeaderData(5, Qt::Horizontal,  QObject::tr("POSITION"));
          model->setHeaderData(6, Qt::Horizontal,  QObject::tr("SALARY"));
          model->setHeaderData(7, Qt::Horizontal,  QObject::tr("EMAIL"));

     return  model;



 }
 QSqlQueryModel * Agent::trinbrabsences(QString y)
 {
     QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT* FROM AGENTS ORDER BY NBR_ABSENCES"+y);
          model->setHeaderData(0, Qt::Horizontal,  QObject::tr("CIN"));
          model->setHeaderData(1, Qt::Horizontal,  QObject::tr("NAME"));
          model->setHeaderData(2, Qt::Horizontal,  QObject::tr("ADMISSIONDATE"));
          model->setHeaderData(3, Qt::Horizontal,  QObject::tr("NBR_ABSENCES"));
          model->setHeaderData(4, Qt::Horizontal,  QObject::tr("ADRESS"));
          model->setHeaderData(5, Qt::Horizontal,  QObject::tr("POSITION"));
          model->setHeaderData(6, Qt::Horizontal,  QObject::tr("SALARY"));
          model->setHeaderData(7, Qt::Horizontal,  QObject::tr("EMAIL"));

     return  model;
 }
 QSqlQueryModel * Agent::triadmissiondate(QString y)
 {
     QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT* FROM AGENTS ORDER BY ADMISSIONDATE"+y);
          model->setHeaderData(0, Qt::Horizontal,  QObject::tr("CIN"));
          model->setHeaderData(1, Qt::Horizontal,  QObject::tr("NAME"));
          model->setHeaderData(2, Qt::Horizontal,  QObject::tr("ADMISSIONDATE"));
          model->setHeaderData(3, Qt::Horizontal,  QObject::tr("NBR_ABSENCES"));
          model->setHeaderData(4, Qt::Horizontal,  QObject::tr("ADRESS"));
          model->setHeaderData(5, Qt::Horizontal,  QObject::tr("POSITION"));
          model->setHeaderData(6, Qt::Horizontal,  QObject::tr("SALARY"));
          model->setHeaderData(7, Qt::Horizontal,  QObject::tr("EMAIL"));

     return  model;
 }














