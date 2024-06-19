#include "widget.h"
#include <QApplication>
#include "adminDB.h"
#include<QtDebug>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << QDir::currentPath();

    AdminDB adminDB;
    if (adminDB.conectar( "C:/Users/Lautaro/Documents/Qt/Simulacro 2/EjercicioA/dbA.sqlite3" ) )
        qDebug() << "Conexion exitosa";
    else
        qDebug() << "Conexion NO exitosa";

    Widget w;
    w.show();
    return a.exec();
}
