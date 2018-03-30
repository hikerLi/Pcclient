#ifndef PCCLIENT_H
#define PCCLIENT_H

#include <QMainWindow>
#include <Common/common.h>
#include <pkghandler.h>

namespace Ui {
class Pcclient;
}

class Pcclient : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pcclient(QWidget *parent = 0);
    ~Pcclient();

private slots:
    void on_toolButton_clicked();

    void on_SendButton_clicked();

private:
    void LoadPackageConfig(PackageConfig& Package);
private:
    Ui::Pcclient *ui;

    PkgHandler mPkgHandle;
};

#endif // PCCLIENT_H
