#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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
#include <QMainWindow>
#include"client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_OK1_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::MainWindow *ui;
    Client c;
};

#endif // MAINWINDOW_H
