#include "pcclient.h"
#include "ui_pcclient.h"
#include <QDir>
#include <QFileDialog>

Pcclient::Pcclient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pcclient)
{
    ui->setupUi(this);
}

Pcclient::~Pcclient()
{
    delete ui;
}

void Pcclient::on_toolButton_clicked()
{
    QString directory = QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("Save path"),QDir::currentPath()));
}
