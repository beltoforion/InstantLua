#include <QtGui/QApplication>
#include "WndMain.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName("beltoforion");
    a.setOrganizationDomain("beltoforion.de");
    a.setApplicationName("luanda");

    WndMain w;
    w.show();

    return a.exec();
}
