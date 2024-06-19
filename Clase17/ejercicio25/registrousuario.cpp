#include "registrousuario.h"
#include "manager.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

RegistroUsuario::RegistroUsuario(Manager *parent) : QWidget(parent), manager(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *nombreLabel = new QLabel("Nombre:");
    layout->addWidget(nombreLabel);
    nombreLineEdit = new QLineEdit();
    layout->addWidget(nombreLineEdit);

    QLabel *usuarioLabel = new QLabel("Usuario:");
    layout->addWidget(usuarioLabel);
    usuarioLineEdit = new QLineEdit();
    layout->addWidget(usuarioLineEdit);

    QLabel *contrasenaLabel = new QLabel("Contraseña:");
    layout->addWidget(contrasenaLabel);
    contrasenaLineEdit = new QLineEdit();
    contrasenaLineEdit->setEchoMode(QLineEdit::Password);
    layout->addWidget(contrasenaLineEdit);

    registrarButton = new QPushButton("Registrar");
    layout->addWidget(registrarButton);

    connect(registrarButton, &QPushButton::clicked, this, &RegistroUsuario::onRegistrarClicked);
}

void RegistroUsuario::onRegistrarClicked() {
    QString nombre = nombreLineEdit->text();
    QString usuario = usuarioLineEdit->text();
    QString contrasena = contrasenaLineEdit->text();

    if (manager->db->registrarUsuario(nombre, usuario, contrasena)) {
        QMessageBox::information(this, "Registro exitoso", "Usuario registrado correctamente.");
        emit registroExitoso();
    } else {
        QMessageBox::warning(this, "Error de registro", "No se pudo registrar el usuario.");
    }
}
