/********************************************************************************
** Form generated from reading UI file 'counter.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUNTER_H
#define UI_COUNTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Counter
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPushButton *buttonAnalize;
    QPushButton *buttonOpenFile;
    QPushButton *buttonSave;
    QPlainTextEdit *plainTextEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Counter)
    {
        if (Counter->objectName().isEmpty())
            Counter->setObjectName(QString::fromUtf8("Counter"));
        Counter->resize(512, 400);
        centralwidget = new QWidget(Counter);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        buttonAnalize = new QPushButton(centralwidget);
        buttonAnalize->setObjectName(QString::fromUtf8("buttonAnalize"));
        buttonAnalize->setEnabled(false);

        verticalLayout->addWidget(buttonAnalize);

        buttonOpenFile = new QPushButton(centralwidget);
        buttonOpenFile->setObjectName(QString::fromUtf8("buttonOpenFile"));

        verticalLayout->addWidget(buttonOpenFile);

        buttonSave = new QPushButton(centralwidget);
        buttonSave->setObjectName(QString::fromUtf8("buttonSave"));
        buttonSave->setEnabled(false);

        verticalLayout->addWidget(buttonSave);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setMinimumSize(QSize(500, 300));
        plainTextEdit->setReadOnly(true);

        verticalLayout->addWidget(plainTextEdit);

        Counter->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Counter);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Counter->setStatusBar(statusbar);

        retranslateUi(Counter);

        QMetaObject::connectSlotsByName(Counter);
    } // setupUi

    void retranslateUi(QMainWindow *Counter)
    {
        Counter->setWindowTitle(QCoreApplication::translate("Counter", "Counter", nullptr));
        buttonAnalize->setText(QCoreApplication::translate("Counter", "Analize", nullptr));
        buttonOpenFile->setText(QCoreApplication::translate("Counter", "Open File", nullptr));
        buttonSave->setText(QCoreApplication::translate("Counter", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Counter: public Ui_Counter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTER_H
