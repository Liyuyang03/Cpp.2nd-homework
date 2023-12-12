#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include <string>

#include "chakan.h"
#include "luru.h"
#include "panti.h"

#include <QPushButton>

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget* parent = Q_NULLPTR);

private:
    Ui::mainwindowClass ui;
private slots:
    void Openchakan();
    void Openluru();
    void Openpanti();
};
/*

*/