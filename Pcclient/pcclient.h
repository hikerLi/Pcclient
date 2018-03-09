#ifndef PCCLIENT_H
#define PCCLIENT_H

#include <QMainWindow>
#include <common.h>
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

    void on_AddToTimerTaskButton_clicked();

private:
    void LoadPackageConfig(PackageConfig& Package);
private:
    Ui::Pcclient *ui;
};

#endif // PCCLIENT_H
