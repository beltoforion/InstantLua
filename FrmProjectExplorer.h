#ifndef FRMPROJECTEXPLORER_H
#define FRMPROJECTEXPLORER_H

//--- Qt lib framework ----------------------------------------------------------------------------
#include <QWidget>
#include <QDir>

//--- Luanda framework ----------------------------------------------------------------------------
#include "IFileObserver.h"
#include "ISettingsProvider.h"


namespace Ui {
    class FrmProjectExplorer;
}

//-------------------------------------------------------------------------------------------------
class FrmProjectExplorer : public QWidget
                         , public ISettingsProvider
                         , public IFileObserver
{
    Q_OBJECT

public:
    explicit FrmProjectExplorer(QWidget *parent = 0);
    ~FrmProjectExplorer();

    const QDir& getProjectPath() const;
    void setProjectPath(QString sNewPath);

    // ISettingsProvider
    virtual void writeSettings(QSettings &settings);
    virtual void readSettings(QSettings &settings);
    virtual void updateFromSettings();

    // IFileObserver
    virtual void notifyFileActivate(const IFile *pFile);
    virtual void notifyFileLoad(const IFile *pFile);
    virtual void notifyBeforeFileSave(IFile *pFile);
    virtual void notifyFileModified(const IFile *pFile);

private:
    Ui::FrmProjectExplorer *ui;
    QDir m_dirProjects;

    void updateOutline(const IFile *pFile);
};

#endif // FRMPROJECTEXPLORER_H
