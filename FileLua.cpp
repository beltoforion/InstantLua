#include "FileLua.h"

//--- Standard includes ---------------------------------------------------------------------------
#include <stdexcept>

//--- QTlib includes ------------------------------------------------------------------------------
#include <QTextStream>
#include <QFile>
#include <QString>


//-------------------------------------------------------------------------------------------------
IFile::ptr_type FileLua::Create(const QString &sPath)
{
    return IFile::ptr_type(new FileLua(sPath));
}

//-------------------------------------------------------------------------------------------------
FileLua::FileLua(const QString &path)
    :m_vLines()
    ,m_fi(path)
{}

//-------------------------------------------------------------------------------------------------
FileLua::~FileLua()
{}

//-------------------------------------------------------------------------------------------------
QString FileLua::path() const
{
    return m_fi.absoluteFilePath();
}

//-------------------------------------------------------------------------------------------------
QString FileLua::getName() const
{
    return m_fi.fileName();
}

//-------------------------------------------------------------------------------------------------
std::size_t FileLua::getNumLines() const
{
    return m_vLines.size();
}

//-------------------------------------------------------------------------------------------------
/** \brief Löscht den zwischengepufferten Dateiinhalt.

*/
void FileLua::clear()
{
    m_vLines.clear();
}

//-------------------------------------------------------------------------------------------------
void FileLua::addLine(const QString &sLine)
{
    m_vLines.push_back(sLine);
}

//-------------------------------------------------------------------------------------------------
const QString& FileLua::getLine(std::size_t i) const
{
    return m_vLines.at(i);
}

//-------------------------------------------------------------------------------------------------
const QVector<QString>& FileLua::getLines() const
{
    return m_vLines;
}

//-------------------------------------------------------------------------------------------------
IProject* FileLua::getProject()
{
    return NULL;
}

//-------------------------------------------------------------------------------------------------
const QFileInfo* FileLua::getFileInfo() const
{
    return &m_fi;
}

//-------------------------------------------------------------------------------------------------
void FileLua::loadImpl()
{
    m_vLines.clear();

    QFile file( m_fi.filePath());
    if ( file.open( QIODevice::ReadOnly | QIODevice::Text) )
    {
        QTextStream stream( &file );
        while ( !stream.atEnd() )
        {
            m_vLines.push_back(stream.readLine());
        }
        file.close();
    }
}

//-------------------------------------------------------------------------------------------------
/** \brief Abspeichern der Datei. */
void FileLua::saveImpl()
{
    QFile file( m_fi.filePath());
    if ( !file.open( QIODevice::WriteOnly | QIODevice::Text ) )
        throw std::runtime_error("Can't save file");

    QTextStream stream( &file );
    for (int i=0; i<m_vLines.size(); ++i)
    {
        stream << m_vLines[i];
    }
    file.close();
}
