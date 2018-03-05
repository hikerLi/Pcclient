/********************************************************************************
** Form generated from reading UI file 'pcclient.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCCLIENT_H
#define UI_PCCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pcclient
{
public:
    QWidget *centralWidget;
    QListView *listView;
    QListView *listView_2;
    QLineEdit *lineEdit;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_7;
    QListView *listView_3;
    QLabel *label_8;
    QListView *listView_4;
    QLabel *label_9;
    QLineEdit *lineEdit_2;
    QComboBox *comboBox_4;
    QLineEdit *lineEdit_3;
    QLabel *label_10;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_6;
    QComboBox *comboBox_3;
    QLabel *label_5;
    QComboBox *comboBox_6;
    QToolButton *toolButton;
    QComboBox *comboBox_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Pcclient)
    {
        if (Pcclient->objectName().isEmpty())
            Pcclient->setObjectName(QStringLiteral("Pcclient"));
        Pcclient->resize(799, 544);
        centralWidget = new QWidget(Pcclient);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(30, 100, 256, 121));
        listView_2 = new QListView(centralWidget);
        listView_2->setObjectName(QStringLiteral("listView_2"));
        listView_2->setGeometry(QRect(30, 260, 256, 111));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 400, 251, 22));
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(30, 430, 79, 22));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 430, 80, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 380, 121, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 230, 121, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 70, 121, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(420, 80, 121, 16));
        listView_3 = new QListView(centralWidget);
        listView_3->setObjectName(QStringLiteral("listView_3"));
        listView_3->setGeometry(QRect(420, 110, 256, 121));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(420, 240, 121, 16));
        listView_4 = new QListView(centralWidget);
        listView_4->setObjectName(QStringLiteral("listView_4"));
        listView_4->setGeometry(QRect(420, 270, 256, 111));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(420, 390, 121, 16));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(420, 410, 251, 22));
        comboBox_4 = new QComboBox(centralWidget);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(30, 430, 79, 22));
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(420, 460, 251, 22));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(420, 440, 121, 16));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 10, 701, 72));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        comboBox = new QComboBox(horizontalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        comboBox_3 = new QComboBox(horizontalLayoutWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        horizontalLayout->addWidget(comboBox_3);

        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        comboBox_6 = new QComboBox(horizontalLayoutWidget);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));

        horizontalLayout->addWidget(comboBox_6);

        toolButton = new QToolButton(horizontalLayoutWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        horizontalLayout->addWidget(toolButton);

        comboBox_5 = new QComboBox(horizontalLayoutWidget);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));

        horizontalLayout->addWidget(comboBox_5);

        Pcclient->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Pcclient);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 799, 19));
        Pcclient->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Pcclient);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Pcclient->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Pcclient);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Pcclient->setStatusBar(statusBar);

        retranslateUi(Pcclient);

        QMetaObject::connectSlotsByName(Pcclient);
    } // setupUi

    void retranslateUi(QMainWindow *Pcclient)
    {
        Pcclient->setWindowTitle(QApplication::translate("Pcclient", "Pcclient", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Pcclient", "tcp", 0)
         << QApplication::translate("Pcclient", "udp", 0)
        );
        pushButton->setText(QApplication::translate("Pcclient", "Send", 0));
        label->setText(QApplication::translate("Pcclient", "MessageName:", 0));
        label_2->setText(QApplication::translate("Pcclient", "Payload:", 0));
        label_3->setText(QApplication::translate("Pcclient", "Header:", 0));
        label_7->setText(QApplication::translate("Pcclient", "Header:", 0));
        label_8->setText(QApplication::translate("Pcclient", "Payload:", 0));
        label_9->setText(QApplication::translate("Pcclient", "MessageName:", 0));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("Pcclient", "tcp", 0)
         << QApplication::translate("Pcclient", "udp", 0)
        );
        label_10->setText(QApplication::translate("Pcclient", "Pattern:", 0));
        label_4->setText(QApplication::translate("Pcclient", "ProtoType:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Pcclient", "empty", 0)
         << QApplication::translate("Pcclient", "protobuffer", 0)
         << QApplication::translate("Pcclient", "flatbuffer", 0)
        );
        label_6->setText(QApplication::translate("Pcclient", "Timer:", 0));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("Pcclient", "Once", 0)
         << QApplication::translate("Pcclient", "5s", 0)
         << QApplication::translate("Pcclient", "10s", 0)
         << QApplication::translate("Pcclient", "30s", 0)
         << QApplication::translate("Pcclient", "1min", 0)
         << QApplication::translate("Pcclient", "15min", 0)
        );
        label_5->setText(QApplication::translate("Pcclient", "ProtoType:", 0));
        toolButton->setText(QApplication::translate("Pcclient", "...", 0));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("Pcclient", "tcp", 0)
         << QApplication::translate("Pcclient", "udp", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class Pcclient: public Ui_Pcclient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCCLIENT_H
