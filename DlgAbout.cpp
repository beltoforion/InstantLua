#include "DlgAbout.h"
#include "ui_DlgAbout.h"


//-------------------------------------------------------------------------------------------------
DlgAbout::DlgAbout(QWidget *parent)
    :QDialog(parent)
    ,ui(new Ui::DlgAbout)
{
    ui->setupUi(this);

    Qt::WindowFlags flags;
    flags  = Qt::Tool;
    flags |= Qt::WindowCloseButtonHint;
    flags |= Qt::WindowStaysOnTopHint;

    setWindowFlags(flags);
}

//-------------------------------------------------------------------------------------------------
DlgAbout::~DlgAbout()
{
    delete ui;
}
