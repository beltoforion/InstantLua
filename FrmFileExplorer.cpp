#include "FrmFileExplorer.h"
#include "ui_FrmFileExplorer.h"

//--- Standard includes ---------------------------------------------------------------------------
#include <cassert>

//--- Qt lib includes -----------------------------------------------------------------------------
#include <Qlist>
#include <QUrl>
#include <QFileInfo>
#include <QDebug>

//--- Luanda framework ----------------------------------------------------------------------------
#include "FrmSourceEdit.h"
#include "FileLua.h"
#include "Settings.h"
#include "QFileExplorerTabBar.h"

//-------------------------------------------------------------------------------------------------
FrmFileExplorer::FrmFileExplorer(QWidget *parent, IFileObserver *pProjectExplorer)
    :QWidget(parent)
    ,ui(new Ui::FrmFileExplorer)
    ,m_pProjectExplorer(pProjectExplorer)
{
    assert(m_pProjectExplorer!=NULL);

    ui->setupUi(this);
    ui->paCaption->setCaption("Source Code");
    ui->paCaption->setIcon(QPixmap(":/images/res/tab-duplicate-3.png"));

    setAcceptDrops(true);
}

//-------------------------------------------------------------------------------------------------
FrmFileExplorer::~FrmFileExplorer()
{
    delete ui;
}

//-------------------------------------------------------------------------------------------------
/** \brief Sucht zu einer Datei den passenden Tabsheet index raus.
    \return Index des Tabsheets oder -1 wenn die Datei nicht gefunden wurde.
  */
int FrmFileExplorer::getTabIndex(const IFile *pFile)
{
    for (int i=0; i<ui->tcProject->count(); ++i)
    {
      FrmSourceEdit *pEdit = static_cast<FrmSourceEdit*>(ui->tcProject->widget(i));
      if (pEdit->getFile().data()==pFile)
      {
          return i;
      }
    }

    return -1;
}

//-------------------------------------------------------------------------------------------------
FrmSourceEdit*  FrmFileExplorer::getSourceEdit(const IFile *pFile)
{
    for (int i=0; i<ui->tcProject->count(); ++i)
    {
      FrmSourceEdit *pEdit = static_cast<FrmSourceEdit*>(ui->tcProject->widget(i));
      if (pEdit->getFile().data()==pFile)
      {
          return pEdit;
      }
    }

    return NULL;
}

//-------------------------------------------------------------------------------------------------
/** \brief Zur�ckgeben des Zeigers auf das File, dessen Tabsheet derzeit der Aktive ist. */
IFile* FrmFileExplorer::getActiveFile() const
{
    FrmSourceEdit *pEdit = dynamic_cast<FrmSourceEdit*>(ui->tcProject->currentWidget());
    if (pEdit!=NULL)
        return pEdit->getFile().data();
    else
        return NULL;
}

//-------------------------------------------------------------------------------------------------
/** \brief Abspeichern aller offenen Dateien.
    \param bModifiedOnly Wenn dieses Flag gesetzt ist werden nur die Modifizierten Dateien
           gespeichert

*/
void FrmFileExplorer::saveAll(bool bModifiedOnly)
{
    for (int i=0; i<ui->tcProject->count(); ++i)
    {
        FrmSourceEdit *pEdit = static_cast<FrmSourceEdit*>(ui->tcProject->widget(i));
        IFile::ptr_type pFile = pEdit->getFile();
        if ( (!bModifiedOnly) || (bModifiedOnly && pFile->wasModified()))
        {
            pFile->save();
        }
    }
}

//-------------------------------------------------------------------------------------------------
void FrmFileExplorer::notifyFileActivate(const IFile *pFile)
{
    int i = getTabIndex(pFile);
    if (i>=0)
    {
        ui->tcProject->setCurrentIndex(i);
        ui->paCaption->setInfo(1, QString("File: %1    ").arg(pFile->path()));
    }
}

//-------------------------------------------------------------------------------------------------
void FrmFileExplorer::notifyFileLoad(const IFile *pFile)
{
    int i = getTabIndex(pFile);
    if (i>=0)
    {
        ui->tcProject->setTabIcon(i, QIcon(":/images/res/ok.ico"));
    }
}

//-------------------------------------------------------------------------------------------------
void FrmFileExplorer::notifyBeforeFileSave(IFile *pFile)
{
    // Entfernen der "unsaved" Markierung
    int i = getTabIndex(pFile);
    if (i>=0)
    {
        ui->tcProject->setTabIcon(i, QIcon(":/images/res/ok.ico"));
    }
}

//-------------------------------------------------------------------------------------------------
/** \brief Ausw�hlen des Tabsheets mit dem Lua Files. */
void FrmFileExplorer::notifyFileModified(const IFile *pFile)
{
    if (pFile==NULL)
        return;

    int i = getTabIndex(pFile);
    if (i<0)
        return;

    ui->tcProject->setTabIcon(i, QIcon(":/images/res/warning.ico"));
    emit checkFile(pFile);
}

//-------------------------------------------------------------------------------------------------
void FrmFileExplorer::notifyFileLineSelected(const IFile *pFile, int nLine, ETextMarker eMarker)
{
    // Tabsheet mit dem File raussuchen und Zeile markieren
    int i = getTabIndex(pFile);
    if (i>=0)
    {
        ui->tcProject->setCurrentIndex(i);
    }

    qDebug() << "FrmFileExplorer::notifyFileLineSelected:" << QString::number(nLine) << "\n";
}

//-------------------------------------------------------------------------------------------------
/** \brief Sucht zu einem gegebenen Pfad die passende Datei des Explorers.
*/
IFile* FrmFileExplorer::findFile(const QString &sPath)
{
    for (int i=0; i<ui->tcProject->count(); ++i)
    {
      FrmSourceEdit *pEdit = static_cast<FrmSourceEdit*>(ui->tcProject->widget(i));
      IFile::ptr_type pFile = pEdit->getFile();
      if (pFile->path()==sPath)
      {
          return pFile.data();
      }
    }

    return NULL;
}

//-------------------------------------------------------------------------------------------------
/** \brief Hinzuf�gen einer Datei zum File explorer.
    \param pFile Zeiger auf die hinzuzuf�gende Datei.

  Wenn die Datei bereits exisitiert wird die Datei neu geladen, ihr Tabsheet rausgesucht
  und zum aktiven Tabsheet gemacht.
*/
void FrmFileExplorer::addFile(IFile::ptr_type pFile)
{

    // rausfinden, ob es bereits ein File mit der gleichen Pfadangabe gibt, wenn
    // ja wird kein neuer reiter angelegt, sondern das "alte" file neu geladen.
    IFile *ptr = findFile(pFile->path());
    if (ptr)
    {
        ptr->load();
        ptr->activate();
    }
    else
    {
        FrmSourceEdit *pSrcEdit = new FrmSourceEdit(this, pFile);
        pSrcEdit->updateFromSettings();

        // Hinzuf�gen der File observer
        pFile->attachObserver(pSrcEdit);
        pFile->attachObserver(m_pProjectExplorer);
        pFile->attachObserver(this);

        int idx = ui->tcProject->addTab(pSrcEdit, pFile->getName());
        ui->tcProject->setTabToolTip(idx, pFile->path());
        ui->tcProject->setTabIcon(idx, QIcon(":/images/res/file_ok.ico"));

        // Sicher stellen, das der Tabsheet des neuen Files angezeigt wird
        pFile->activate();
    }
}

//-------------------------------------------------------------------------------------------------
void FrmFileExplorer::updateFromSettings()
{
    for (int i=0; i<ui->tcProject->count(); ++i)
    {
        FrmSourceEdit *pSrcEdit = static_cast<FrmSourceEdit*>(ui->tcProject->widget(i));
        pSrcEdit->updateFromSettings();
    }
}

//-------------------------------------------------------------------------------------------------
void FrmFileExplorer::writeSettings(QSettings &settings)
{
    settings.beginGroup("OpenFiles");

    settings.setValue("num", ui->tcProject->count());
    for (int i=0; i<ui->tcProject->count(); ++i)
    {
        FrmSourceEdit *pEdit = static_cast<FrmSourceEdit*>(ui->tcProject->widget(i));
        IFile::ptr_type pFile = pEdit->getFile();
        settings.setValue(QString("file") + QString::number(i), pFile->path());
    }
    settings.endGroup();
}

//-------------------------------------------------------------------------------------------------
void FrmFileExplorer::readSettings(QSettings &settings)
{
    settings.beginGroup("OpenFiles");

    int num = settings.value("num", 0).toInt();
    for (int i=0; i<num; ++i)
    {
        QString sKey = QString("file") + QString::number(i);
        QString sFile = settings.value(sKey, "").toString();

        IFile::ptr_type pFile = FileLua::Create(sFile);
        addFile(pFile);
        pFile->load();
    }

    settings.endGroup();
}


//-------------------------------------------------------------------------------------------------
/** \brief Close a single file tabsheet and delete its widget. */
void FrmFileExplorer::on_tcProject_tabCloseRequested(int idx)
{
    QWidget *pPage = ui->tcProject->widget(idx);
    ui->tcProject->removeTab(idx);
    delete pPage;
}

//-------------------------------------------------------------------------------------------------
void FrmFileExplorer::dropEvent(QDropEvent *evt)
{
    QList<QUrl> urls = evt->mimeData()->urls();
    if (urls.isEmpty())
        return;

    QString fileName = urls.first().toLocalFile();
    if (fileName.isEmpty())
        return;

    QFileInfo info(fileName);
    QString sExt = info.suffix();
    if (sExt!="lua")
        return;

    IFile::ptr_type pFile = FileLua::Create(fileName);
    addFile(pFile);
    pFile->load();
    pFile->activate();
}

//-------------------------------------------------------------------------------------------------
void FrmFileExplorer::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/uri-list"))
    {
        QList<QUrl> urls = event->mimeData()->urls();
        if (urls.isEmpty())
            return;

        QString fileName = urls.first().toLocalFile();
        if (fileName.isEmpty())
            return;

        QFileInfo info(fileName);
        QString sExt = info.suffix();
        if (sExt!="lua")
            return;

        event->acceptProposedAction();
    }
}

//-------------------------------------------------------------------------------------------------
void FrmFileExplorer::on_actionClose_triggered()
{}

//-------------------------------------------------------------------------------------------------
void FrmFileExplorer::on_actionClose_All_But_This_triggered()
{}

//-------------------------------------------------------------------------------------------------
/** \brief Reaktion auf wechsel des aktiven Tabsheets.

    Wenn der aktive Tabsheet wechselt m�ssen die File observer dar�ber
    informiert werden. Dadurch wird dann auch der Projektexplorer
    angepasst.
*/
void FrmFileExplorer::on_tcProject_currentChanged(QWidget *tabPage)
{
    FrmSourceEdit *pEdit = dynamic_cast<FrmSourceEdit*>(tabPage);
    if (pEdit==NULL)
        return;

    IFile::ptr_type pFile = pEdit->getFile();
    if (!pFile.isNull())
        pFile->activate();
}

//-------------------------------------------------------------------------------------------------
void FrmFileExplorer::setCursorInfo(int nLine, int nIndex)
{
    ui->paCaption->setInfo(0, tr("Line: %1, Column: %2  ").arg(nLine).arg(nIndex));
}

