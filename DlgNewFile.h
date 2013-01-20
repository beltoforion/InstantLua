#ifndef DLGNEWFILE_H
#define DLGNEWFILE_H

#include <QDialog>
#include <QFileInfo>
#include "Settings.h"


namespace Ui {
class DlgNewFile;
}

class DlgNewFile : public QDialog
{
    Q_OBJECT
    
public:
    explicit DlgNewFile(QWidget *parent, const Settings &settings);
    ~DlgNewFile();
    
private slots:
    void on_btnProjectDir_clicked();

    void on_edFileName_textChanged(const QString &arg1);

private:
    Ui::DlgNewFile *ui;
    const Settings &m_settings;
    QString m_sFullName;
    QFileInfo m_fi;
};

#endif // DLGNEWFILE_H
