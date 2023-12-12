#pragma execution_character_set("utf-8")

#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(Openchakan()));
    connect(ui.pushButton_2, SIGNAL(clicked(bool)), this, SLOT(Openluru()));
    connect(ui.pushButton_3, SIGNAL(clicked(bool)), this, SLOT(Openpanti()));
}

void mainwindow::Openchakan()
{
    chakan* c = new chakan;
    c->show();
    this->close();
}

void mainwindow::Openluru()
{
    luru* l = new luru;
    l->show();
    this->close();
}

void mainwindow::Openpanti()
{
    panti* p = new panti;
    p->show();
    this->close();
}
