#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <test.h>
#include <delivery.h>
#include"mailing.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow :
        public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_clicked();
    void on_delete_2_clicked();
    void on_update_clicked();
    void on_DeliveryDetails_clicked();
    bool search(int);
    void on_lineEdit_rechercher_textChanged();

    void on_classify_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

private:
Ui::MainWindow *ui;
test tmptest;
mailing *mailling;


delivery d;
};
#endif // MAINWINDOW_H
