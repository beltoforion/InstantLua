/********************************************************************************
** Form generated from reading UI file 'FrmConsole.ui'
**
** Created: Tue 4. Sep 23:50:26 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMCONSOLE_H
#define UI_FRMCONSOLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "QCommandPrompt.h"
#include "QGradientPanel.h"

QT_BEGIN_NAMESPACE

class Ui_FrmConsole
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGradientPanel *paCaption;
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
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        paCaption = new QGradientPanel(FrmConsole);
        paCaption->setObjectName(QString::fromUtf8("paCaption"));
        paCaption->setMinimumSize(QSize(0, 25));

        verticalLayout->addWidget(paCaption);

        edConsole = new QCommandPrompt(FrmConsole);
        edConsole->setObjectName(QString::fromUtf8("edConsole"));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(10);
        edConsole->setFont(font);

        verticalLayout->addWidget(edConsole);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(FrmConsole);

        QMetaObject::connectSlotsByName(FrmConsole);
    } // setupUi

    void retranslateUi(QWidget *FrmConsole)
    {
        FrmConsole->setWindowTitle(QApplication::translate("FrmConsole", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FrmConsole: public Ui_FrmConsole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMCONSOLE_H
