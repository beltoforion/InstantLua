#ifndef FRMPROJECTVIEW_H
#define FRMPROJECTVIEW_H

//--- Qtlib includes ------------------------------------------------------------------------------
#include <QWidget>
#include <QDropEvent>

//--- luanda framework ----------------------------------------------------------------------------
#include "IFile.h"
#include "ISettingsProvider.h"
#include "Types.h"


namespace Ui {
    class FrmFileExplorer;
}

//-------------------------------------------------------------------------------------------------
class FrmFileExplorer : public QWidget,
                        public ISettingsProvider,
                        public IFileObserver
{
    Q_OBJECT

public:
    explicit FrmFileExplorer(QWidget *parent, IFileObserver *pProjectExplorer);
    ~FrmFileExplorer();

    void addFile(IFile::ptr_type pFile);
    void saveAll(bool bModifiedOnly);

    void dropEvent(QDropEvent *evt);
    void dragEnterEvent(QDragEnterEvent *event);
    void setCursorInfo(int nLine, int nIndex);

    IFile* getActiveFile() const;

    // ISettingsprovider
    virtual void writeSettings(QSettings &settings);
    virtual void readSettings(QSettings &settings);
    virtual void updateFromSettings();

    // IFileObserver
    virtual void notifyFileActivate(const IFile *pFile);
    virtual void notifyFileLoad(const IFile *pFile);
    virtual void notifyBeforeFileSave(IFile *pFile);
    virtual void notifyFileModified(const IFile *pFile);
    virtual void notifyFileLineSelected(const IFile *pFile, int nLine, ETextMarker eMarker);


private:
    Ui::FrmFileExplorer *ui;
    IFileObserver *m_pProjectExplorer;

    IFile* findFile(const QString &sPath);

    int getTabIndex(const IFile *pFile);
    FrmSourceEdit* getSourceEdit(const IFile *pFile);

signals:
    void checkFile(const IFile *pFile);

private slots:
    void on_actionClose_All_But_This_triggered();
    void on_actionClose_triggered();
    void on_tcProject_tabCloseRequested(int index);
    void on_tcProject_currentChanged(QWidget *arg1);
};

#endif // FRMPROJECTVIEW_H
