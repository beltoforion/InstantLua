/********************************************************************************
** Form generated from reading UI file 'WndMain.ui'
**
** Created: Tue 18. Sep 18:40:23 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WNDMAIN_H
#define UI_WNDMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WndMain
{
public:
    QAction *actionOpenFile;
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionQuit;
    QAction *actionPreferences;
    QAction *actionConsole;
    QAction *actionActionProjectExplorer;
    QAction *actionAbout;
    QAction *actionOpenProject;
    QAction *actionRun;
    QAction *actionActionStep;
    QAction *actionActionStepOver;
    QAction *actionActionStepOut;
    QAction *actionStop;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFrame *frmMain;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuRecentFiles;
    QMenu *menuSettings;
    QMenu *menuHelp;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *WndMain)
    {
        if (WndMain->objectName().isEmpty())
            WndMain->setObjectName(QString::fromUtf8("WndMain"));
        WndMain->resize(1024, 768);
        actionOpenFile = new QAction(WndMain);
        actionOpenFile->setObjectName(QString::fromUtf8("actionOpenFile"));
        actionOpenFile->setCheckable(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/ico_open_prj"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenFile->setIcon(icon);
        actionNew = new QAction(WndMain);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/ico_add_prj"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon1);
        actionSave = new QAction(WndMain);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/ico_save_all"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionSave_as = new QAction(WndMain);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/ico_save_as"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_as->setIcon(icon3);
        actionQuit = new QAction(WndMain);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/ico_exit"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon4);
        actionPreferences = new QAction(WndMain);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/ico_settings"), QSize(), QIcon::Normal, QIcon::Off);
        actionPreferences->setIcon(icon5);
        actionConsole = new QAction(WndMain);
        actionConsole->setObjectName(QString::fromUtf8("actionConsole"));
        actionConsole->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/res/konsole.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConsole->setIcon(icon6);
        actionActionProjectExplorer = new QAction(WndMain);
        actionActionProjectExplorer->setObjectName(QString::fromUtf8("actionActionProjectExplorer"));
        actionActionProjectExplorer->setCheckable(true);
        actionAbout = new QAction(WndMain);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/ico_info"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon7);
        actionOpenProject = new QAction(WndMain);
        actionOpenProject->setObjectName(QString::fromUtf8("actionOpenProject"));
        actionOpenProject->setIcon(icon);
        actionRun = new QAction(WndMain);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/run_and_debug/res/run.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon8);
        actionActionStep = new QAction(WndMain);
        actionActionStep->setObjectName(QString::fromUtf8("actionActionStep"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/run_and_debug/res/debug-step-into.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionActionStep->setIcon(icon9);
        actionActionStepOver = new QAction(WndMain);
        actionActionStepOver->setObjectName(QString::fromUtf8("actionActionStepOver"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/run_and_debug/res/debug-step-over.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionActionStepOver->setIcon(icon10);
        actionActionStepOut = new QAction(WndMain);
        actionActionStepOut->setObjectName(QString::fromUtf8("actionActionStepOut"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/run_and_debug/res/debug-step-out.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionActionStepOut->setIcon(icon11);
        actionStop = new QAction(WndMain);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/run_and_debug/res/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon12);
        centralWidget = new QWidget(WndMain);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frmMain = new QFrame(centralWidget);
        frmMain->setObjectName(QString::fromUtf8("frmMain"));
        frmMain->setFrameShape(QFrame::StyledPanel);
        frmMain->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frmMain);

        WndMain->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WndMain);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuRecentFiles = new QMenu(menuFile);
        menuRecentFiles->setObjectName(QString::fromUtf8("menuRecentFiles"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        WndMain->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WndMain);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setEnabled(true);
        mainToolBar->setStyleSheet(QString::fromUtf8(""));
        mainToolBar->setIconSize(QSize(48, 48));
        WndMain->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpenProject);
        menuFile->addAction(actionOpenFile);
        menuFile->addAction(actionNew);
        menuFile->addAction(menuRecentFiles->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuSettings->addAction(actionPreferences);
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionOpenFile);
        mainToolBar->addAction(actionPreferences);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionConsole);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRun);
        mainToolBar->addAction(actionActionStep);
        mainToolBar->addAction(actionActionStepOver);
        mainToolBar->addAction(actionActionStepOut);
        mainToolBar->addAction(actionStop);

        retranslateUi(WndMain);

        QMetaObject::connectSlotsByName(WndMain);
    } // setupUi

    void retranslateUi(QMainWindow *WndMain)
    {
        WndMain->setWindowTitle(QApplication::translate("WndMain", "Instant Lua", 0, QApplication::UnicodeUTF8));
        actionOpenFile->setText(QApplication::translate("WndMain", "Open File", 0, QApplication::UnicodeUTF8));
        actionOpenFile->setShortcut(QApplication::translate("WndMain", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("WndMain", "New", 0, QApplication::UnicodeUTF8));
        actionNew->setShortcut(QApplication::translate("WndMain", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("WndMain", "Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("WndMain", "Save current file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave->setShortcut(QApplication::translate("WndMain", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionSave_as->setText(QApplication::translate("WndMain", "Save as", 0, QApplication::UnicodeUTF8));
        actionSave_as->setShortcut(QApplication::translate("WndMain", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("WndMain", "Quit", 0, QApplication::UnicodeUTF8));
        actionQuit->setShortcut(QApplication::translate("WndMain", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionPreferences->setText(QApplication::translate("WndMain", "Preferences", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPreferences->setToolTip(QApplication::translate("WndMain", "Change the source code editor configuration", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionConsole->setText(QApplication::translate("WndMain", "View console", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionConsole->setToolTip(QApplication::translate("WndMain", "Shows or hides the console frame", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionConsole->setShortcut(QApplication::translate("WndMain", "Ctrl+1", 0, QApplication::UnicodeUTF8));
        actionActionProjectExplorer->setText(QApplication::translate("WndMain", "View Project explorer", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionActionProjectExplorer->setToolTip(QApplication::translate("WndMain", "Show or hides the project explorer", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionActionProjectExplorer->setShortcut(QApplication::translate("WndMain", "Ctrl+2", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("WndMain", "About", 0, QApplication::UnicodeUTF8));
        actionOpenProject->setText(QApplication::translate("WndMain", "Open Project", 0, QApplication::UnicodeUTF8));
        actionRun->setText(QApplication::translate("WndMain", "actionRun", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRun->setToolTip(QApplication::translate("WndMain", "Run", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionActionStep->setText(QApplication::translate("WndMain", "actionStep", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionActionStep->setToolTip(QApplication::translate("WndMain", "Step", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionActionStepOver->setText(QApplication::translate("WndMain", "actionStepOver", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionActionStepOver->setToolTip(QApplication::translate("WndMain", "Step Over", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionActionStepOut->setText(QApplication::translate("WndMain", "actionStepOut", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionActionStepOut->setToolTip(QApplication::translate("WndMain", "Step Out", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionStop->setText(QApplication::translate("WndMain", "Stop", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionStop->setToolTip(QApplication::translate("WndMain", "Stop Execution", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        menuFile->setTitle(QApplication::translate("WndMain", "File", 0, QApplication::UnicodeUTF8));
        menuRecentFiles->setTitle(QApplication::translate("WndMain", "Recent Files", 0, QApplication::UnicodeUTF8));
        menuSettings->setTitle(QApplication::translate("WndMain", "Settings", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("WndMain", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WndMain: public Ui_WndMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WNDMAIN_H
