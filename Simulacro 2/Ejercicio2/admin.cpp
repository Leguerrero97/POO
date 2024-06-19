#include "admin.h"
#include <QDebug>

Admin::Admin(QObject *parent) : QObject(parent)
{
    db = new AdminDB(this);
    if (!db->conectar("C:/Users/Lautaro/Documents/Qt/Simulacro 2/Ejercicio2/base_poo.sqlite")) {
        qDebug() << "No se pudo conectar a la base de datos";
        return;
    }

    loginWindow = new Login();
    connect(loginWindow, &Login::signal_usuarioValidado, this, &Admin::onUsuarioValidado);
    loginWindow->show();
}

Admin::~Admin()
{
    delete loginWindow;
    delete mainWindow;
    delete db;
}

void Admin::onUsuarioValidado(QString usuario)
{
    qDebug() << "Usuario validado:" << usuario;
    loginWindow->close();

    mainWindow = new Ventana();
    mainWindow->show();
}
