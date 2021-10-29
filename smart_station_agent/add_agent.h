#ifndef ADD_AGENT_H
#define ADD_AGENT_H
#include "agent.h"

#include <QDialog>

namespace Ui {
class add_agent;
}

class add_agent : public QDialog
{
    Q_OBJECT

public:
    explicit add_agent(QWidget *parent = nullptr);
    void setagent(agent a);
    ~add_agent();

private slots:
    void on_pushButton_clicked();

private:
    Ui::add_agent *ui;
};

#endif // ADD_AGENT_H
