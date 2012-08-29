#include "FrmProjectExplorer.h"
#include "ui_FrmProjectExplorer.h"

//--- Qt lib framework ----------------------------------------------------------------------------
#include <QVector>
#include <QRegExp>
#include <QDebug>

//--- Luanda framework ----------------------------------------------------------------------------
#include "IFile.h"
#include "Exceptions.h"
#include "Prototypes.h"

//-------------------------------------------------------------------------------------------------
FrmProjectExplorer::FrmProjectExplorer(QWidget *parent)
    :QWidget(parent)
    ,ui(new Ui::FrmProjectExplorer)
    ,m_dirProjects()
{
    ui->setupUi(this);
}

//-------------------------------------------------------------------------------------------------
FrmProjectExplorer::~FrmProjectExplorer()
{
    delete ui;
}

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::setProjectPath(QString sNewPath)
{
    m_dirProjects.setPath(sNewPath);
}

//-------------------------------------------------------------------------------------------------
const QDir& FrmProjectExplorer::getProjectPath() const
{
    return m_dirProjects;
}

//-------------------------------------------------------------------------------------------------
//
// ISettingsProvider interface
//
//-------------------------------------------------------------------------------------------------

void FrmProjectExplorer::writeSettings(QSettings &settings)
{
    settings.beginGroup("Paths");
    settings.setValue("projects", m_dirProjects.absolutePath());
    settings.endGroup();
}

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::readSettings(QSettings &settings)
{
    settings.beginGroup("Paths");
    m_dirProjects.setPath(settings.value("projects", "").toString());
    settings.endGroup();
}

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::updateFromSettings()
{}

//-------------------------------------------------------------------------------------------------
//
// IFileobserver interface
//
//-------------------------------------------------------------------------------------------------

/** \brief Aktualisieren der Outline Ansicht.
*/
void FrmProjectExplorer::notifyFileActivate(const IFile *pFile)
{
    try
    {
        updateOutline(pFile);
    }
    catch(std::exception exc)
    {
    }
    catch(...)
    {
    }
}

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::notifyFileLoad(const IFile *pFile)
{}

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::notifyBeforeFileSave(IFile *pFile)
{}

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::notifyFileModified(const IFile *pFile)
{}

//-------------------------------------------------------------------------------------------------
//
// sonstiges
//
//-------------------------------------------------------------------------------------------------

void FrmProjectExplorer::updateOutline(const IFile *pFile)
{
    ui->tvOutline->clear();
    ui->tvOutline->setRootIsDecorated(true);
    m_pScriptOutline.clear();

    if (pFile==NULL)
        return;

    QTreeWidgetItem* itHeader = new QTreeWidgetItem();
    itHeader->setText(0, QString("Function overview (") + pFile->getName() + ")");
    ui->tvOutline->setHeaderItem(itHeader);

    // Heraussuchen von Funktionsdefinitionen
    const QVector<QString> &vLines = pFile->getLines();
    if (vLines.size()==0)
        return;

    QRegExp regex = QRegExp("function \\s*([^\\(]*)\\(([^)]*)\\)(.*)",
                            Qt::CaseSensitive,
                            QRegExp::RegExp);
    if (!regex.isValid())
        throw InternalError("Can't create outline: Invalid regular expression.");

    m_pScriptOutline = QSharedPointer<ScriptOutline>(new ScriptOutline(pFile->getName()));

    // Heraussuchen der Funktionsdefinitionen
    for (int i=0; i<vLines.size(); ++i)
    {
        QString sLine = vLines[i];
        bool bStat = regex.exactMatch(sLine);
        if (!bStat)
           continue;

        int nCount = regex.captureCount();
        if (nCount<3)
            continue;

        // Die Zeile enthält eine gültige Funktionsdefinition
        QString sMatch   = regex.cap(0);
        QString sFunName = regex.cap(1);
        QString sFunArgs = regex.cap(2);
        m_pScriptOutline->addFunction(sFunName, sFunArgs);
        qDebug() << "function " << sFunName << "(" << sFunArgs << ")";
    }

    QTreeWidgetItem *pOutline = m_pScriptOutline->toTreeItem();
    ui->tvOutline->invisibleRootItem()->addChild(pOutline);
    ui->tvOutline->expandAll();
}
