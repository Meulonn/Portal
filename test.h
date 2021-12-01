#ifndef TEST_H
#define TEST_H
#include<QSystemTrayIcon>
#include <QMainWindow>

#include <QString>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>
class test
{
public:
    test();
    test(QString,QString);
    QString getid();
    QString getnom();
    bool ajout ();
    QSqlQueryModel *afficher();
private:
    QString id,nom;
};

#endif // TEST_H
