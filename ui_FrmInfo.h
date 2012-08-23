/********************************************************************************
** Form generated from reading UI file 'FrmInfo.ui'
**
** Created: Sun 19. Aug 22:33:24 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMINFO_H
#define UI_FRMINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmInfo
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QLabel *lbTitle;
    QLabel *lbSubTitle;
    QLabel *label_4;

    void setupUi(QWidget *FrmInfo)
    {
        if (FrmInfo->objectName().isEmpty())
            FrmInfo->setObjectName(QString::fromUtf8("FrmInfo"));
        FrmInfo->resize(706, 79);
        verticalLayout = new QVBoxLayout(FrmInfo);
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(FrmInfo);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 20, 100, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color:rgb(255, 255, 255);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 1px solid gray;\n"
"border-radius: 4px;\n"
""));
        lbTitle = new QLabel(widget);
        lbTitle->setObjectName(QString::fromUtf8("lbTitle"));
        lbTitle->setGeometry(QRect(60, 10, 491, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(false);
        font.setWeight(50);
        lbTitle->setFont(font);
        lbTitle->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"border-style: none;\n"
"background-color: none;\n"
"background-image: none;\n"
"background-position: none;\n"
""));
        lbSubTitle = new QLabel(widget);
        lbSubTitle->setObjectName(QString::fromUtf8("lbSubTitle"));
        lbSubTitle->setGeometry(QRect(70, 50, 411, 16));
        lbSubTitle->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"border-style: none;\n"
"background-color: none;\n"
"background-image: none;\n"
"background-position: none;\n"
""));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 15, 48, 48));
        label_4->setMinimumSize(QSize(48, 48));
        label_4->setMaximumSize(QSize(48, 48));
        label_4->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(10, 10, 50, 255), stop:1 rgba(200, 200, 200, 255));\n"
"border: 1px solid white;\n"
"border-radius: 8px;"));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/ico_settings")));
        lbSubTitle->raise();
        label_4->raise();
        lbTitle->raise();

        verticalLayout->addWidget(widget);


        retranslateUi(FrmInfo);

        QMetaObject::connectSlotsByName(FrmInfo);
    } // setupUi

    void retranslateUi(QWidget *FrmInfo)
    {
        FrmInfo->setWindowTitle(QApplication::translate("FrmInfo", "Form", 0, QApplication::UnicodeUTF8));
        lbTitle->setText(QApplication::translate("FrmInfo", "Saving File...", 0, QApplication::UnicodeUTF8));
        lbSubTitle->setText(QApplication::translate("FrmInfo", "Lorem ipsum dolor sit amet, consectetur, adipisci velit", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FrmInfo: public Ui_FrmInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMINFO_H
