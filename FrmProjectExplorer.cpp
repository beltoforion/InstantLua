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
    ,m_pScriptOutline()
    ,m_pActiveFile(NULL)
{
    ui->setupUi(this);

    initOutline();
}

//-------------------------------------------------------------------------------------------------
FrmProjectExplorer::~FrmProjectExplorer()
{
    delete ui;
}

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::initOutline()
{
    QTreeWidgetItem* itHeader = new QTreeWidgetItem();
    itHeader->setText(0, "Function overview");
    itHeader->setTextAlignment(0, Qt::AlignCenter);
    itHeader->setText(1, "Line");
    itHeader->setTextAlignment(1, Qt::AlignCenter);
    ui->tvOutline->setHeaderItem(itHeader);

    ui->tvOutline->header()->setStretchLastSection(false);
    ui->tvOutline->header()->setResizeMode(0, QHeaderView::Stretch);
    ui->tvOutline->header()->setResizeMode(1, QHeaderView::ResizeToContents);
    ui->tvOutline->setAlternatingRowColors(true);
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
        m_pActiveFile = pFile;
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
void FrmProjectExplorer::notifyFileLineSelected(const IFile *pFile, int nLine)
{}

//-------------------------------------------------------------------------------------------------
//
// sonstiges
//
//-------------------------------------------------------------------------------------------------

/*
void FrmProjectExplorer::resizeEvent(QResizeEvent* event)
{
    if (event!=NULL)
    {
        QWidget::resizeEvent(event);
    }

    int nTreeWidth = ui->tvOutline->width();
    ui->tvOutline->header()->resizeSection(0, nTreeWidth*0.7);
    ui->tvOutline->header()->resizeSection(1, nTreeWidth*0.3);
    ui->tvOutline->header()->setResizeMode(0, );
}
*/

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::updateOutline(const IFile *pFile)
{
    ui->tvOutline->clear();
    m_pScriptOutline.clear();

    if (pFile==NULL)
        return;

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
        m_pScriptOutline->addFunction(sFunName, sFunArgs, i);
        qDebug() << "function " << sFunName << "(" << sFunArgs << ")";
    }

    QTreeWidgetItem *pOutline = m_pScriptOutline->toTreeItem();
    ui->tvOutline->invisibleRootItem()->addChild(pOutline);
    ui->tvOutline->expandAll();
}

//-------------------------------------------------------------------------------------------------
void FrmProjectExplorer::on_tvOutline_itemSelectionChanged()
{
    if (m_pActiveFile==NULL)
        return;

    QList<QTreeWidgetItem *> items = ui->tvOutline->selectedItems();
    if (items.size()>0)
    {
        QVariant data = items[0]->data(1, Qt::DisplayRole);
        if (data.isValid())
        {
            m_pActiveFile->navigateToLine(data.toInt());
        }
    }
}
