/********************************************************************************
** Form generated from reading UI file 'FrmConsole.ui'
**
** Created: Sat 25. Aug 00:46:52 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMCONSOLE_H
#define UI_FRMCONSOLE_H

#include <QCommandPrompt.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmConsole
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *lbCapDebug;
    QCommandPrompt *edConsole;

    void setupUi(QWidget *FrmConsole)
    {
        if (FrmConsole->objectName().isEmpty())
            FrmConsole->setObjectName(QString::fromUtf8("FrmConsole"));
        FrmConsole->resize(400, 300);
        horizontalLayout = new QHBoxLayout(FrmConsole);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbCapDebug = new QLabel(FrmConsole);
        lbCapDebug->setObjectName(QString::fromUtf8("lbCapDebug"));
        QFont font;
        font.setPointSize(12);
        lbCapDebug->setFont(font);
        lbCapDebug->setAutoFillBackground(false);
        lbCapDebug->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 112, 255), stop:1 rgba(220, 240, 220, 255));\n"
"color: rgb(255, 255, 255);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 1px solid gray;\n"
"border-radius: 2px;"));
        lbCapDebug->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lbCapDebug->setMargin(3);
        lbCapDebug->setIndent(5);

        verticalLayout->addWidget(lbCapDebug);

        edConsole = new QCommandPrompt(FrmConsole);
        edConsole->setObjectName(QString::fromUtf8("edConsole"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Courier New"));
        edConsole->setFont(font1);

        verticalLayout->addWidget(edConsole);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(FrmConsole);

        QMetaObject::connectSlotsByName(FrmConsole);
    } // setupUi

    void retranslateUi(QWidget *FrmConsole)
    {
        FrmConsole->setWindowTitle(QApplication::translate("FrmConsole", "Form", 0, QApplication::UnicodeUTF8));
        lbCapDebug->setText(QApplication::translate("FrmConsole", "Console", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FrmConsole: public Ui_FrmConsole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMCONSOLE_H
