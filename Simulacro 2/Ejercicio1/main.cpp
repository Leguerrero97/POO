#include "principal.h"
#include <QApplication>
#include <QDebug>
#include <qdir.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << QDir::currentPath();

    if (AdminDB::instance().conectar("path/to/rectangles.sqlite")) {
        qDebug() << "Conexion exitosa";
    } else {
        qDebug() << "Conexion NO exitosa";
    }

    Principal w;
    w.show();

    return a.exec();
}
