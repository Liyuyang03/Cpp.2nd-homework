#pragma execution_character_set("utf-8")

#include "luru.h"
#include "mainwindow.h"

luru::luru(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    connect(ui.radioButton_5, SIGNAL(pressed()), this, SLOT(tiankong()));
    connect(ui.radioButton_6, SIGNAL(pressed()), this, SLOT(xuanze()));
    connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(Save()));
    connect(ui.pushButton_2, SIGNAL(clicked(bool)), this, SLOT(Save_Close()));
    connect(ui.pushButton_3, SIGNAL(clicked(bool)), this, SLOT(Closeluru()));
}

void luru::Closeluru()
{
    mainwindow* m = new mainwindow;
    m->show();
    this->close();
}

void luru::tiankong()
{
    this->ui.textEdit->setEnabled(true);
    this->ui.textEdit_2->setEnabled(true);
    this->ui.lineEdit_A->setEnabled(false);
    this->ui.lineEdit_B->setEnabled(false);
    this->ui.lineEdit_C->setEnabled(false);
    this->ui.lineEdit_D->setEnabled(false);
    this->ui.radioButton->setEnabled(false);
    this->ui.radioButton_2->setEnabled(false);
    this->ui.radioButton_3->setEnabled(false);
    this->ui.radioButton_4->setEnabled(false);
    this->ui.radioButton_6->setChecked(false);
}
void luru::xuanze()
{
    this->ui.textEdit->setEnabled(true);
    this->ui.textEdit_2->setEnabled(false);
    this->ui.lineEdit_A->setEnabled(true);
    this->ui.lineEdit_B->setEnabled(true);
    this->ui.lineEdit_C->setEnabled(true);
    this->ui.lineEdit_D->setEnabled(true);
    this->ui.radioButton->setEnabled(true);
    this->ui.radioButton_2->setEnabled(true);
    this->ui.radioButton_3->setEnabled(true);
    this->ui.radioButton_4->setEnabled(true);
    this->ui.radioButton_5->setChecked(false);
}
void luru::Save()
{
    if (this->ui.radioButton_5->isChecked())//填空题
    {
        QString total = "tiankongLiyuyang" + this->ui.textEdit->toPlainText() +
            "Liyuyang" + this->ui.textEdit_2->toPlainText();
        QString file_path = QFileDialog::getSaveFileName(this, "保存", this->ui.lineEdit_title->text() + ".lyy", "lyy files (*.lyy)");
        QByteArray totalEncode = total.toLocal8Bit();
        totalEncode = totalEncode.toBase64();
        QFile file(file_path);
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        out << totalEncode;
        file.close();
    }
    else if (this->ui.radioButton_6->isChecked())//选择题
    {
        QString answer;
        if (this->ui.radioButton->isChecked()) { answer = "A"; }
        else if (this->ui.radioButton_2->isChecked()) { answer = "B"; }
        else if (this->ui.radioButton_3->isChecked()) { answer = "C"; }
        else if (this->ui.radioButton_4->isChecked()) { answer = "D"; };
        QString total = "xuanzeLiyuyang" + this->ui.textEdit->toPlainText() +
            "LiyuyangA." + this->ui.lineEdit_A->text() +
            "LiyuyangB." + this->ui.lineEdit_B->text() +
            "LiyuyangC." + this->ui.lineEdit_C->text() +
            "LiyuyangD." + this->ui.lineEdit_D->text() +
            "Liyuyang" + answer;
        QString file_path = QFileDialog::getSaveFileName(this, "保存", this->ui.lineEdit_title->text() + ".lyy", "lyy files (*.lyy)");
        QByteArray totalEncode = total.toLocal8Bit();
        totalEncode = totalEncode.toBase64();
        QFile file(file_path);
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        out << totalEncode;
        file.close();
    };
}
void luru::Save_Close()
{
    this->Save();
    this->Closeluru();
}