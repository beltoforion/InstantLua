/********************************************************************************
** Form generated from reading UI file 'QSelection.ui'
**
** Created: Mon 3. Sep 22:39:06 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSELECTION_H
#define UI_QSELECTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QSelection
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;

    void setupUi(QWidget *QSelection)
    {
        if (QSelection->objectName().isEmpty())
            QSelection->setObjectName(QString::fromUtf8("QSelection"));
        QSelection->resize(169, 127);
        verticalLayout = new QVBoxLayout(QSelection);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(QSelection);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #77c, stop: 0.1 #dde, stop: 0.49 #679, stop: 0.5 #559, stop: 1 #78b);\n"
"border-width: 1px;\n"
"border-color: #000;\n"
"border-style: solid;\n"
"border-radius: 2;\n"
"\n"
""));
        label_5->setMargin(0);

        verticalLayout->addWidget(label_5);

        label_3 = new QLabel(QSelection);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(12);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #66b, stop: 0.1 #ccd, stop: 0.49 #568, stop: 0.5 #448, stop: 1 #67a);\n"
"border-width: 1px;\n"
"border-color: #000;\n"
"border-style: solid;\n"
"border-radius: 2;\n"
"\n"
""));

        verticalLayout->addWidget(label_3);

        label = new QLabel(QSelection);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(16);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("color: white;\n"
"/*\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #eef, stop: 0.49 #78b, stop: 0.5 #66b, stop: 1 #8ac);\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #66b, stop: 0.1 #ccd, stop: 0.49 #568, stop: 0.5 #448, stop: 1 #67a);\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #55a, stop: 0.1 #bbc, stop: 0.49 #457, stop: 0.5 #337, stop: 1 #568);\n"
"*/\n"
"\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #448, stop: 0.1 #aab, stop: 0.49 #346, stop: 0.5 #226, stop: 1 #457);\n"
"\n"
"border-width: 3px;\n"
"border-color: #000;\n"
"border-style: solid;\n"
"border-radius:2;\n"
"\n"
""));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(QSelection);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #66b, stop: 0.1 #ccd, stop: 0.49 #568, stop: 0.5 #448, stop: 1 #67a);\n"
"border-width: 1px;\n"
"border-color: #000;\n"
"border-style: solid;\n"
"border-radius: 2;\n"
"\n"
""));

        verticalLayout->addWidget(label_2);

        label_4 = new QLabel(QSelection);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #77c, stop: 0.1 #dde, stop: 0.49 #679, stop: 0.5 #559, stop: 1 #78b);\n"
"border-width: 1px;\n"
"border-color: #000;\n"
"border-style: solid;\n"
"border-radius: 2;"));

        verticalLayout->addWidget(label_4);


        retranslateUi(QSelection);

        QMetaObject::connectSlotsByName(QSelection);
    } // setupUi

    void retranslateUi(QWidget *QSelection)
    {
        QSelection->setWindowTitle(QApplication::translate("QSelection", "Form", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("QSelection", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QSelection", "TextLabel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QSelection", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QSelection", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QSelection", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QSelection: public Ui_QSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSELECTION_H
