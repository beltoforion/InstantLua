#include "DlgAbout.h"
#include "ui_DlgAbout.h"

DlgAbout::DlgAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgAbout)
{
    ui->setupUi(this);
}

DlgAbout::~DlgAbout()
{
    delete ui;
}
