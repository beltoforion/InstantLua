#include "FrmConsole.h"
#include "ui_FrmConsole.h"

#include "Settings.h"
#include "Exceptions.h"
#include "IInterpreter.h"


//-------------------------------------------------------------------------------------------------
FrmConsole::FrmConsole(QWidget *parent)
    :QWidget(parent)
    ,ui(new Ui::FrmConsole)
    ,m_pLua(NULL)
{
    ui->setupUi(this);

    ui->edConsole->setPrompt("Lua", ">");
    ui->paCaption->setCaption("Console");
    ui->paCaption->setColorScheme(QGradientPanel::csBLUE);

    connect(ui->edConsole, SIGNAL(commandInput(QString)), this, SLOT(executeCommand(QString)));
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
void FrmConsole::bindToInterpreter(IInterpreter *pInterpreter)
{
    m_pLua = pInterpreter;
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

//-------------------------------------------------------------------------------------------------
void FrmConsole::executeCommand(const QString &sCmd)
{
    try
    {
        if (m_pLua==NULL)
        {
            ui->edConsole->addLine(QString("Can't execute: %1 because no interpreter is bound to the console").arg(sCmd));
        }
        else
        {
            m_pLua->execute(sCmd);
        }
    }
    catch(Exception &exc)
    {
        ui->edConsole->addLine(exc.getMessage());
    }
    catch(std::exception &exc)
    {
        ui->edConsole->addLine(exc.what());
    }
    catch(...)
    {
        ui->edConsole->addLine("Internal error: FrmConsole::executeCommand");
    }
}


