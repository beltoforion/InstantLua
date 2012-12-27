#include "FrmSourceEdit.h"

#include <QVBoxLayout>
#include <QTextStream>
#include <QSettings>
#include <QList>
#include <QUrl>
#include <Qsci/qscilexerlua.h>
#include <QDebug>

//--- InstandLuaX Framework -----------------------------------------------------------------------
#include "Settings.h"
#include "Locker.h"

//-------------------------------------------------------------------------------------------------
FrmSourceEdit::FrmSourceEdit(FrmFileExplorer *pParent, IFile::ptr_type pFile)
    :QWidget(pParent)
    ,m_pSrcEdit(NULL)
    ,m_pFile(pFile)
    ,m_pFileExplorer(pParent)
    ,m_nMarkerBreakPoint(0)
    ,m_nMarkerCIP(0)
    ,m_nMarkerLine(0)
    ,m_nMarkerError(0)
    ,m_vMarkedLines()
    ,m_nErrorLine(-1)
    ,m_nNumberIndicator(0)
{
    try
    {
        m_pSrcEdit = new QsciScintilla(this);

        connect(m_pSrcEdit, SIGNAL(textChanged()), this, SLOT(textChanged()));

        connect(m_pSrcEdit, SIGNAL(modificationChanged(bool)), this, SLOT(fileModified(bool)));

        connect(m_pSrcEdit, SIGNAL(linesChanged()), this, SLOT(linesChanged()));

        connect(m_pSrcEdit, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(cursorMoved(int,int)));

        connect(m_pSrcEdit, SIGNAL(indicatorClicked(int, int, Qt::KeyboardModifiers)), this, SLOT(indicatorClicked(int, int,Qt::KeyboardModifiers)));

        connect(m_pSrcEdit, SIGNAL(marginClicked(int, int, Qt::KeyboardModifiers)), this, SLOT(marginClicked(int, int,Qt::KeyboardModifiers)));

/*
        //! This signal is emitted whenever text is selected or de-selected.
        //! \a yes is true if text has been selected and false if text has been
        //! deselected.  If \a yes is true then copy() can be used to copy the
        //! selection to the clipboard.  If \a yes is false then copy() does
        //! nothing.
        //!
        //! \sa copy(), selectionChanged()
        void copyAvailable(bool yes);

        //! This signal is emitted whenever the user clicks on an indicator.  \a
        //! line is the number of the line where the user clicked.  \a index is the
        //! character index within the line.  \a state is the state of the modifier
        //! keys (Qt::ShiftModifier, Qt::ControlModifier, Qt::AltModifer and
        //! Qt::MetaModifier) when the user clicked.
        //!
        //! \sa indicatorReleased()
        void indicatorClicked(int line, int index, Qt::KeyboardModifiers state);

        //! This signal is emitted whenever the user releases the mouse on an
        //! indicator.  \a line is the number of the line where the user clicked.
        //! \a index is the character index within the line.  \a state is the state
        //! of the modifier keys (Qt::ShiftModifier, Qt::ControlModifier,
        //! Qt::AltModifer and Qt::MetaModifier) when the user released the mouse.
        //!
        //! \sa indicatorClicked()
        void indicatorReleased(int line, int index, Qt::KeyboardModifiers state);

        //! This signal is emitted whenever the number of lines of text changes.
        void linesChanged();

        //! This signal is emitted whenever the user clicks on a sensitive margin.
        //! \a margin is the margin.  \a line is the number of the line where the
        //! user clicked.  \a state is the state of the modifier keys
        //! (Qt::ShiftModifier, Qt::ControlModifier, Qt::AltModifer and
        //! Qt::MetaModifier) when the user clicked.
        //!
        //! \sa marginSensitivity(), setMarginSensitivity()
        void marginClicked(int margin, int line, Qt::KeyboardModifiers state);

        //! This signal is emitted whenever the user attempts to modify read-only
        //! text.
        //!
        //! \sa isReadOnly(), setReadOnly()
        void modificationAttempted();

        //! This signal is emitted whenever the modification state of the text
        //! changes.  \a m is true if the text has been modified.
        //!
        //! \sa isModified(), setModified()
        void modificationChanged(bool m);

        //! This signal is emitted whenever the selection changes.
        //!
        //! \sa copyAvailable()
        void selectionChanged();

        //! This signal is emitted whenever the text in the text edit changes.
        void textChanged();

        //! This signal is emitted when an item in a user defined list is activated
        //! (selected).  \a id is the list identifier.  \a string is the text of
        //! the item.
        //!
        //! \sa showUserList()
        void userListActivated(int id, const QString &string);
*/


        // Lexer konfigurieren
        QsciLexerLua *pLexer = new QsciLexerLua;
        pLexer->setFont(QFont("Courier New", 10));

        m_pSrcEdit->setLexer(pLexer);
        m_pSrcEdit->setFolding(QsciScintilla::BoxedTreeFoldStyle, 2 /* margin */);

        // Margins
        m_pSrcEdit->setMarginWidth(0, 40);
        m_pSrcEdit->setMarginType(0, QsciScintilla::NumberMargin);
        m_pSrcEdit->setMarginLineNumbers(0, true);

        m_pSrcEdit->setMarginWidth(1, 40);
        m_pSrcEdit->setMarginType(1, QsciScintilla::SymbolMargin /*DefaultBackgroundColor*/);
        m_pSrcEdit->setMarginSensitivity(1, true);  // marginClick Signale freischalten

        // Auto complete
        m_pSrcEdit->setAutoCompletionThreshold(2);
        m_pSrcEdit->setAutoCompletionCaseSensitivity(true);
        m_pSrcEdit->setAutoCompletionSource(QsciScintilla::AcsAll);

        // misc
        m_pSrcEdit->setBraceMatching(QsciScintilla::StrictBraceMatch);
        m_pSrcEdit->setAcceptDrops(true);

        // Markieren für überlange Zeilen
        // ab 80 Spalten ist eine Zeile als zu lang zu markieren. Die GUI
        // ist darauf ausgelegt Debugpanel einzublenden, daher sollte die
        // Ideale Zeilenbreite angezeigt werden. Wenn der Nutzer
        // drüberschreibt ist er selber schuld
        m_pSrcEdit->setEdgeColumn(80);
        m_pSrcEdit->setEdgeMode(QsciScintilla::EdgeLine);

        // Marker definieren (Haltepunkte und Instruktionpointer)
        m_nMarkerBreakPoint = m_pSrcEdit->markerDefine(QsciScintilla::Circle);
        m_pSrcEdit->setMarkerForegroundColor(QColor("black"), m_nMarkerBreakPoint);
        m_pSrcEdit->setMarkerBackgroundColor(QColor("red"),   m_nMarkerBreakPoint);

        m_nMarkerCIP = m_pSrcEdit->markerDefine(QsciScintilla::RightArrow);
        m_pSrcEdit->setMarkerForegroundColor(QColor("black"), m_nMarkerCIP);
        m_pSrcEdit->setMarkerBackgroundColor(QColor("green"), m_nMarkerCIP);

        m_nMarkerLine = m_pSrcEdit->markerDefine(QsciScintilla::Background);
        m_pSrcEdit->setMarkerBackgroundColor(QColor(180, 255, 180), m_nMarkerLine);

//        m_nMarkerError = m_pSrcEdit->markerDefine(QsciScintilla::Background);
        m_nMarkerError = m_pSrcEdit->markerDefine(QsciScintilla::Underline);
        m_pSrcEdit->setMarkerBackgroundColor(QColor(255, 180, 180), m_nMarkerError);

        // Indikatoren
        m_nNumberIndicator = m_pSrcEdit->indicatorDefine(QsciScintilla::StrikeIndicator /*RoundBoxIndicator*/);

        QVBoxLayout *vbox = new QVBoxLayout(this);
        vbox->addWidget(m_pSrcEdit);
        vbox->setMargin(0);
        setLayout(vbox);
    }
    catch(...)
    {
        // no problem, editor remains empty. Constructor may not fail!
    }
}

//-------------------------------------------------------------------------------------------------
FrmSourceEdit::~FrmSourceEdit()
{}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::fileModified(bool bStat)
{
    updateFile(true);
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::textChanged()
{
    updateFile(true);

    // Stellenweise hat fileModified nicht mehr getriggert, Grund unbekannt...
    // textChanged sollte immer triggern
    qDebug() << "textChanged()";
}

//-------------------------------------------------------------------------------------------------
/** \brief Synchronisiert den Inhalt der Scintilla Komponente mit dem zwischengepufferten Inhalt
           in m_pFile.

    Das Modified flag von m_pFile wird gesetzt.
*/
void FrmSourceEdit::updateFile(bool bSetModifiedFlag)
{
    if (m_pFile==NULL)
        return;

    int nLines = m_pSrcEdit->lines();

    Locker lock(m_pFile.data());

    m_pFile->clear();

    qDebug() << "clearing buffered content of file " << m_pFile->getName();
    for (int i=0; i<nLines; ++i)
    {
        m_pFile->addLine(m_pSrcEdit->text(i));
    }
    qDebug() << "content of file " << m_pFile->getName() << "updated";

    if (bSetModifiedFlag)
    {
        m_pFile->setModified(true);
    }
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::linesChanged()
{
    // todo: outline aktualisieren
    qDebug() << "linesChanged()";
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::marginClicked(int nMargin, int nLine, Qt::KeyboardModifiers eState)
{
    if (nMargin==1)
    {
        m_pSrcEdit->fillIndicatorRange(1, 10, 0, 0, m_nNumberIndicator);

        // Schon Haltepunkt gesetzt?
        int nMarkers = m_pSrcEdit->markersAtLine(nLine);
        if ((nMarkers & 1)!=0)
        {
            m_pSrcEdit->markerDelete(nLine, m_nMarkerBreakPoint);
        }
        else
        {
            m_pSrcEdit->markerAdd(nLine, m_nMarkerBreakPoint);
        }

        qDebug() << "marginClicked(" << nMargin << "," << nLine << ", " << eState << ")";
    }
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::cursorMoved(int nLine, int nIndex)
{
    m_pFileExplorer->setCursorInfo(nLine, nIndex);
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::indicatorClicked(int nLine, int nIndex, Qt::KeyboardModifiers state)
{
    qDebug() << "indicatorClicked(" << nLine << "," << nIndex << ", " << state << ")";
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::notifyFileModified(const IFile *pFile)
{
    // Diese Komponente löst den Event aus, der Inhalt von pFile
    // wurde bereite in updateFile aktualisiert.
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::notifyFileActivate(const IFile *pFile)
{
    deleteMarker(tmHIGHLIGHT);
}

//-------------------------------------------------------------------------------------------------
/** \brief Aktualisieren des angezeigten Dateiinhaltes. */
void FrmSourceEdit::notifyFileLoad(const IFile *pFile)
{
    std::size_t sz = pFile->getNumLines();
    QString sFile;
    for (std::size_t i=0; i<sz; ++i)
    {
        sFile += pFile->getLine(i) + "\n";
    }
    m_pSrcEdit->setText(sFile);
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::notifyBeforeFileSave(IFile *pFile)
{}

//-------------------------------------------------------------------------------------------------
/** \brief Markieren einer bestimmten Zeile.
    \param pFile File in dem die Zeile markiert werden soll
    \param nLine Zeilenindex (einsbasiert)
*/
void FrmSourceEdit::notifyFileLineSelected(const IFile *pFile, int nLine, ETextMarker eMarker)
{
    deleteMarker(tmHIGHLIGHT);

    qDebug() << "FrmSourceEdit::notifyFileLineSelected:" << QString::number(nLine) << "\n";

    int nLineIdx = nLine - 1;
    if (nLineIdx<0)
        return;

    switch(eMarker)
    {
    case tmHIGHLIGHT:
        // es können mehrere Zeilen hervorgehoben sein
        m_pSrcEdit->markerAdd(nLineIdx, m_nMarkerLine);
        m_vMarkedLines.push_back(nLineIdx);
        break;

    case tmERROR:
        // Alte Fehlermarkierung löschen
        if (m_nErrorLine!=-1)
        {
            // Es scheint ein Redrawproblem zu geben, wenn der
            // cursor nicht in der Zeile steht
            m_pSrcEdit->setCursorPosition(m_nErrorLine, 0);
            m_pSrcEdit->markerDelete(m_nErrorLine, m_nMarkerError);
        }

        // Es kann nur eine Zeile als Fehler markiert sein
        m_pSrcEdit->markerAdd(nLineIdx, m_nMarkerError);
        m_nErrorLine = nLineIdx;
        break;

    case tmBREAKPOINT:
    default:
        break;
    }

    m_pSrcEdit->setCursorPosition(nLineIdx, 0);
    m_pSrcEdit->ensureCursorVisible();
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::deleteMarker(ETextMarker eMarker)
{
    int flags = (int)eMarker;

    // Errormarker entfernen
    if ( (flags & tmERROR) != 0)
    {
        if (m_nErrorLine!=-1)
        {
            m_pSrcEdit->markerDelete(m_nErrorLine, m_nMarkerError);
        }
    }

    // Highlights entfernen
    if ( (flags & tmHIGHLIGHT) != 0)
    {
        for (int i=0; i<m_vMarkedLines.size(); ++i)
        {
            m_pSrcEdit->markerDelete(m_vMarkedLines[i], m_nMarkerLine);
        }
        m_vMarkedLines.clear();
    }

    //m_pSrcEdit->up->update();
}

//-------------------------------------------------------------------------------------------------
void FrmSourceEdit::mousePressEvent(QMouseEvent * event)
{
    qDebug() << "mousePressEvent";
    QWidget::mousePressEvent(event);
}

//-------------------------------------------------------------------------------------------------
IFile::ptr_type FrmSourceEdit::getFile()
{
    return m_pFile;
}

//-------------------------------------------------------------------------------------------------
/** \brief Aktualisieren der Konfiguration des controls gemäß der globalen Einstellungen.
*/
void FrmSourceEdit::updateFromSettings()
{
    const Settings &settings = Settings::Instance();
    m_pSrcEdit->setMarginWidth(0, (settings.hasLineNumbers()) ? 40 :0);
    m_pSrcEdit->setFolding( (settings.hasSourceFolding()) ? QsciScintilla::BoxedTreeFoldStyle
                                                          :  QsciScintilla::NoFoldStyle, 2);

    m_pSrcEdit->lexer()->setFont(QFont("Courier New", settings.getFontSize()));
    m_pSrcEdit->setTabWidth(settings.getTabIndent());
}



