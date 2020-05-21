#include "mainwdgt.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWdgt w;
    w.show();

    return a.exec();
}
