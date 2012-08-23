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

private:
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
#endif
