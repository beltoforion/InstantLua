/********************************************************************************
** Form generated from reading UI file 'QGradientPanel.ui'
**
** Created: Tue 18. Sep 18:40:23 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGRADIENTPANEL_H
#define UI_QGRADIENTPANEL_H

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

class Ui_QGradientPanel
{
public:
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbCaption;
    QLabel *lbImage;
    QVBoxLayout *verticalLayout;
    QLabel *lbInfo1;
    QLabel *lbInfo2;

    void setupUi(QWidget *QGradientPanel)
    {
        if (QGradientPanel->objectName().isEmpty())
            QGradientPanel->setObjectName(QString::fromUtf8("QGradientPanel"));
        QGradientPanel->resize(793, 38);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QGradientPanel->sizePolicy().hasHeightForWidth());
        QGradientPanel->setSizePolicy(sizePolicy);
        QGradientPanel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #eef, stop: 0.49 #78b, stop: 0.5 #66b, stop: 1 #8ac);\n"
"border-width: 1px;\n"
"border-color: #000;\n"
"border-style: solid;\n"
"border-radius: 4;\n"
"\n"
""));
        horizontalLayout_2 = new QHBoxLayout(QGradientPanel);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 2, 0, 2);
        lbCaption = new QLabel(QGradientPanel);
        lbCaption->setObjectName(QString::fromUtf8("lbCaption"));
        lbCaption->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(13);
        lbCaption->setFont(font);
        lbCaption->setStyleSheet(QString::fromUtf8("border-style: none;\n"
"background-color: none;\n"
"background-image: none;\n"
"background-position: none;"));

        horizontalLayout_2->addWidget(lbCaption);

        lbImage = new QLabel(QGradientPanel);
        lbImage->setObjectName(QString::fromUtf8("lbImage"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbImage->sizePolicy().hasHeightForWidth());
        lbImage->setSizePolicy(sizePolicy1);
        lbImage->setStyleSheet(QString::fromUtf8("border-style: none;\n"
"background-color: none;\n"
"background-image: none;\n"
"background-position: none;"));
        lbImage->setScaledContents(false);
        lbImage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lbImage);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbInfo1 = new QLabel(QGradientPanel);
        lbInfo1->setObjectName(QString::fromUtf8("lbInfo1"));
        lbInfo1->setStyleSheet(QString::fromUtf8("border-style: none;\n"
"background-color: none;\n"
"background-image: none;\n"
"background-position: none;"));
        lbInfo1->setMargin(0);

        verticalLayout->addWidget(lbInfo1);

        lbInfo2 = new QLabel(QGradientPanel);
        lbInfo2->setObjectName(QString::fromUtf8("lbInfo2"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lbInfo2->sizePolicy().hasHeightForWidth());
        lbInfo2->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(8);
        lbInfo2->setFont(font1);
        lbInfo2->setStyleSheet(QString::fromUtf8("border-style: none;\n"
"background-color: none;\n"
"background-image: none;\n"
"background-position: none;"));

        verticalLayout->addWidget(lbInfo2);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(QGradientPanel);

        QMetaObject::connectSlotsByName(QGradientPanel);
    } // setupUi

    void retranslateUi(QWidget *QGradientPanel)
    {
        QGradientPanel->setWindowTitle(QApplication::translate("QGradientPanel", "Form", 0, QApplication::UnicodeUTF8));
        lbCaption->setText(QApplication::translate("QGradientPanel", "Caption", 0, QApplication::UnicodeUTF8));
        lbImage->setText(QString());
        lbInfo1->setText(QApplication::translate("QGradientPanel", "Line1", 0, QApplication::UnicodeUTF8));
        lbInfo2->setText(QApplication::translate("QGradientPanel", "Line2................................................................................................", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QGradientPanel: public Ui_QGradientPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGRADIENTPANEL_H
