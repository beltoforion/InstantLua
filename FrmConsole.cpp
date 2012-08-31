#include "FrmConsole.h"
#include "ui_FrmConsole.h"

#include "Settings.h"


//-------------------------------------------------------------------------------------------------
FrmConsole::FrmConsole(QWidget *parent)
    :QWidget(parent)
    ,ui(new Ui::FrmConsole)
{
    ui->setupUi(this);

    ui->edConsole->setPrompt("Lua", ">");
    ui->paCaption->setCaption("Console");
    splashScreen();
}

//-------------------------------------------------------------------------------------------------
FrmConsole::~FrmConsole()
{
    delete ui;
}

//-------------------------------------------------------------------------------------------------
void FrmConsole::splashScreen()
{
    ui->edConsole->addLine(" _____           _              _     _                  ");
    ui->edConsole->addLine("|_   _|         | |            | |   | |                 ");
    ui->edConsole->addLine("  | |  _ __  ___| |_ __ _ _ __ | |_  | |    _   _  __ _  ");
    ui->edConsole->addLine("  | | | '_ \\/ __| __/ _` | '_ \\| __| | |   | | | |/ _` |");
    ui->edConsole->addLine(" _| |_| | | \\__ \\ || (_| | | | | |_  | |___| |_| | (_| |");
    ui->edConsole->addLine("|_____|_| |_|___/\\__\\__,_|_| |_|\\__| |______\\__,_|\\__,_|");
    ui->edConsole->addLine(" (C) 2012 Ingo Berg                         Version 0.0");
    ui->edConsole->addLine("");
    ui->edConsole->addLine("             http://beltoforion.de/instant_lua");
    ui->edConsole->addLine("");
    ui->edConsole->addLine("Running with Lua V5.2");
    ui->edConsole->addLine("");
}


//-------------------------------------------------------------------------------------------------
void FrmConsole::AddLine(const QString &sLine, ELineOptions eOptions)
{
    ui->edConsole->appendPlainText(sLine);
}

//-------------------------------------------------------------------------------------------------
void FrmConsole::writeSettings(QSettings &settings)
{}

//-------------------------------------------------------------------------------------------------
void FrmConsole::readSettings(QSettings &settings)
{}

//-------------------------------------------------------------------------------------------------
void FrmConsole::updateFromSettings()
{
    const Settings &settings = Settings::Instance();
    ui->edConsole->setFontSize(settings.getFontSize());
}


