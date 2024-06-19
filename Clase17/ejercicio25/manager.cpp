#include "manager.h"
#include <QDebug>

Manager::Manager() {
    db = AdminDB::getInstancia();

    loginWindow = new Login(this);
    registroWindow = new RegistroUsuario(this);
    visualizacionWindow = new VisualizacionUsuarios(this);

    connect(loginWindow, &Login::loginExitoso, this, &Manager::mostrarVisualizacionUsuarios);
    connect(loginWindow, &Login::abrirRegistro, this, &Manager::mostrarRegistroUsuario);
    connect(registroWindow, &RegistroUsuario::registroExitoso, this, &Manager::mostrarLogin);
    connect(visualizacionWindow, &VisualizacionUsuarios::cerrarVentana, this, &Manager::mostrarLogin);

    mostrarLogin();
}

void Manager::mostrarLogin() {
    loginWindow->show();
    registroWindow->hide();
    visualizacionWindow->hide();
}

void Manager::mostrarRegistroUsuario() {
    registroWindow->show();
    loginWindow->hide();
    visualizacionWindow->hide();
}

void Manager::mostrarVisualizacionUsuarios() {
    visualizacionWindow->cargarUsuarios();
    visualizacionWindow->show();
    loginWindow->hide();
    registroWindow->hide();
}
