#include "WndMain.h"
#include "ui_WndMain.h"

#include <iostream>

//--- QTlib includes ------------------------------------------------------------------------------
#include <QSplitter.h>
#include <QSettings>
#include <QFileDialog>

//-------------------------------------------------------------------------------------------------
#include "Settings.h"
#include "FileLua.h"
#include "DlgSettings.h"
#include "ProjectLua.h"


//-------------------------------------------------------------------------------------------------
WndMain::WndMain(QWidget *parent)
    :QMainWindow(parent)
    ,ISettingsProvider()
    ,ui(new Ui::WndMain)
    ,m_pFrmExplorer(NULL)
    ,m_pFrmFileExplorer(NULL)
    ,m_pFrmInfo(NULL)
    ,m_pFrmConsole(NULL)
    ,m_pDlgSettings(NULL)
    ,m_projects()
    ,m_pspLeft(NULL)
    ,m_pspMain(NULL)
    ,m_thLua(new QLuaThread(this))
    ,m_pConsoleStreamBuf(NULL)
{
    ui->setupUi(this);


    // Explorer Fenster anlegen, die Reihenfolge ist wichtig, da gegenseitige Abhängigkeiten
    // bestehen!
    m_pFrmExplorer = new FrmProjectExplorer(this);
    m_pFrmExplorer->setMaximumWidth(300);

    m_pFrmFileExplorer = new FrmFileExplorer(this, m_pFrmExplorer);

    // Weitere Frames und Dialoge
    m_pFrmInfo = new FrmInfo(this);
    m_pFrmConsole = new FrmConsole(this);
    m_pDlgSettings = new DlgSettings(this);
    m_pDlgAbout = new DlgAbout(this);

    // Konsole einrichten
//    m_pFrmConsole->bindToInterpreter(&m_lua);

    //m_pFrmConsole->SetPrompt("Luanda");

    // Linkes Splitterfenster
    m_pspLeft = new QSplitter(Qt::Vertical, this);
    m_pspLeft->addWidget(m_pFrmFileExplorer);
    m_pspLeft->addWidget(m_pFrmConsole);

    // Splitter einrichten
    m_pspMain = new QSplitter(Qt::Horizontal, this);
    m_pspMain->addWidget(m_pFrmExplorer);
    m_pspMain->addWidget(m_pspLeft);

    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->addWidget(m_pspMain);
    vbox->setMargin(0);
    ui->frmMain->setLayout(vbox);

    createRecentFileMenus();

    // Einlesen der Settings (letzter Schritt!)
    Settings &s = Settings::Instance();
    s.addProvider(this);
    s.addProvider(m_pFrmFileExplorer);
    s.addProvider(m_pFrmExplorer);
    s.addProvider(m_pFrmConsole);
    s.addProvider(m_pDlgSettings);
    s.readSettings();

    // Umleiten der Standardausgabe in die Konsole, speichern des Originalstreams
    m_pConsoleStreamBuf  = new console_streambuf(m_pFrmConsole->getIConsole());
    m_pOriginalStreamBuf = std::cout.rdbuf(m_pConsoleStreamBuf);

    // Starten des Lua threads
    m_thLua->start();
    m_thLua->bindToConsole(m_pFrmConsole->getIConsole());

    connect(m_thLua, SIGNAL(luaSyntaxCheckDone()), this, SLOT(on_lua_syntaxCheckDone()));
    connect(m_thLua, SIGNAL(luaExecutionFinished()), this, SLOT(on_lua_executionFinished()));
    connect(m_thLua, SIGNAL(luaFunctionCall()), this, SLOT(on_lua_functionCall()));

    // Kommandoeingabe in der Konsole direkt zur Ausführung an den Lua Thread weiter geben
    connect(m_pFrmConsole->getConsole(), SIGNAL(commandInput(const QString&)),
            m_thLua, SLOT(on_doString(const QString&)));

    connect(this, SIGNAL(doFile(const IFile*)), m_thLua, SLOT(on_doFile(const IFile*)));

}

//-------------------------------------------------------------------------------------------------
WndMain::~WndMain()
{
    delete ui;
    delete m_pConsoleStreamBuf;

    // Restore original cout stream buffer
    std::cout.rdbuf(m_pOriginalStreamBuf);
}

//-------------------------------------------------------------------------------------------------
void WndMain::createRecentFileMenus()
{
    for (int i = 0; i < MaxRecentFiles; ++i)
    {
        m_recentFileActs[i] = new QAction(this);
        m_recentFileActs[i]->setVisible(false);
        connect(m_recentFileActs[i],
                SIGNAL(triggered()),
                this,
                SLOT(openRecentFile()));
    }


    for (int i = 0; i < MaxRecentFiles; ++i)
        ui->menuRecentFiles->addAction(m_recentFileActs[i]);
}


//-------------------------------------------------------------------------------------------------
void WndMain::resizeEvent(QResizeEvent *)
{
    if (m_pFrmInfo->isVisible())
        m_pFrmInfo->center();
}

//-------------------------------------------------------------------------------------------------
/** \brief Opens a new Lua File in the editor.
*/
void WndMain::on_actionOpenFile_triggered()
{
    QString sFile = QFileDialog::getOpenFileName(this,
                                                tr("Select File of project to open"),
                                                m_pFrmExplorer->getProjectPath().absolutePath(),
                                                tr("LUA Files (*.lua *.lpf)"));

    if (sFile.length()>0)
    {
        openFile(sFile);
    }
}

//-------------------------------------------------------------------------------------------------
/** \brief Öffnen eines Projektverzeichnisses.
*/
void WndMain::on_actionOpenProject_triggered()
{
    // Es gibt drei Möglichkeiten für das Projektöffnen
    // 1.) Angeben eines Verzeichnisses, Wenn im Verzeichnis ein Projektfile liegt, wird dieses geladen
    // 2.) Anwählen eines Projektfiles
    Settings &settings = Settings::Instance();
    QString sPath = QFileDialog::getExistingDirectory(this,
                                                      tr("Select the project directory"),
                                                      settings.getProjectPath(),
                                                      QFileDialog::ShowDirsOnly);
    if (!sPath.isEmpty())
    {
        QSharedPointer<ProjectLua> pProject(new ProjectLua(sPath));
    }
}

//-------------------------------------------------------------------------------------------------
/** \brief Opens a new file in the editor. */
void WndMain::openFile(QString sFile)
{
    if (sFile.isNull() || sFile.isEmpty())
        return;

    IFile::ptr_type pFile = FileLua::Create(sFile);
    m_pFrmFileExplorer->addFile(pFile);
    pFile->load();

    // update recent file list
    m_recentFiles.removeAll(sFile);
    m_recentFiles.prepend(sFile);

    while (m_recentFiles.size() > MaxRecentFiles)
        m_recentFiles.removeLast();

    updateRecentFileActions();
}

//-------------------------------------------------------------------------------------------------
/** \brief Speichert all offenen Dateien ab, die als geändert markiert sind. */
void WndMain::on_actionSave_triggered()
{
    m_pFrmInfo->setTitle("Saving files");
    m_pFrmInfo->setSubTitle("please wait...");
    m_pFrmInfo->show(2000);
    m_pFrmFileExplorer->saveAll(true);
}

//-------------------------------------------------------------------------------------------------
/** \brief Quit the application.
*/
void WndMain::on_actionQuit_triggered()
{
    Settings::Instance().writeSettings();
    QApplication::exit(0);
}

//-------------------------------------------------------------------------------------------------
/** \brief Open the settings window. */
void WndMain::on_actionPreferences_triggered()
{
    m_pDlgSettings->exec();
}

//-------------------------------------------------------------------------------------------------
void WndMain::on_actionAbout_triggered()
{
    m_pDlgAbout->exec();
}

//-------------------------------------------------------------------------------------------------
void WndMain::readSettings(QSettings &settings)
{
    settings.beginGroup("MainWindow");

    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();

    QByteArray state;
    state = settings.value("state", QByteArray()).toByteArray();
    restoreState(state);

    state = settings.value("splitter_main", QByteArray()).toByteArray();
    m_pspMain->restoreState(state);

    state = settings.value("splitter_left", QByteArray()).toByteArray();
    m_pspLeft->restoreState(state);

    resize(size);
    move(pos);

    m_recentFiles = settings.value("recent_file_list").toStringList();

    m_pFrmConsole->setVisible(settings.value("console_visibility", true).toBool());
    m_pFrmExplorer->setVisible(settings.value("project_explorer_visibility", true).toBool());

    settings.endGroup();
}

//-------------------------------------------------------------------------------------------------
void WndMain::writeSettings(QSettings &settings)
{
    settings.beginGroup("MainWindow");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
    settings.setValue("state", saveState());
    settings.setValue("splitter_main", m_pspMain->saveState());
    settings.setValue("splitter_left", m_pspLeft->saveState());
    settings.setValue("console_visibility", m_pFrmConsole->isVisible());
    settings.setValue("project_explorer_visibility", m_pFrmExplorer->isVisible());
    settings.setValue("recent_file_list", m_recentFiles);
    settings.endGroup();
}

//-------------------------------------------------------------------------------------------------
/** \brief Aktualisieren des Hauptfensters nach einlesen bzw. Ändern der Programmeinstellungen.

  Aktualisiert die recent File Liste.
*/
void WndMain::updateFromSettings()
{
    updateRecentFileActions();
}

//-------------------------------------------------------------------------------------------------
/** \brief Anzeigen bzw. Verstecken des Konsolenframes.
  */
void WndMain::on_actionConsole_triggered()
{
    if (m_pFrmConsole->isVisible())
        m_pFrmConsole->hide();
    else
        m_pFrmConsole->show();
}

//-------------------------------------------------------------------------------------------------
/** \brief Lua Thread ist fertif mit einem Syntaxcheck. */
void WndMain::on_lua_syntaxCheckDone()
{

}
//-------------------------------------------------------------------------------------------------
void WndMain::on_lua_executionFinished()
{}

//-------------------------------------------------------------------------------------------------
void WndMain::on_lua_functionCall()
{}

//-------------------------------------------------------------------------------------------------
void WndMain::openRecentFile()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
    {
        QString sFile = action->data().toString();
        openFile(sFile);
    }
}

//-------------------------------------------------------------------------------------------------
void WndMain::updateRecentFileActions()
{
    int nRecentFiles = qMin(m_recentFiles.size(), (int)MaxRecentFiles);
    for (int i = 0; i < nRecentFiles; ++i)
    {
// Nur Dateiname:
//        QString text = tr("&%1 %2").arg(i + 1).arg(QFileInfo(m_recentFiles[i]).fileName());
// Dateiname + Pfad:
        QString text = tr("&%1 %2").arg(i + 1).arg(QFileInfo(m_recentFiles[i]).filePath());
        m_recentFileActs[i]->setText(text);
        m_recentFileActs[i]->setData(m_recentFiles[i]);
        m_recentFileActs[i]->setVisible(true);
    }

    for (int j = nRecentFiles; j < MaxRecentFiles; ++j)
        m_recentFileActs[j]->setVisible(false);
}

//-------------------------------------------------------------------------------------------------
void WndMain::on_actionRun_triggered()
{
    if (m_thLua==NULL)
        return;

    // Aktives File heraussuchen
    const IFile *pFile = m_pFrmFileExplorer->getActiveFile();
    if (pFile!=NULL)
    {
        emit doFile(pFile);
    }
}
