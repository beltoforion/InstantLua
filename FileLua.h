#ifndef FILELUA_H
#define FILELUA_H

//--- QTLib includes ------------------------------------------------------------------------------
#include <QVector>
#include <QString>
#include <QFileInfo>

//--- Luanda framework ----------------------------------------------------------------------------
#include "IFile.h"
#include "IProject.h"


//-------------------------------------------------------------------------------------------------
/** \brief Eine Klasse, die eine einzelnes Lua File repräsentiert.
*/
class FileLua : public IFile
{
public:

    static IFile::ptr_type Create(const QString &sPath);

    virtual ~FileLua();


    // IFile implementation
    virtual std::size_t getNumLines() const;
    virtual void clear();
    virtual void addLine(const QString &sLine);
    virtual const QVector<QString>& getLines() const;

    virtual QString getName() const;
    virtual IProject* getProject();
    virtual const QFileInfo* getFileInfo() const;

    virtual const QString& getLine(std::size_t i) const;
    virtual QString path() const;

protected:
    virtual void loadImpl();
    virtual void saveImpl();

private:

    FileLua(const QString &sPath);

    QVector<QString> m_vLines;
    QFileInfo m_fi;
};

#endif // FILELUA_H
