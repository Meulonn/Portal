#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include<QString>
#include<QSqlQuery>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include<QApplication>
#include<QMessageBox>
#include<QDebug>
#include <QDate>
#include <QObject>

class Connection
{
     QSqlDatabase db;
public:
    Connection();
    bool createconnect();
    void closeconnect();
};

#endif // CONNECTION_H
