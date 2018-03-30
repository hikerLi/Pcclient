#include "pcclient.h"
#include "ui_pcclient.h"
#include <QDir>
#include <QFileDialog>
#include <QTextBlock>

#include <statics.h>


Pcclient::Pcclient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pcclient)
{
    ui->setupUi(this);

    Statics::Init();
    connect(&mPkgHandle, SIGNAL(EventLogSignal(QString)), ui->PTELog, SLOT(appendPlainText(QString)));
    connect(&mPkgHandle, SIGNAL(EventMessageSignal(QString)), ui->PTERecverHeader, SLOT(appendPlainText(QString)));
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
    mPkgHandle.Execute(package);
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
    Package.maxBuffSize = ui->LEMaxBuffSize->text().toInt();

    auto sendheaderdocument = ui->PTESenderHeader->document();
    for(QTextBlock textblock = sendheaderdocument->begin(); textblock != sendheaderdocument->end(); textblock = textblock.next()){
        Package.headerLines.push_back(textblock.text().toStdString());
    }

    auto payloaddocument = ui->PTESenderPayload->document();
    for(QTextBlock textblock = payloaddocument->begin(); textblock != payloaddocument->end(); textblock = textblock.next()){
        Package.paylaodLines.push_back(textblock.text().toStdString());
    }

    Package.bUseKcp = (1 == ui->UDPKCP->currentIndex());
}
