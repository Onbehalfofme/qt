#include "mainwdgt.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QMessageBox>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWdgt w;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", "db");
    db.setHostName("localhost");
    db.setPort(5432);
    db.setDatabaseName("flightdb");
    db.setUserName("postgres");
    db.setPassword("postgres");
    if(!db.open()){
    QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
        QObject::tr("Unable to establish a database connection.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
    w.show();

    return a.exec();
}
