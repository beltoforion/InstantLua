/********************************************************************************
** Form generated from reading UI file 'DlgSettings.ui'
**
** Created: Tue 18. Sep 18:40:23 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGSETTINGS_H
#define UI_DLGSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgSettings
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QLabel *lbCaption;
    QLabel *lbSubCaption;
    QLabel *lbIcon;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tcPreferences;
    QWidget *tabPaths;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbCapProjectDir;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *edProjectDir;
    QPushButton *btnSelectProjectDir;
    QSpacerItem *verticalSpacer;
    QWidget *tabEditor;
    QVBoxLayout *verticalLayout;
    QCheckBox *cbLineNumbers;
    QCheckBox *cbFolding;
    QHBoxLayout *layoutFontSize;
    QSpinBox *sbFontSize;
    QLabel *lbFontSize;
    QHBoxLayout *layoutTabIndent;
    QSpinBox *sbTabIndent;
    QLabel *lbTabIndent;
    QSpacerItem *verticalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DlgSettings)
    {
        if (DlgSettings->objectName().isEmpty())
            DlgSettings->setObjectName(QString::fromUtf8("DlgSettings"));
        DlgSettings->setWindowModality(Qt::WindowModal);
        DlgSettings->resize(450, 308);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DlgSettings->sizePolicy().hasHeightForWidth());
        DlgSettings->setSizePolicy(sizePolicy);
        DlgSettings->setMinimumSize(QSize(450, 250));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/ico_settings"), QSize(), QIcon::Normal, QIcon::Off);
        DlgSettings->setWindowIcon(icon);
        DlgSettings->setModal(true);
        verticalLayout_3 = new QVBoxLayout(DlgSettings);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setContentsMargins(4, 4, 4, 4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget = new QWidget(DlgSettings);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 60));
        widget->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c, stop: 0.5 #66b, stop: 1 #77c);\n"
"border: 1px solid gray;\n"
"/*border-radius: 7;*/\n"
"/*\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 20, 100, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color:rgb(255, 255, 255);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 1px solid gray;\n"
"border-radius: 4px;\n"
"*/"));
        lbCaption = new QLabel(widget);
        lbCaption->setObjectName(QString::fromUtf8("lbCaption"));
        lbCaption->setGeometry(QRect(67, 8, 175, 35));
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

        verticalLayout_3->addWidget(widget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tcPreferences = new QTabWidget(DlgSettings);
        tcPreferences->setObjectName(QString::fromUtf8("tcPreferences"));
        tabPaths = new QWidget();
        tabPaths->setObjectName(QString::fromUtf8("tabPaths"));
        verticalLayout_5 = new QVBoxLayout(tabPaths);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lbCapProjectDir = new QLabel(tabPaths);
        lbCapProjectDir->setObjectName(QString::fromUtf8("lbCapProjectDir"));

        horizontalLayout_2->addWidget(lbCapProjectDir);

        horizontalSpacer = new QSpacerItem(378, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        edProjectDir = new QLineEdit(tabPaths);
        edProjectDir->setObjectName(QString::fromUtf8("edProjectDir"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(edProjectDir->sizePolicy().hasHeightForWidth());
        edProjectDir->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(edProjectDir);

        btnSelectProjectDir = new QPushButton(tabPaths);
        btnSelectProjectDir->setObjectName(QString::fromUtf8("btnSelectProjectDir"));
        btnSelectProjectDir->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_3->addWidget(btnSelectProjectDir);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(488, 160, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        verticalLayout_5->addLayout(verticalLayout_4);

        tcPreferences->addTab(tabPaths, QString());
        tabEditor = new QWidget();
        tabEditor->setObjectName(QString::fromUtf8("tabEditor"));
        verticalLayout = new QVBoxLayout(tabEditor);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        cbLineNumbers = new QCheckBox(tabEditor);
        cbLineNumbers->setObjectName(QString::fromUtf8("cbLineNumbers"));

        verticalLayout->addWidget(cbLineNumbers);

        cbFolding = new QCheckBox(tabEditor);
        cbFolding->setObjectName(QString::fromUtf8("cbFolding"));

        verticalLayout->addWidget(cbFolding);

        layoutFontSize = new QHBoxLayout();
        layoutFontSize->setObjectName(QString::fromUtf8("layoutFontSize"));
        sbFontSize = new QSpinBox(tabEditor);
        sbFontSize->setObjectName(QString::fromUtf8("sbFontSize"));
        sbFontSize->setMaximumSize(QSize(50, 16777215));
        sbFontSize->setMinimum(6);
        sbFontSize->setMaximum(30);
        sbFontSize->setValue(10);

        layoutFontSize->addWidget(sbFontSize);

        lbFontSize = new QLabel(tabEditor);
        lbFontSize->setObjectName(QString::fromUtf8("lbFontSize"));

        layoutFontSize->addWidget(lbFontSize);


        verticalLayout->addLayout(layoutFontSize);

        layoutTabIndent = new QHBoxLayout();
        layoutTabIndent->setObjectName(QString::fromUtf8("layoutTabIndent"));
        sbTabIndent = new QSpinBox(tabEditor);
        sbTabIndent->setObjectName(QString::fromUtf8("sbTabIndent"));
        sbTabIndent->setMaximumSize(QSize(50, 16777215));
        sbTabIndent->setMinimum(2);
        sbTabIndent->setMaximum(10);
        sbTabIndent->setValue(2);

        layoutTabIndent->addWidget(sbTabIndent);

        lbTabIndent = new QLabel(tabEditor);
        lbTabIndent->setObjectName(QString::fromUtf8("lbTabIndent"));

        layoutTabIndent->addWidget(lbTabIndent);


        verticalLayout->addLayout(layoutTabIndent);

        verticalSpacer_2 = new QSpacerItem(20, 139, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        tcPreferences->addTab(tabEditor, QString());

        verticalLayout_2->addWidget(tcPreferences);

        buttonBox = new QDialogButtonBox(DlgSettings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(DlgSettings);
        QObject::connect(buttonBox, SIGNAL(accepted()), DlgSettings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DlgSettings, SLOT(reject()));

        tcPreferences->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DlgSettings);
    } // setupUi

    void retranslateUi(QDialog *DlgSettings)
    {
        DlgSettings->setWindowTitle(QApplication::translate("DlgSettings", "Preferences", 0, QApplication::UnicodeUTF8));
        lbCaption->setText(QApplication::translate("DlgSettings", "Editor Settings", 0, QApplication::UnicodeUTF8));
        lbSubCaption->setText(QApplication::translate("DlgSettings", "Edit the LUA Text editor preferences here", 0, QApplication::UnicodeUTF8));
        lbIcon->setText(QString());
        lbCapProjectDir->setText(QApplication::translate("DlgSettings", "Project directory", 0, QApplication::UnicodeUTF8));
        btnSelectProjectDir->setText(QApplication::translate("DlgSettings", "...", 0, QApplication::UnicodeUTF8));
        tcPreferences->setTabText(tcPreferences->indexOf(tabPaths), QApplication::translate("DlgSettings", "Paths", 0, QApplication::UnicodeUTF8));
        cbLineNumbers->setText(QApplication::translate("DlgSettings", "Show line numbers", 0, QApplication::UnicodeUTF8));
        cbFolding->setText(QApplication::translate("DlgSettings", "Enable source code folding", 0, QApplication::UnicodeUTF8));
        sbFontSize->setSuffix(QString());
        sbFontSize->setPrefix(QString());
        lbFontSize->setText(QApplication::translate("DlgSettings", "Font size", 0, QApplication::UnicodeUTF8));
        lbTabIndent->setText(QApplication::translate("DlgSettings", "Tabulator indentation", 0, QApplication::UnicodeUTF8));
        tcPreferences->setTabText(tcPreferences->indexOf(tabEditor), QApplication::translate("DlgSettings", "Editor", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgSettings: public Ui_DlgSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGSETTINGS_H
