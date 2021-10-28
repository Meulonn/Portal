#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "product.h"
#include "addproduct.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    addProduct ap;
    ap.setModal(true);
    ap.exec();



}
