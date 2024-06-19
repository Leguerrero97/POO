#include "manager.h"
#include "login.h"
#include "ventana.h"

Manager::Manager(QObject *parent) : QObject(parent) {
    loginWidget = std::unique_ptr<Login>(new Login());
    connect(loginWidget.get(), &Login::signal_usuarioValidado, this, &Manager::mostrarVentana);

    ventanaWidget = std::unique_ptr<Ventana>(new Ventana());
    connect(ventanaWidget.get(), &Ventana::signal_volverLogin, this, &Manager::mostrarLogin);

    mostrarLogin(); // Mostrar el Login al inicio
}

Manager::~Manager() {
    // Los unique_ptr se encargarán de liberar la memoria de los widgets
}

void Manager::mostrarLogin() {
    ventanaWidget->hide();
    loginWidget->show();
}

void Manager::mostrarVentana(const QString &usuario) {
    loginWidget->hide();
    ventanaWidget->show();

    // Aquí puedes pasar datos a Ventana si es necesario
    // ventanaWidget->setUsuario(usuario);
}

void Manager::volverLogin() {
    ventanaWidget->hide();
    loginWidget->show();
}

