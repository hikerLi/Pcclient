#include "pcclient.h"
#include "ui_pcclient.h"
#include <QDir>
#include <QFileDialog>
#include <QTextBlock>
#include <packagemanager.h>


Pcclient::Pcclient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pcclient)
{
    ui->setupUi(this);

    PackMgr.Start();
}

Pcclient::~Pcclient()
{
    delete ui;
}

void Pcclient::on_toolButton_clicked()
{
    QString directory = QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("Save path"),QDir::currentPath()));
}

void Pcclient::on_SendButton_clicked()
{
    PackageConfig package;
    LoadPackageConfig(package);
    PackMgr.SendPackage(package);
}

void Pcclient::on_AddToTimerTaskButton_clicked()
{
    PackageConfig package;
    LoadPackageConfig(package);
}

void Pcclient::LoadPackageConfig(PackageConfig &Package)
{
    Package.sType = (EMSTREAMTYPE)ui->StreamType->currentIndex();
    Package.pType = (EMPROTOTYPE)ui->ProtoType->currentIndex();
    if(Package.sType != EMSTREAMTYPE::NONE){
        Package.streamFilePath = ui->StreamFilePath->currentText().toStdString();
    }
    Package.ePort.ip = ui->LEIP->text().toStdString();
    Package.ePort.port = ui->LEPort->text().toShort();
    Package.tType = (EMTIMERTYPE)ui->Timer->currentIndex();

    auto sendheaderdocument = ui->PTESenderHeader->document();
    for(QTextBlock textblock = sendheaderdocument->begin(); textblock != sendheaderdocument->end(); textblock = textblock.next()){
        Package.headerLines.push_back(textblock.text().toStdString());
    }

    auto payloaddocument = ui->PTESenderPayload->document();
    for(QTextBlock textblock = payloaddocument->begin(); textblock != payloaddocument->end(); textblock = textblock.next()){
        Package.paylaodLines.push_back(textblock.text().toStdString());
    }

}
