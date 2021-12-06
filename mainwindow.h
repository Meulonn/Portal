#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "product.h"
#include "Agent.h"
#include"delivery.h"
#include"mailing.h"


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
    //void on_pushButton_clicked();

//    void on_pushButton_4_clicked();

  //  void on_Modify_clicked();

  //  void on_recherche_clicked();

   // void on_pushButton_5_clicked();

    //void on_Tri_clicked();

    //void on_PDFbutton_clicked();

   // void on_PDFbuttonn_clicked();

    //void on_STATbutton_clicked();

    void on_comfirmaddproduct_clicked();

    void on_Modifyproduct_clicked();

    void on_statproduct_clicked();

    void on_searchproduct_clicked();

    void on_deleteproduct_clicked();

    void on_pdfproduct_clicked();

    void on_sortproduct_clicked();

    void on_comfirmaddagent_clicked();

    void on_modifyagent_clicked();

    void on_pushButton_supprimeragent_clicked();

    void on_trinumberofabsencesagents_clicked();

    void on_tripositionagents_clicked();

    void on_triadmissiondateagents_clicked();

    void on_searchagents_clicked();

    void on_printpaymentsheetagent_clicked();

    void on_statisticsagents_clicked();

    void on_Productsmenu_clicked();

    void on_Agentsmenu_clicked();

    void on_returnagent_clicked();

    void on_returnproduct_clicked();

    void on_lineEditchercher_textChanged(const QString &arg1);

    void on_lineeditsearchproduct_textChanged(const QString &arg1);

    //void on_Clientsmenu_clicked();

    void on_deliveriesmenu_clicked();

    void on_delete_2_clicked();

    void on_update_clicked();

    void on_classify_clicked();

    void on_add_clicked();
    bool search(int);

    void on_DeliveryDetails_clicked(const QModelIndex &index);

    void on_lineEdit_rechercher_textChanged(const QString &arg1);


    void on_excel_clicked();

    void on_pdf_clicked();

    void on_mail_clicked();

    void on_cancel_clicked();

private:
    Ui::MainWindow *ui;
    product p;
    Agent a;
    delivery d;
    mailing *mailling;


};

#endif // MAINWINDOW_H
