/********************************************************************************
** Form generated from reading UI file 'FrmFileExplorer.ui'
**
** Created: Sun 2. Sep 18:13:45 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMFILEEXPLORER_H
#define UI_FRMFILEEXPLORER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "FileExplorerTabWidget.h"
#include "QGradientPanel.h"

QT_BEGIN_NAMESPACE

class Ui_FrmFileExplorer
{
public:
    QAction *actionClose;
    QAction *actionClose_All_But_This;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGradientPanel *paCaption;
    FileExplorerTabWidget *tcProject;

    void setupUi(QWidget *FrmFileExplorer)
    {
        if (FrmFileExplorer->objectName().isEmpty())
            FrmFileExplorer->setObjectName(QString::fromUtf8("FrmFileExplorer"));
        FrmFileExplorer->resize(480, 438);
        actionClose = new QAction(FrmFileExplorer);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/res/tab-close-3.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon);
        actionClose_All_But_This = new QAction(FrmFileExplorer);
        actionClose_All_But_This->setObjectName(QString::fromUtf8("actionClose_All_But_This"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/res/tab-close-other.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose_All_But_This->setIcon(icon1);
        horizontalLayout = new QHBoxLayout(FrmFileExplorer);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 1, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
#ifndef Q_OS_MAC
        verticalLayout->setContentsMargins(0, 0, 0, 0);
#endif
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        paCaption = new QGradientPanel(FrmFileExplorer);
        paCaption->setObjectName(QString::fromUtf8("paCaption"));
        paCaption->setMinimumSize(QSize(0, 25));
        paCaption->setAutoFillBackground(false);

        verticalLayout->addWidget(paCaption);

        tcProject = new FileExplorerTabWidget(FrmFileExplorer);
        tcProject->setObjectName(QString::fromUtf8("tcProject"));
        tcProject->setTabPosition(QTabWidget::North);
        tcProject->setTabsClosable(true);
        tcProject->setMovable(true);

        verticalLayout->addWidget(tcProject);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(FrmFileExplorer);

        tcProject->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(FrmFileExplorer);
    } // setupUi

    void retranslateUi(QWidget *FrmFileExplorer)
    {
        FrmFileExplorer->setWindowTitle(QApplication::translate("FrmFileExplorer", "Form", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("FrmFileExplorer", "Close", 0, QApplication::UnicodeUTF8));
        actionClose_All_But_This->setText(QApplication::translate("FrmFileExplorer", "Close All But This", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FrmFileExplorer: public Ui_FrmFileExplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMFILEEXPLORER_H
