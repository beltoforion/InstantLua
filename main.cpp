#include <QtGui/QApplication>
#include <QMessageBox>
#include <QSplashScreen>
#include "WndMain.h"
#include "Exceptions.h"


#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>

#include <WndCanvas.h>


int main(int argc, char *argv[])
{
    try
    {
        QApplication a(argc, argv);
        a.setOrganizationName("beltoforion");
        a.setOrganizationDomain("beltoforion.de");
        a.setApplicationName("InstantLua");
        a.setApplicationVersion(APP_VERSION);

        QSplashScreen *splash = new QSplashScreen;
        splash->setPixmap(QPixmap(":/images/res/splash.png"));
        splash->show();

        WndMain w;
        QTimer::singleShot(2500, splash, SLOT(close()));
        QTimer::singleShot(2500, &w, SLOT(show()));

        return a.exec();
    }
    catch(Exception &exc)
    {
        QMessageBox msgBox;
        msgBox.setText(exc.getMessage());
        msgBox.exec();
    }
    catch(std::exception &exc)
    {
        QMessageBox msgBox;
        msgBox.setText(exc.what());
        msgBox.exec();
    }
    catch(...)
    {
        QMessageBox msgBox;
        msgBox.setText("Program aborted due to an unexpected exception");
        msgBox.exec();
    }

    return -1;
}
