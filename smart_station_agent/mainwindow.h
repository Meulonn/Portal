#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Agent.h"
#include <QMainWindow>
#include <QApplication>
#include <QtCore>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>

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

    void on_pushButton_clicked();

    void on_sort_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_trinumberofabsences_clicked();

    void on_triposition_clicked();

    void on_triadmissiondate_clicked();

    void on_print_clicked();

    void on_lineEditchercher_textChanged(const QString &arg1);

    void on_pushButton_stats_clicked();

    void on_history_clicked();

    void on_Statistics_clicked();

    void on_statistics_clicked();

private:
    Ui::MainWindow *ui;
    Agent a;

};
#endif // MAINWINDOW_H
