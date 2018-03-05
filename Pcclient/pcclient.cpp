#include "pcclient.h"
#include "ui_pcclient.h"

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
