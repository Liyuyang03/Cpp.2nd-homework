#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_panti.h"

#include <Qlabel>
#include <QPushButton>
#include <QFileDialog>
#include <QDir>

class panti : public QMainWindow
{
    Q_OBJECT

public:
    panti(QWidget* parent = Q_NULLPTR);

private:
    Ui::pantiClass ui;

private slots:
    void Closepanti();
    void choosepanti();
    void quedingpanti();
    void answerpanti();
};