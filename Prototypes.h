#ifndef PROTOTYPES_H
#define PROTOTYPES_H

//--- At lib includes -----------------------------------------------------------------------------
#include <QString>
#include <QVector>
#include <QTreeWidgetItem>

//-------------------------------------------------------------------------------------------------
class LanguageToken //: public QTreeWidgetItem
{
public:
    LanguageToken(const QString &sName);

    virtual ~LanguageToken();

    const QString& getName() const;

    void setLine(int nLine);
    int getLine() const;

    const QVector<LanguageToken*>& getChilds() const;

    void setParent(LanguageToken *pToken);
    LanguageToken* getParent();

    void addFunction(const QString &sName, const QString &sArg, int nLine);
    QTreeWidgetItem* toTreeItem() ;

protected:

    QVector<LanguageToken*> m_vChilds;
    QString m_sName;
    QIcon m_icon;
    LanguageToken *m_pParent;
    int m_nLine;

    void add(LanguageToken *pItem);
    void remove(LanguageToken *pItem);
    LanguageToken* find(const QString &sName);
};


//-------------------------------------------------------------------------------------------------
class ScriptOutline : public LanguageToken
{
public:
    ScriptOutline(const QString &sName);
};


//-------------------------------------------------------------------------------------------------
class ClassDefinition : public LanguageToken
{
public:
    ClassDefinition(const QString &sName,
                    const QString &sRest,
                    const QString &sArg,
                    int nLine);
};


//-------------------------------------------------------------------------------------------------
class FunctionDefinition : public LanguageToken
{
public:
    FunctionDefinition(const QString &sName,
                       const QString &sArgs,
                       int nLine);

    QString m_sArgs;
};

#endif // PROTOTYPES_H
