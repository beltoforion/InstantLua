#ifndef FRMSOURCEEDIT_H
#define FRMSOURCEEDIT_H

//--- QTLib includes ------------------------------------------------------------------------------
#include <QFileInfo>
#include <Qsci/qsciscintilla.h>

//--- luanda includes -----------------------------------------------------------------------------
#include "IFile.h"
#include "IFileObserver.h"
#include "FrmFileExplorer.h"

//-------------------------------------------------------------------------------------------------
class FrmSourceEdit : public QWidget,
                      public IFileObserver
{
    Q_OBJECT

public:

    FrmSourceEdit(FrmFileExplorer *pParent, IFile::ptr_type pFile);
   ~FrmSourceEdit();

    // IFileObserver
    virtual void notifyFileActivate(const IFile *pFile);
    virtual void notifyFileModified(const IFile *pFile);
    virtual void notifyFileLoad(const IFile *pFile);
    virtual void notifyBeforeFileSave(IFile *pFile);
    virtual void notifyFileLineSelected(const IFile *pFile, int nLine);

    // von Widget reimplementiert
    virtual void mousePressEvent(QMouseEvent * event);

    // eigene Funktionen
    IFile::ptr_type getFile();
    void updateFileBuffer();
    void updateFromSettings();
//    void markLine(int nLine);

private slots:

    // für QScintilla
    void fileModified(bool bStat);
    void linesChanged();
    void cursorMoved(int,int);
    void indicatorClicked(int, int, Qt::KeyboardModifiers);
    void marginClicked(int margin, int line, Qt::KeyboardModifiers state);
    void textChanged();

    // andere
    void tabCloseRequest(int);
    void tabChange(int);

private:
    QsciScintilla *m_pSrcEdit;
    IFile::ptr_type m_pFile;
    FrmFileExplorer *m_pFileExplorer;

    // Marker
    int m_nMarkerBreakPoint;
    int m_nMarkerCIP;
    int m_nMarkerLine;

    QVector<int> m_vMarkedLines;

    // Indikatoren
    int m_nNumberIndicator;

    void clearMarkedLines();
};

#endif // FRMSOURCEEDIT_H
