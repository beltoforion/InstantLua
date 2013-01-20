#include "DlgNewFile.h"
#include "ui_DlgNewFile.h"

#include <QFileDialog>


//-------------------------------------------------------------------------------------------------
DlgNewFile::DlgNewFile(QWidget *parent, const Settings &settings)
    :QDialog(parent)
    ,ui(new Ui::DlgNewFile)
    ,m_settings(settings)
{
    ui->setupUi(this);

    Qt::WindowFlags flags;
    flags  = Qt::Tool;
    flags |= Qt::WindowStaysOnTopHint;
    setWindowFlags(flags);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    ui->edProjectDir->setText(m_settings.getProjectPath());
}

//-------------------------------------------------------------------------------------------------
DlgNewFile::~DlgNewFile()
{
    delete ui;
}

//-------------------------------------------------------------------------------------------------
void DlgNewFile::on_btnProjectDir_clicked()
{
    QString sPath = QFileDialog::getExistingDirectory(this,
                                                      tr("Select an alternate project directory"),
                                                      m_settings.getProjectPath(),
                                                      QFileDialog::ShowDirsOnly);
    ui->edProjectDir->setText(sPath);
}

//-------------------------------------------------------------------------------------------------
void DlgNewFile::on_edFileName_textChanged(const QString &sFileName)
{
    m_sFullName = ui->edProjectDir->text() + ui->edFileName->text();
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(sFileName.length()!=0);

    m_fi.setFile(QDir(ui->edProjectDir->text()), sFileName);

    if (sFileName.length()==0)
    {
        ui->lbHint->setText("Please input a filename");
    }
    else
    {
        //ui->lbHint->setText(m_sFullName);
        ui->lbHint->setText(m_fi.absoluteFilePath());
    }
}
