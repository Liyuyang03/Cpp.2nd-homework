#pragma execution_character_set("utf-8")

#include "panti.h"
#include "mainwindow.h"

panti::panti(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->ui.label_4->setVisible(false);
    this->ui.label_5->setVisible(false);
	this->ui.label_6->setVisible(false);
    setAttribute(Qt::WA_DeleteOnClose);
	connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(quedingpanti()));
	connect(ui.pushButton_2, SIGNAL(clicked(bool)), this, SLOT(Closepanti()));
	connect(ui.pushButton_3, SIGNAL(clicked(bool)), this, SLOT(choosepanti()));
	connect(ui.pushButton_4, SIGNAL(clicked(bool)), this, SLOT(answerpanti()));
}

void panti::Closepanti()
{
    mainwindow* m = new mainwindow;
    m->show();
    this->close();
}

void panti::choosepanti()
{
	QString dirname = QFileDialog::getExistingDirectory(this, "选择题库所在文件夹");
	this->ui.lineEdit->setText(dirname);
	QDir* dirinfo = new QDir(dirname);
	if (!dirinfo->exists()) {

		delete dirinfo, dirinfo = nullptr;
		return;
	}

	QStringList dirList = dirinfo->entryList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
	QStringList lyyList;
	for (auto fileName : dirList)
	{
		if (fileName.endsWith(".lyy"))
			lyyList << fileName;
	}

	ui.listWidget->clear();
	ui.listWidget->addItems(lyyList);

	delete dirinfo, dirinfo = nullptr;
	return;
}

void panti::quedingpanti()
{
	QListWidgetItem* selectedItem = this->ui.listWidget->currentItem();
	if (selectedItem)
	{
		this->ui.label_4->setVisible(false);
		this->ui.label_5->setVisible(false);
		QString title = ui.lineEdit->text() + "/" + selectedItem->text();
		QFile file(title);
		file.open(QIODevice::ReadOnly);
		QTextStream in(&file);
		QByteArray totalDecode;
		in >> totalDecode;
		//		totalDecode = totalDecode.toLocal8Bit();
		totalDecode = totalDecode.fromBase64(totalDecode);
		QString total = QString::fromLocal8Bit(totalDecode);
		QStringList totalList = total.split("Liyuyang");
		QString type = totalList[0];
		QString timu = totalList[1];
		this->ui.label_timu->setText(timu);
		if (type == "tiankong")//填空题
		{
			this->ui.radioButton->setEnabled(false);
			this->ui.radioButton_2->setEnabled(false);
			this->ui.radioButton_3->setEnabled(false);
			this->ui.radioButton_4->setEnabled(false);
			this->ui.radioButton->setVisible(false);
			this->ui.radioButton_2->setVisible(false);
			this->ui.radioButton_3->setVisible(false);
			this->ui.radioButton_4->setVisible(false);
			this->ui.label_3->setVisible(true);
			this->ui.textEdit_2->setEnabled(true);
			this->ui.textEdit_2->setVisible(true);
			this->ui.label_A->clear();
			this->ui.label_B->clear();
			this->ui.label_C->clear();
			this->ui.label_D->clear();
			this->ui.label_6->setText(totalList[2]);
		}
		else if (type == "xuanze")//选择题
		{
			this->ui.radioButton->setEnabled(true);
			this->ui.radioButton_2->setEnabled(true);
			this->ui.radioButton_3->setEnabled(true);
			this->ui.radioButton_4->setEnabled(true);
			this->ui.radioButton->setVisible(true);
			this->ui.radioButton_2->setVisible(true);
			this->ui.radioButton_3->setVisible(true);
			this->ui.radioButton_4->setVisible(true);
			this->ui.label_3->setVisible(false);
			this->ui.textEdit_2->setEnabled(false);
			this->ui.textEdit_2->setVisible(false);
			this->ui.textEdit_2->clear();
			this->ui.label_A->setText(totalList[2]);
			this->ui.label_B->setText(totalList[3]);
			this->ui.label_C->setText(totalList[4]);
			this->ui.label_D->setText(totalList[5]);
			this->ui.label_6->setText(totalList[6]);
		};
	};
}

void panti::answerpanti()
{
	if (this->ui.label_6->text() != "")
	{
		if (this->ui.label_6->text() == this->ui.textEdit_2->toPlainText()
			|| this->ui.label_6->text() == "A" && this->ui.radioButton->isChecked()
			|| this->ui.label_6->text() == "B" && this->ui.radioButton_2->isChecked()
			|| this->ui.label_6->text() == "C" && this->ui.radioButton_3->isChecked()
			|| this->ui.label_6->text() == "D" && this->ui.radioButton_4->isChecked())
		{
			this->ui.label_4->setVisible(true);
			this->ui.label_5->setVisible(false);
		}
		else
		{
			this->ui.label_4->setVisible(false);
			this->ui.label_5->setVisible(true);
		};
	};
}