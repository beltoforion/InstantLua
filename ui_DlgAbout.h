/********************************************************************************
** Form generated from reading UI file 'DlgAbout.ui'
**
** Created: Sun 19. Aug 22:33:24 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGABOUT_H
#define UI_DLGABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgAbout
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QLabel *lbCaption;
    QLabel *lbSubCaption;
    QLabel *lbIcon;
    QVBoxLayout *verticalLayout_2;
    QListView *listView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DlgAbout)
    {
        if (DlgAbout->objectName().isEmpty())
            DlgAbout->setObjectName(QString::fromUtf8("DlgAbout"));
        DlgAbout->resize(400, 337);
        verticalLayout = new QVBoxLayout(DlgAbout);
        verticalLayout->setSpacing(3);
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(DlgAbout);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 60));
        widget->setMaximumSize(QSize(16777215, 50));
        widget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 20, 100, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color:rgb(255, 255, 255);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 1px solid gray;\n"
"border-radius: 4px;\n"
""));
        lbCaption = new QLabel(widget);
        lbCaption->setObjectName(QString::fromUtf8("lbCaption"));
        lbCaption->setGeometry(QRect(67, 8, 291, 35));
        QFont font;
        font.setPointSize(16);
        lbCaption->setFont(font);
        lbCaption->setAutoFillBackground(false);
        lbCaption->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"border-style: none;\n"
"background-color: none;\n"
"background-image: none;\n"
"background-position: none;\n"
""));
        lbCaption->setFrameShape(QFrame::NoFrame);
        lbCaption->setFrameShadow(QFrame::Plain);
        lbCaption->setIndent(0);
        lbSubCaption = new QLabel(widget);
        lbSubCaption->setObjectName(QString::fromUtf8("lbSubCaption"));
        lbSubCaption->setGeometry(QRect(70, 38, 243, 18));
        lbSubCaption->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"border-style: none;\n"
"background-color: rgba(0,0,0,0);\n"
"background-image: none;\n"
"background-position: center right;"));
        lbSubCaption->setIndent(0);
        lbIcon = new QLabel(widget);
        lbIcon->setObjectName(QString::fromUtf8("lbIcon"));
        lbIcon->setGeometry(QRect(11, 8, 48, 48));
        lbIcon->setMinimumSize(QSize(48, 48));
        lbIcon->setMaximumSize(QSize(48, 48));
        lbIcon->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(10, 10, 50, 255), stop:1 rgba(200, 200, 200, 255));\n"
"border: 1px solid white;\n"
"border-radius: 8px;"));
        lbIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/ico_settings")));

        verticalLayout->addWidget(widget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, -1);
        listView = new QListView(DlgAbout);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout_2->addWidget(listView);


        verticalLayout->addLayout(verticalLayout_2);

        buttonBox = new QDialogButtonBox(DlgAbout);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DlgAbout);
        QObject::connect(buttonBox, SIGNAL(accepted()), DlgAbout, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DlgAbout, SLOT(reject()));

        QMetaObject::connectSlotsByName(DlgAbout);
    } // setupUi

    void retranslateUi(QDialog *DlgAbout)
    {
        DlgAbout->setWindowTitle(QApplication::translate("DlgAbout", "About the Instant LUA IDE", 0, QApplication::UnicodeUTF8));
        lbCaption->setText(QApplication::translate("DlgAbout", "Instant Lua", 0, QApplication::UnicodeUTF8));
        lbSubCaption->setText(QApplication::translate("DlgAbout", "(C) 2012 Ingo Berg (beltoforion.de)", 0, QApplication::UnicodeUTF8));
        lbIcon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DlgAbout: public Ui_DlgAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGABOUT_H
