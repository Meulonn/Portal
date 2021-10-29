#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "agent.h"
#include "add_agent.h"

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
   agent a ;
   add_agent ag;
   ag.setModal(true);
   ag.exec();
    //ui->stackedWidget->setCurrentIndex(1);
    //a.setname(ui->lineEdit)
}
