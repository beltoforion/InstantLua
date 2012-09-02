#include <QtGui/QApplication>
#include <QMessageBox>
#include "WndMain.h"
#include "Exceptions.h"


int main(int argc, char *argv[])
{
    try
    {
        QApplication a(argc, argv);
        a.setOrganizationName("beltoforion");
        a.setOrganizationDomain("beltoforion.de");
        a.setApplicationName("luanda");

        WndMain w;
        w.show();
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
