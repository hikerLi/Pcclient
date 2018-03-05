#ifndef PCCLIENT_H
#define PCCLIENT_H

#include <QMainWindow>

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

private:
    Ui::Pcclient *ui;
};

#endif // PCCLIENT_H
