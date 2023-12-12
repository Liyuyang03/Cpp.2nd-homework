#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_chakan.h"

#include <Qlabel>
#include <QPushButton>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTextstream>
#include <QDir>

class chakan : public QMainWindow
{
    Q_OBJECT

public:
    chakan(QWidget* parent = Q_NULLPTR);

private:
    Ui::chakanClass ui;
private slots:
    void Closechakan();
    void choosechakan();
    void quedingchakan();
};