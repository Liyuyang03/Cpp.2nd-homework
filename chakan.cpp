#pragma execution_character_set("utf-8")

#include "chakan.h"
#include "mainwindow.h"

chakan::chakan(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
	connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(quedingchakan()));
    connect(ui.pushButton_2, SIGNAL(clicked(bool)), this, SLOT(Closechakan()));
    connect(ui.pushButton_3, SIGNAL(clicked(bool)), this, SLOT(choosechakan()));
}

void chakan::Closechakan()
{
    mainwindow* m = new mainwindow;
    m->show();
    this->close();
}

void chakan::choosechakan()
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

void chakan::quedingchakan()
{
	QListWidgetItem* selectedItem=this->ui.listWidget->currentItem();
	if (selectedItem)
	{
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
			this->ui.label_A->clear();
			this->ui.label_B->clear();
			this->ui.label_C->clear();
			this->ui.label_D->clear();
			this->ui.label_answer->setText(totalList[2]);
		}
		else if (type == "xuanze")//选择题
		{
			this->ui.label_A->setText(totalList[2]);
			this->ui.label_B->setText(totalList[3]);
			this->ui.label_C->setText(totalList[4]);
			this->ui.label_D->setText(totalList[5]);
			this->ui.label_answer->setText(totalList[6]);
		};
	};
}