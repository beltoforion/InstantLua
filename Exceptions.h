#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <QString>

//-------------------------------------------------------------------------------------------------
class Exception : public std::exception
{
public:
    Exception(QString sMsg);
    virtual ~Exception() throw();

    const QString& getMessage() const throw();

    // std::exception implementation
    virtual const char* what() const throw();

protected:
    void setMessage(const QString &sMsg);

protected:
    QString m_sMsg;
};


//-------------------------------------------------------------------------------------------------
struct FileIOException : Exception
{
    FileIOException(QString sMsg);
    virtual ~FileIOException() throw();
};

//-------------------------------------------------------------------------------------------------
struct InternalError : Exception
{
    InternalError(QString sMsg);
    virtual ~InternalError() throw();
};

//-------------------------------------------------------------------------------------------------
struct LuaException : Exception
{
    LuaException(QString sMsg);
    virtual ~LuaException() throw();

    int getLine() const;
    const QString& getModule() const;

private:
    QString m_sModule;
    int m_nLine;
};

#endif
