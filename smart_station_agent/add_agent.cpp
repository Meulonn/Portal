#include "add_agent.h"
#include "ui_add_agent.h"
#include "agent.h"

add_agent::add_agent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_agent)
{
    ui->setupUi(this);
}

add_agent::~add_agent()
{
    delete ui;
}
