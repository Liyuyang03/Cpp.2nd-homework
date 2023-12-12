#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_luru.h"

#include <Qlabel>
#include <QPushButton>
#include <Qstring>
#include <QFile>
#include <QFileDialog>
#include <QTextstream>
#include <QDir>

class luru : public QMainWindow
{
    Q_OBJECT

public:
    luru(QWidget* parent = Q_NULLPTR);
private:
    Ui::luruClass ui;
private slots:
    void Closeluru();
    void tiankong();
    void xuanze();
    void Save();
    void Save_Close();
};