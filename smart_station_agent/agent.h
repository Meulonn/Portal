#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QRegularExpression>
#include <QApplication>
#include <QtCore>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>


class Agent
{
private:
    int cin,position,numberofabsences;
    QString  name,email,adress,date;
    float salary ;


public:
    void setCin(int );
    void setName(QString );
    void setposition(int );
    void setEmail(QString );
    void setNumberofabsences(int );
    void setSalary(float);
    void setadmissiondate(QString);
    void setadress(QString);
    int getCin(){return cin;}
    QString getName(){return name;}
    int getPosition(){return position;}
    QString getEmail(){return email;}
    int getnumberofabsences(){return numberofabsences;}
    float getsalary(){return salary;}
    QString getadress(){return adress;}
    QString getadmissiondate(){return date;}
    QSqlQueryModel * afficherCIN();
    QSqlQueryModel * rechercher (const QString &aux);
    bool validEmail(QString);

    Agent();
    Agent(int cin,QString name,QString adress,QString email,int position,int numberofabsences,float salary ,QString date);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int cin,QString name,QString adress,QString email,int position,int numberofabsences,float salary ,QString date);
    QSqlQueryModel * tri(const QString &critere);
    QSqlQueryModel * triposition(QString y);
    QSqlQueryModel * trinbrabsences(QString y);
    QSqlQueryModel * triadmissiondate(QString y);
};

#endif // CLIENT_H
