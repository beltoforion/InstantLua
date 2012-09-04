/********************************************************************************
** Form generated from reading UI file 'FrmProjectExplorer.ui'
**
** Created: Mon 3. Sep 22:39:06 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMPROJECTEXPLORER_H
#define UI_FRMPROJECTEXPLORER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "QGradientPanel.h"

QT_BEGIN_NAMESPACE

class Ui_FrmProjectExplorer
{
public:
    QHBoxLayout *horizontalLayout;
    QSplitter *spExplorer;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QGradientPanel *paCaption;
    QTabWidget *tabCommands;
    QWidget *tsOutline;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *tvOutline;
    QWidget *tab;

    void setupUi(QWidget *FrmProjectExplorer)
    {
        if (FrmProjectExplorer->objectName().isEmpty())
            FrmProjectExplorer->setObjectName(QString::fromUtf8("FrmProjectExplorer"));
        FrmProjectExplorer->resize(346, 664);
        horizontalLayout = new QHBoxLayout(FrmProjectExplorer);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spExplorer = new QSplitter(FrmProjectExplorer);
        spExplorer->setObjectName(QString::fromUtf8("spExplorer"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spExplorer->sizePolicy().hasHeightForWidth());
        spExplorer->setSizePolicy(sizePolicy);
        spExplorer->setOrientation(Qt::Vertical);
        spExplorer->setOpaqueResize(true);
        spExplorer->setHandleWidth(6);
        frame = new QFrame(spExplorer);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        paCaption = new QGradientPanel(frame);
        paCaption->setObjectName(QString::fromUtf8("paCaption"));
        paCaption->setMinimumSize(QSize(0, 25));
        paCaption->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(paCaption);

        tabCommands = new QTabWidget(frame);
        tabCommands->setObjectName(QString::fromUtf8("tabCommands"));
        tabCommands->setTabShape(QTabWidget::Rounded);
        tsOutline = new QWidget();
        tsOutline->setObjectName(QString::fromUtf8("tsOutline"));
        tsOutline->setEnabled(true);
        horizontalLayout_2 = new QHBoxLayout(tsOutline);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tvOutline = new QTreeWidget(tsOutline);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(1, QString::fromUtf8("2"));
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        tvOutline->setHeaderItem(__qtreewidgetitem);
        tvOutline->setObjectName(QString::fromUtf8("tvOutline"));
        tvOutline->setStyleSheet(QString::fromUtf8(""));
        tvOutline->setAlternatingRowColors(true);
        tvOutline->setIndentation(15);
        tvOutline->setRootIsDecorated(true);
        tvOutline->setAllColumnsShowFocus(false);
        tvOutline->setColumnCount(2);
        tvOutline->header()->setVisible(true);
        tvOutline->header()->setMinimumSectionSize(20);
        tvOutline->header()->setProperty("showSortIndicator", QVariant(true));
        tvOutline->header()->setStretchLastSection(false);

        horizontalLayout_2->addWidget(tvOutline);

        tabCommands->addTab(tsOutline, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabCommands->addTab(tab, QString());

        verticalLayout->addWidget(tabCommands);

        spExplorer->addWidget(frame);

        horizontalLayout->addWidget(spExplorer);


        retranslateUi(FrmProjectExplorer);

        tabCommands->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FrmProjectExplorer);
    } // setupUi

    void retranslateUi(QWidget *FrmProjectExplorer)
    {
        FrmProjectExplorer->setWindowTitle(QApplication::translate("FrmProjectExplorer", "Form", 0, QApplication::UnicodeUTF8));
        tabCommands->setTabText(tabCommands->indexOf(tsOutline), QApplication::translate("FrmProjectExplorer", "Outline", 0, QApplication::UnicodeUTF8));
        tabCommands->setTabText(tabCommands->indexOf(tab), QApplication::translate("FrmProjectExplorer", "Seite", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FrmProjectExplorer: public Ui_FrmProjectExplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMPROJECTEXPLORER_H
