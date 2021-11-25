#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "product.h"

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_Modify_clicked();

    void on_recherche_clicked();

    void on_pushButton_5_clicked();

    void on_Tri_clicked();

    void on_PDFbutton_clicked();

    void on_PDFbuttonn_clicked();

    void on_STATbutton_clicked();

private:
    Ui::MainWindow *ui;
    product p;
};

#endif // MAINWINDOW_H
