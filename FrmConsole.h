#ifndef FRMCONSOLE_H
#define FRMCONSOLE_H

#include <QWidget>
#include <QVector>

#include "ISettingsProvider.h"


namespace Ui {
    class FrmConsole;
}

class FrmConsole : public QWidget,
                   public ISettingsProvider
{
    Q_OBJECT

public:

    enum ELineOptions
    {
        loNORMAL,
        loWITHOUT_PROMPT
    };

    explicit FrmConsole(QWidget *parent = 0);
    ~FrmConsole();

    void AddLine(const QString &sLine, ELineOptions eOptions);

    // ISettingsProvider
    virtual void writeSettings(QSettings &settings);
    virtual void readSettings(QSettings &settings);
    virtual void updateFromSettings();

private:
    Ui::FrmConsole *ui;

    void splashScreen();
};

#endif // FRMDEBUG_H
