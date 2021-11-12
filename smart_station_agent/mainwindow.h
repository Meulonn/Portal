#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Agent.h"
#include <QMainWindow>

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

    void on_pushButton_supprimer_clicked();
    void on_comfirm_clicked();

    void on_modify_clicked();

    void on_pushButton_Chercher_clicked();

private:
    Ui::MainWindow *ui;
    Agent a;

};
#endif // MAINWINDOW_H
