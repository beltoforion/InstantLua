/********************************************************************************
** Form generated from reading UI file 'FrmProjectExplorer.ui'
**
** Created: Sun 19. Aug 22:33:24 2012
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
#include <QtGui/QLabel>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmProjectExplorer
{
public:
    QHBoxLayout *horizontalLayout;
    QSplitter *spExplorer;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *lbCapExplorer;
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
        verticalLayout->setSpacing(5);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbCapExplorer = new QLabel(frame);
        lbCapExplorer->setObjectName(QString::fromUtf8("lbCapExplorer"));
        QFont font;
        font.setPointSize(12);
        lbCapExplorer->setFont(font);
        lbCapExplorer->setAutoFillBackground(false);
        lbCapExplorer->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 112, 255), stop:1 rgba(220, 240, 220, 255));\n"
"color: rgb(255, 255, 255);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 1px solid gray;\n"
"border-radius: 2px;"));
        lbCapExplorer->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lbCapExplorer->setMargin(3);
        lbCapExplorer->setIndent(5);

        verticalLayout->addWidget(lbCapExplorer);

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
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        tvOutline->setHeaderItem(__qtreewidgetitem);
        tvOutline->setObjectName(QString::fromUtf8("tvOutline"));

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
        lbCapExplorer->setText(QApplication::translate("FrmProjectExplorer", "Explorer", 0, QApplication::UnicodeUTF8));
        tabCommands->setTabText(tabCommands->indexOf(tsOutline), QApplication::translate("FrmProjectExplorer", "Outline", 0, QApplication::UnicodeUTF8));
        tabCommands->setTabText(tabCommands->indexOf(tab), QApplication::translate("FrmProjectExplorer", "Seite", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FrmProjectExplorer: public Ui_FrmProjectExplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMPROJECTEXPLORER_H