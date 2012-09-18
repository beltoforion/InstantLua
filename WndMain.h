#ifndef WND_MAIN_H
#define WND_MAIN_H

//--- Standard includes ---------------------------------------------------------------------------
#include <vector>

//--- Qtlib includes ------------------------------------------------------------------------------
#include <QMainWindow>
#include <QSplitter>
#include <QSettings>
#include <Qsci/qsciscintilla.h>

//--- Luanda includes -----------------------------------------------------------------------------
#include "IProject.h"
#include "IMainFrame.h"
#include "ISettingsProvider.h"
#include "FrmProjectExplorer.h"
#include "FrmFileExplorer.h"
#include "FrmConsole.h"
#include "FrmInfo.h"
#include "DlgSettings.h"
#include "DlgAbout.h"
#include "QConsoleStreamBuffer.h"
#include "QLuaThread.h"

//--- Lua bindings --------------------------------------------------------------------------------
#include "luabind/LuaContext.h"


namespace Ui {
    class WndMain;
}

//-------------------------------------------------------------------------------------------------
class WndMain : public QMainWindow,
                public ISettingsProvider,
                public IMainFrame
{
    Q_OBJECT

public:
    explicit WndMain(QWidget *parent = 0);
    ~WndMain();

    //---------------------------------------------------------------------------------------------
    // IMainFrame implementierung
    //---------------------------------------------------------------------------------------------

    virtual QWidget* asWidget();
    virtual IScriptEngine* getScriptEngine();
    virtual IFileObserver* getProjectExplorer();
    virtual IConsole* getConsole();

private:
    Ui::WndMain *ui;
    FrmProjectExplorer *m_pFrmExplorer;
    FrmFileExplorer *m_pFrmFileExplorer;
    FrmInfo *m_pFrmInfo;
    FrmConsole *m_pFrmConsole;
    DlgSettings *m_pDlgSettings;
    DlgAbout *m_pDlgAbout;

    std::vector<IProject*> m_projects;
    QSplitter *m_pspLeft;
    QSplitter *m_pspMain;

    QLuaThread *m_thLua;

    enum { MaxRecentFiles = 5 };
    QAction *m_recentFileActs[MaxRecentFiles];
    QMenu *m_menuRecentFiles;
    QStringList m_recentFiles;

    void resizeEvent(QResizeEvent *);
    void createRecentFileMenus();
    void updateRecentFileActions();
    void openFile(QString sFile);

    // ISettingsProvide
    virtual void writeSettings(QSettings &settings);
    virtual void readSettings(QSettings &settings);
    virtual void updateFromSettings();

signals:
    void doFile(IFile *pFile);


private slots:
    void openRecentFile();

    void on_lua_functionCall();
    void on_lua_scriptError(const LuaException &exc);

    void on_actionConsole_triggered();
    void on_actionPreferences_triggered();
    void on_actionQuit_triggered();
    void on_actionSave_triggered();
    void on_actionAbout_triggered();
    void on_actionOpenProject_triggered();
    void on_actionOpenFile_triggered();
    void on_actionRun_triggered();


private:
    std::streambuf *m_pConsoleStreamBuf;
    std::streambuf *m_pOriginalStreamBuf;
};

#endif // WND_MAIN_H
