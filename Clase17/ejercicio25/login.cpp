#include "login.h"
#include "manager.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

Login::Login(Manager *parent) : QWidget(parent), manager(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *usuarioLabel = new QLabel("Usuario:");
    layout->addWidget(usuarioLabel);
    usuarioLineEdit = new QLineEdit();
    layout->addWidget(usuarioLineEdit);

    QLabel *contrasenaLabel = new QLabel("Contraseña:");
    layout->addWidget(contrasenaLabel);
    contrasenaLineEdit = new QLineEdit();
    contrasenaLineEdit->setEchoMode(QLineEdit::Password);
    layout->addWidget(contrasenaLineEdit);

    loginButton = new QPushButton("Iniciar Sesión");
    layout->addWidget(loginButton);

    registrarButton = new QPushButton("Registrarse");
    layout->addWidget(registrarButton);

    connect(loginButton, &QPushButton::clicked, this, &Login::onLoginClicked);
    connect(registrarButton, &QPushButton::clicked, this, &Login::abrirRegistro);
}

void Login::onLoginClicked() {
    QString usuario = usuarioLineEdit->text();
    QString contrasena = contrasenaLineEdit->text();

    if (manager->db->validarUsuario(usuario, contrasena)) {
        emit loginExitoso();
    } else {
        QMessageBox::warning(this, "Error de inicio de sesión", "Usuario o contraseña incorrectos.");
    }
}

void Login::abrirRegistro() {
    emit abrirRegistro();
}
