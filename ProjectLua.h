#ifndef PROJECTLUA_H
#define PROJECTLUA_H

//-------------------------------------------------------------------------------------------------
#include <QVector>
#include <QDir>
//#include <QtXml/QDomDocument>

//-------------------------------------------------------------------------------------------------
#include "IProject.h"
#include "FwdDecl.h"

//-------------------------------------------------------------------------------------------------
/** \brief Encapsulation of a lua project. */
class ProjectLua : public IProject
{
public:
    ProjectLua(const QString &sName);
    virtual ~ProjectLua();

    void importFromDirectory(QDir initialDir);
    void loadFromFile(const QString &sFileName);

    // IProject implementation
    virtual void AddFile(const string_type &sFileName);
    virtual void DeleteFile(const string_type &sFileName);
    virtual void Open(const string_type &sProject);
    virtual string_type GetName() const;

private:
    QString m_sProjectFile;
    QVector<FileLua*> m_vFiles;
//    QDomDocument m_xmlDoc;          ///< Projektfile als xml

    void scanDir(QDir dir);
};

#endif // PROJECTLUA_H
